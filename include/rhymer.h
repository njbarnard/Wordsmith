#ifndef UNTITLED14_RYHMER_H
#define UNTITLED14_RYHMER_H

/*
	(C) Copyright Thierry Seegers 2016. Distributed under the following license:

	Boost Software License - Version 1.0 - August 17th, 2003

	Permission is hereby granted, free of charge, to any person or organization
	obtaining a copy of the software and accompanying documentation covered by
	this license (the "Software") to use, reproduce, display, distribute,
	execute, and transmit the Software, and to prepare derivative works of the
	Software, and to permit third-parties to whom the Software is furnished to
	do so, all subject to the following:

	The copyright notices in the Software and this entire statement, including
	the above license grant, this restriction and the following disclaimer,
	must be included in all copies of the Software, in whole or in part, and
	all derivative works of the Software, unless such copies or derivative
	works are solely in the form of machine-executable object code generated by
	a source language processor.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
	SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
	FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
	ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
	DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace std
{
    istream& operator>>(istream&, array<char, 3>&);

    ostream& operator<<(ostream&, array<char, 3> const&);
}

class rhymer
{
public:
    using phoneme = std::array<char, 3>;
    using phonemes = std::vector<phoneme>;

    rhymer(std::ifstream&& phoneme_dictionary, std::ifstream&& phonemes_description)
    {
        // Save which phonemes represent vowels.
        phoneme p;
        std::string description;

        while(phonemes_description)
        {
            phonemes_description >> p;
            phonemes_description >> description;

            if(description == "vowel")
            {
                vowels_.push_back(p);
            }
        }

        // Map words in reverse order from their last phoneme to their last vowel phoneme.
        std::string line, word;
        std::stringstream ss;
        phonemes pronunciation;

        while(getline(phoneme_dictionary, line))
        {
            ss.clear();
            ss.str(line);

            if(line.substr(0, 3) != ";;;")
            {
                ss >> word;
                pronunciation.assign(std::istream_iterator<phoneme>(ss), std::istream_iterator<phoneme>());

                dictionary_[word] = pronunciation;

                // Get a reverse iterator one past last vowel sound.
                auto const v = std::next(std::find_first_of(pronunciation.crbegin(), pronunciation.crend(), vowels_.cbegin(), vowels_.cend(), [](phoneme const& a, phoneme const& b)
                {
                    return a[0] == b[0] && a[1] == b[1];
                }));

                // Navigate base trie from last phoneme to v and copy word in the target.
                lookup_.insert(pronunciation.crbegin(), v)->words_.push_back(word);
            }
        }
    }

    // Returns words that rhyme with given word, matching stress or not.
    std::vector<std::string> rhymes(std::string word, bool const match_stress = true) const
    {
        std::vector<std::string> matches;

        transform(word.begin(), word.end(), word.begin(), ::toupper);
        auto const w = dictionary_.find(word);
        if(w != dictionary_.end())
        {
            phonemes const pronunciation = w->second;

            // Get a reverse iterator to the last vowel sound.
            auto const v = std::find_first_of(pronunciation.crbegin(), pronunciation.crend(), vowels_.cbegin(), vowels_.cend(), [](phoneme const& a, phoneme const& b)
            {
                return a[0] == b[0] && a[1] == b[1];
            });

            // Navigate base trie from the last phoneme up to that vowel.
            trie const *const t = lookup_.find(pronunciation.crbegin(), v);

            // For each stress marker we need to match, find that vowel sound in t and copy its words.
            auto const stresses = match_stress ? std::vector<char>{(*v)[2]} : std::vector<char>{'0', '1', '2'};
            for(char const stress : stresses)
            {
                auto const s = t->children_.find({{(*v)[0], (*v)[1], stress}});
                if(s != t->children_.end())
                {
                    auto const i = matches.insert(matches.end(), s->second.words_.begin(), s->second.words_.end());
                    std::inplace_merge(matches.begin(), i, matches.end());
                }
            }

            // Remove the given word from the matches.
            matches.erase(std::lower_bound(matches.begin(), matches.end(), word));
        }

        return matches;
    }

    phonemes pronunciation(std::string word) const
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        return dictionary_.at(word);
    }

    // Returns list of alternate pronunciations of a given word.
    std::vector<std::string> alternates(std::string word) const
    {
        std::vector<std::string> alternates;

        transform(word.begin(), word.end(), word.begin(), ::toupper);
        int n = 1;
        std::string alternate = word + "(" + std::to_string(n) + ")";

        while(dictionary_.find(alternate) != dictionary_.end())
        {
            alternates.push_back(alternate);

            alternate = word + "(" + std::to_string(++n) + ")";
        }

        return alternates;
    }

private:
    struct trie
    {
    public:
        trie* insert(phoneme const& p)
        {
            return &children_[p];
        }

        template<typename I>
        trie* insert(I begin, I const end)
        {
            trie *t = this;

            for(; begin != end; ++begin)
            {
                t = t->insert(*begin);
            }

            return t;
        }

        template<typename I>
        trie const* find(I begin, I const end) const
        {
            trie const* t = this;

            for(; begin != end; ++begin)
            {
                t = &(t->children_.find(*begin)->second);
            }

            return t;
        }

        std::map<const phoneme, trie> children_;
        std::vector<const std::string> words_;
    } lookup_;

    phonemes vowels_;
    std::map<const std::string, phonemes> dictionary_;
};


namespace std
{
    istream& operator>>(istream& i, rhymer::phoneme& p)
    {
        i >> p[0];

        if(isalnum(i.peek()))
        {
            i >> p[1];

            if(isalnum(i.peek()))
            {
                i >> p[2];
            }
            else
            {
                p[2] = '\0';
            }
        }
        else
        {
            p[1] = p[2] = '\0';
        }

        return i;
    }

    ostream& operator<<(ostream& o, rhymer::phoneme const& p)
    {
        return o << p[0] << p[1] << p[2];
    }
}

#endif //UNTITLED14_RYHMER_H
