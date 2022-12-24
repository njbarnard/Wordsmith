/**
 * Wordsmith: a program to help you craft words for your poems and songs
 *
 * Created by Noah Barnard on 12/12/2022
 * Rhyming algorithm provided by thierryseegers:
 * https://github.com/thierryseegers/rhymer
 * 194k word list provided by:
 * http://www.gwicks.net/dictionaries.htm
 * 479k word list provided by:
 * https://github.com/dwyl/english-words
 * 25k syllables list provided by:
 * https://github.com/gautesolheim/25000-syllabified-words-list#readme
 * number removing solution sound via Riad Afridi Shibly:
 * https://www.quora.com/How-do-I-remove-numbers-from-a-string-in-C
 */

#ifndef WORDSMITH_WORDCRAFTER_H
#define WORDSMITH_WORDCRAFTER_H

#include <vector>
#include <unordered_set>
#include <iostream>
#include "rhymer.h"
#include "Affix.h"



class Wordcrafter {

public:
    //constructor
    Wordcrafter() {
        InitializeBools();
        shortWordListPath = "../english194k.txt";
        longWordListPath = "../english479k.txt";
        properNounListPath = "../english479k.txt";
    }

    //algorithm functions
    std::vector<std::string> craftWords();
    static std::string Lowercase(std::string word);

    //setters
    void setOutput (const std::string &str, bool b);
    void setStartsWith (const std::string &str, bool b);
    void setEndsWith (const std::string &str, bool b);
    void setContains(const std::string &str, bool b);
    void setLetters(const std::string &str, bool b);
    void setAnagram(bool b);
    void setLength(int l, bool b);
    void setSyllables(int l, bool b);
    void setRhymesWith(const std::string &str, bool b);
    void setWordType(const std::string &str, bool b);
    void setPalindrome(bool b);
    void setKangarooWord(bool b);
    void setCompoundWord(bool b);
    void setProperNoun(bool b);
    void setLongList(bool b);
    void setPerfectRhyme(bool b);
    void setHomophone(const std::string &str, bool b);
    void setOmitLetters(const std::string &str, bool b);
    void setSynonym(const std::string &str, bool b);
    void setAntonym(const std::string &str, bool b);

    //getters
    bool getSyllablesBool() const{return syllablesIsUsed;}
    bool getHomophoneBool() const{return homophoneIsUsed;}
    bool getOmitLettersBool() const{return omitLettersIsUsed;}
    bool getPalindromeBool() const{return palindromeIsUsed;}
    bool getKangarooWordBool() const{return kangarooWordIsUsed;}
    bool getCompoundWordBool() const{return compoundWordIsUsed;}
    bool getProperNounBool() const{return properNounIsUsed;}
    bool getLongListBool() const{return longListIsUsed;}
    bool getPerfectRhymeBool() const{return perfectRhymeIsUsed;}

    //terminal output
    void outputAllVariables();
    static std::string BoolToString(bool b){
        if (b) return "True";
        else return "False";
    };

    static std::string intToString(int num);

private:

    void InitializeBools();

    //algorithm-specific variables
    int previousLongListIsUsed, previousProperNounIsUsed;
    std::vector<std::string> wordList{};
    std::unordered_set<std::string> wordSet{};

    //algorithm functions
    void parseWordList(std::string& filePath);
    void startsWithFilter(std::vector<std::string>& words);
    void endsWithFilter(std::vector<std::string>& words);
    void containsFilter(std::vector<std::string>& words);
    void rhymesWithFilter(std::vector<std::string>& words);
    void lengthFilter(std::vector<std::string>& words);
    void lettersFilter(std::vector<std::string>& words);
    void palindromeFilter(std::vector<std::string>& words);
    void omitLettersFilter(std::vector<std::string>& words);
    void homophoneFilter(std::vector<std::string>& words);
    void syllablesFilter(std::vector<std::string>& words);
    void compoundWordFilter(std::vector<std::string>& words);


    std::string output, startsWith, endsWith, contains, letters, rhymesWith,
             wordType, homophone, omitLetters, synonym, antonym;

    bool outputIsUsed, startsWithIsUsed, endsWithIsUsed, containsIsUsed, lettersIsUsed, anagramIsUsed, lengthIsUsed,
            syllablesIsUsed, rhymesWithIsUsed, wordTypeIsUsed, palindromeIsUsed, kangarooWordIsUsed, compoundWordIsUsed,
            properNounIsUsed, longListIsUsed, perfectRhymeIsUsed, homophoneIsUsed, omitLettersIsUsed, synonymIsUsed,
            antonymIsUsed;

    int length, syllables;

    std::string shortWordListPath, longWordListPath, properNounListPath;

};

void Wordcrafter::InitializeBools(){

    //SET ALL BOOLS TO FALSE
    outputIsUsed = startsWithIsUsed = endsWithIsUsed = containsIsUsed = lettersIsUsed = anagramIsUsed =
    lengthIsUsed = syllablesIsUsed = rhymesWithIsUsed = wordTypeIsUsed = palindromeIsUsed = kangarooWordIsUsed =
    compoundWordIsUsed = properNounIsUsed = longListIsUsed = perfectRhymeIsUsed = homophoneIsUsed =
    omitLettersIsUsed = synonymIsUsed = antonymIsUsed = false;

    length = syllables = 0;

    previousLongListIsUsed = previousProperNounIsUsed = -1;
}

std::vector<std::string> Wordcrafter::craftWords(){
    std::vector<std::string> craftedWords;

    //this block of code avoids parsing the word list every time if the choice hasn't changed
    if (properNounIsUsed){
        if (properNounIsUsed != previousProperNounIsUsed) parseWordList(properNounListPath);
    }
    else if (previousLongListIsUsed != longListIsUsed) {
        if (longListIsUsed) parseWordList(longWordListPath);
        else parseWordList(shortWordListPath);
    }
    craftedWords = wordList;
    previousProperNounIsUsed = properNounIsUsed;
    previousLongListIsUsed = longListIsUsed;

    //parameter functions
    if(startsWithIsUsed) startsWithFilter(craftedWords);
    if(endsWithIsUsed) endsWithFilter(craftedWords);
    if(containsIsUsed) containsFilter(craftedWords);
    if(rhymesWithIsUsed) rhymesWithFilter(craftedWords);
    if (lengthIsUsed) lengthFilter(craftedWords);
    if (lettersIsUsed) lettersFilter(craftedWords);
    if (palindromeIsUsed) palindromeFilter(craftedWords);
    if (omitLettersIsUsed) omitLettersFilter(craftedWords);
    if (homophoneIsUsed) homophoneFilter(craftedWords);
    if (syllablesIsUsed) syllablesFilter(craftedWords);
    if (compoundWordIsUsed) compoundWordFilter(craftedWords);


    /*
    std::cout << "----------------------------------" << std::endl;
    for (auto word : craftedWords)
        std::cout << word << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << craftedWords.size() << " words found!";
    */

    return craftedWords;
}

void Wordcrafter::parseWordList(std::string& filePath){
    std::string word;
    std::ifstream file(filePath);
    wordList.clear();
    wordSet.clear();

    if (!file) {
        //checks to make sure the file can be opened
        std::cout << "File cannot be opened" << std::endl << std::endl;
        return;
    }

    while (!file.eof()) {
        getline(file, word); //gets word
        wordList.push_back(word);
        wordSet.insert(word);
    }
}

void Wordcrafter::startsWithFilter(std::vector<std::string> &words){
    std::vector<std::string> results;

    for (auto word : words){
        if (startsWith.length() <= word.length()){
            bool checker = true;
            for (int i = 0; i < startsWith.length(); i++){
                if (word.at(i) != startsWith.at(i) && startsWith.at(i) != '_'){
                    checker = false;
                }
            }
            if (checker) results.push_back(word);
        }
    }
    words = results;
}

void Wordcrafter::endsWithFilter(std::vector<std::string> &words){
    std::vector<std::string> results;

    for (auto word : words){
        if (endsWith.length() <= word.length()){
            bool checker = true;
            for (int i = 0; i < endsWith.length(); i++){
                if (word.at(word.length() -1 -i) != endsWith.at(endsWith.length() -1 -i)
                        && endsWith.at(endsWith.length() -1 -i) != '_'){
                    checker = false;
                }
            }
            if (checker) results.push_back(word);
        }
    }
    words = results;
}

void Wordcrafter::containsFilter(std::vector<std::string> &words) {
    std::vector<std::string> results;

    for (auto word : words){
        auto n = word.find(contains);
        if (n != std::string::npos)
        {
            results.push_back(word);
        }
    }
    words = results;
}

void Wordcrafter::rhymesWithFilter(std::vector<std::string> &words) {
    std::vector<std::string> results;

    std::stringstream ss(rhymesWith);
    std::string singleRhyme;
    std::vector<std::string> rhymeWords;

    while (getline(ss, singleRhyme, ' ')){
        rhymeWords.push_back(singleRhyme);
    }

    rhymer r(std::ifstream("../cmudict-0.7b"), std::ifstream("../cmudict-0.7b.phones"));

    std::vector<std::string> rhymes;
    std::vector<std::string> rhymesTemp;

    for (auto word : rhymeWords) {
        if (perfectRhymeIsUsed) rhymesTemp = r.rhymes(word, true);
        else rhymesTemp = r.rhymes(word, false);

        rhymes.insert(rhymes.end(), rhymesTemp.begin(), rhymesTemp.end());
    }

    sort(rhymes.begin(), rhymes.end());
    rhymes.erase(unique( rhymes.begin(), rhymes.end()), rhymes.end());

    for (auto & rhyme : rhymes){
        rhyme = Lowercase(rhyme);
    }

    sort(words.begin(), words.end());
    sort(rhymes.begin(), rhymes.end());

    set_intersection(words.begin(), words.end(), rhymes.begin(),
                     rhymes.end(), back_inserter(results));
    words = results;
}

void Wordcrafter::lengthFilter(std::vector<std::string>& words){
    std::vector<std::string> results;
    for (auto word : words){
            if (word.length() == length) results.push_back(word);
    }
    words = results;
}

void Wordcrafter::lettersFilter(std::vector<std::string>& words){
    std::vector<std::string> results;

    std::vector<int> alphabet(26, 0);
    std::string allLetters = Lowercase(letters);
    for (char x : allLetters){
        if (isalpha(x)) alphabet.at(x - 97)++;
    }

    for (auto word : words){
        std::vector<int> alphabetValues = alphabet;
        bool checker = true;
        for (char x : word){
            if (isalpha(x)) {if (alphabetValues.at(x - 97)-- < 1) checker = false;}
        }
        if (!anagramIsUsed){
            if (checker) results.push_back(word);
        } else {
            if (checker){
                bool anagramChecker = true;
                for (auto val : alphabetValues){
                    if (val != 0) anagramChecker = false;
                }
                if (anagramChecker) results.push_back(word);
            }
        }
    }
    words = results;
}

void Wordcrafter::palindromeFilter(std::vector<std::string>& words){
    std::vector<std::string> results;

    for (auto word : words){
        //the word must be 4 letters long (filters out junk words)
        if (word.length() > 3) {
            std::string reverse = word;
            std::reverse(reverse.begin(), reverse.end());

            if (word == reverse) {
                results.push_back(word);
            }
        }
    }

    words = results;

    //old, manual solution
    /*
    for (auto word : words) {
        if (word.length() > 3) {
            int j = word.length() - 1;
            int i = 0;
            bool checker = true;
            while (i < j) {
                if (word.at(i) != word.at(j - i)) {
                    checker = false;
                    break;
                } else i++;
            }
            if (checker) results.push_back(word);
        }
    }
    words = results;
    */
}

void Wordcrafter::omitLettersFilter(std::vector<std::string>& words){
    std::vector<std::string> results;

    std::vector<int> alphabet(26, 0);
    std::string allLetters = Lowercase(omitLetters);
    for (char x : allLetters){
        if (isalpha(x)) alphabet.at(x - 97)++;
    }

    for (auto word : words) {
        bool checker = true;
        for (char x: word) {
            if (isalpha(x)) { if (alphabet.at(x - 97) > 0) checker = false; }
        }
        if (checker) results.push_back(word);
    }

    words = results;
}

void Wordcrafter::homophoneFilter(std::vector<std::string>& words){
    std::vector<std::string> results;

    rhymer r(std::ifstream("../cmudict-0.7b"), std::ifstream("../cmudict-0.7b.phones"));
    auto const homophonePronunciation = r.pronunciation(homophone);

    /*
     * r.pronunciation crashes if you give it a word not in its dictionary, but
     * r.rhymes returns an empty vector if you give it a word not in its dictionary.
     * Thus, r.rhymes is used to check for a valid word in the pronunciation dictionary
     * [It slows down the runtime substantially but stops it from crashing]
     */
    for (auto word : words) {
        auto const rhymes = r.rhymes(word);
        if (!rhymes.empty()){
            auto const wordPronunciation = r.pronunciation(word);
            if (homophonePronunciation == wordPronunciation) results.push_back(word);
        }
    }

    words = results;
}

void Wordcrafter::syllablesFilter(std::vector<std::string>& words){
    std::vector<std::string> results;
    std::unordered_set<std::string> syllableSet{};

    std::string filePath;
    if (syllables == 1)
        filePath = "../syllables25k/" + intToString(syllables) + "-syllable-sorted-by-prevalence.txt";
    else
        filePath = "../syllables25k/" + intToString(syllables) + "-syllables-sorted-by-prevalence.txt";

    std::string word;
    std::ifstream file(filePath);

    if (!file) {
        //checks to make sure the file can be opened
        std::cout << "Syllables file cannot be opened" << std::endl << std::endl;
        return;
    }

    while (!file.eof()) {
        getline(file, word); //gets word
        syllableSet.insert(word);
    }

    for (auto word : words){
        if (syllableSet.find(word) != syllableSet.end()) results.push_back(word);
    }
    words = results;
}

void Wordcrafter::compoundWordFilter(std::vector<std::string>& words){
    std::vector<std::string> results;

    //filters out words which are not compound words
    //based off of code provided by Ashutosh:
    //https://www.careercup.com/question?id=6224460008914944

    Affix affix;

    for (auto word : words) {
        int n = word.length();
        if (n >= 6) {
        //ensure that each of the words forming the compound word are at least 3 letters in length
            for (int i = 3; i < n - 2; i++) {
                //loop over the word, breaking it into two halves each time
                std::string x = word.substr(0, i);
                std::string y = word.substr(i, n - 1);
                if ((wordSet.find(x) != wordSet.end()) && (wordSet.find(y) != wordSet.end())
                        && !affix.isPrefix(x) && !affix.isSuffix(y)) {
                    //if the two substrings are valid words and are not prefixes or suffixes,
                    //the word is a compound word and can be added to the results
                    results.push_back(word);
                    break;
                }
            }
        }
    }
    words = results;
}

std::string Wordcrafter::Lowercase(std::string word){
    //number removing solution found via Riad Afridi Shibly:
    //https://www.quora.com/How-do-I-remove-numbers-from-a-string-in-C

    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    word.erase(std::remove_if(std::begin(word), std::end(word), [](auto ch)
    {return std::isdigit(ch);}),word.end());
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    return word;
}

std::string Wordcrafter::intToString(int num){
    switch(num) {
        case 1:
            return  "one";
            break;
        case 2:
            return "two";
            break;
        case 3:
            return "three";
            break;
        case 4:
            return "four";
            break;
        case 5:
            return "five";
            break;
        case 6:
            return "six";
            break;
        case 7:
            return "seven";
            break;
        case 8:
            return "eight";
            break;
        default:
            return"NaN";
            break;
    }
}


void Wordcrafter::outputAllVariables() {

    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Output: " << output << " [" << BoolToString(outputIsUsed) << "]" << std::endl;
    std::cout << "Starts with: " << startsWith << " [" << BoolToString(startsWithIsUsed) << "]" << std::endl;
    std::cout << "Ends with: " << endsWith << " [" << BoolToString(endsWithIsUsed) << "]" << std::endl;
    std::cout << "Contains: " << contains << " [" << BoolToString(containsIsUsed) << "]" << std::endl;
    std::cout << "Letters: " << letters << " [" << BoolToString(lettersIsUsed) << "]" << std::endl;
    std::cout << "Anagram" << " [" << BoolToString(anagramIsUsed) << "]" << std::endl;
    std::cout << "Length: " << length << " [" << BoolToString(lengthIsUsed) << "]" << std::endl;
    std::cout << "Syllables: " << syllables << " [" << BoolToString(syllablesIsUsed) << "]" << std::endl;
    std::cout << "Palindrome" << " [" << BoolToString(palindromeIsUsed) << "]" << std::endl;
    std::cout << "Kangaroo Word" << " [" << BoolToString(kangarooWordIsUsed) << "]" << std::endl;
    std::cout << "Compound Word" << " [" << BoolToString(compoundWordIsUsed) << "]" << std::endl;
    std::cout << "Proper Noun" << " [" << BoolToString(properNounIsUsed) << "]" << std::endl;
    std::cout << "Long List" << " [" << BoolToString(longListIsUsed) << "]" << std::endl;
    std::cout << "Perfect Rhyme" << " [" << BoolToString(perfectRhymeIsUsed) << "]" << std::endl;
    std::cout << "Rhymes with: " << rhymesWith << " [" << BoolToString(rhymesWithIsUsed) << "]" << std::endl;
    std::cout << "Homophone: " << homophone << " [" << BoolToString(homophoneIsUsed) << "]" << std::endl;
    std::cout << "Omit Letters: " << omitLetters << " [" << BoolToString(omitLettersIsUsed) << "]" << std::endl;
    std::cout << "Word Type: " << wordType << " [" << BoolToString(wordTypeIsUsed) << "]" << std::endl;
    std::cout << "Synonym: " << synonym << " [" << BoolToString(synonymIsUsed) << "]" << std::endl;
    std::cout << "Antonym: " << antonym << " [" << BoolToString(antonymIsUsed) << "]" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
}


void Wordcrafter::setOutput(const std::string &str, bool b) {
    output = str;
    outputIsUsed = b;
}
void Wordcrafter::setStartsWith(const std::string &str, bool b) {
    startsWith = str;
    startsWithIsUsed = b;
}
void Wordcrafter::setEndsWith(const std::string &str, bool b) {
    endsWith = str;
    endsWithIsUsed = b;
}

void Wordcrafter::setContains(const std::string &str, bool b) {
    contains = str;
    containsIsUsed = b;
}
void Wordcrafter::setLetters(const std::string &str, bool b) {
    letters = str;
    lettersIsUsed = b;
}
void Wordcrafter::setAnagram(bool b) {
    anagramIsUsed = b;
}
void Wordcrafter::setLength(int l, bool b) {
    length = l;
    lengthIsUsed = b;
}
void Wordcrafter::setSyllables(int l, bool b) {
    syllables = l;
    syllablesIsUsed = b;
}
void Wordcrafter::setRhymesWith(const std::string &str, bool b) {
    rhymesWith = str;
    rhymesWithIsUsed = b;
}
void Wordcrafter::setWordType(const std::string &str, bool b) {
    wordType = str;
    wordTypeIsUsed = b;
}
void Wordcrafter::setPalindrome(bool b) {
    palindromeIsUsed = b;
}
void Wordcrafter::setKangarooWord(bool b) {
    kangarooWordIsUsed = b;
}

void Wordcrafter::setCompoundWord(bool b) {
    compoundWordIsUsed = b;
}
void Wordcrafter::setProperNoun(bool b) {
    properNounIsUsed = b;
}
void Wordcrafter::setLongList(bool b) {
    longListIsUsed = b;
}
void Wordcrafter::setPerfectRhyme(bool b) {
    perfectRhymeIsUsed = b;
}
void Wordcrafter::setHomophone(const std::string &str, bool b){
    homophone = str;
    homophoneIsUsed = b;
}
void Wordcrafter::setOmitLetters(const std::string &str, bool b) {
    omitLetters = str;
    omitLettersIsUsed = b;
}
void Wordcrafter::setSynonym(const std::string &str, bool b) {
    synonym = str;
    synonymIsUsed = b;
}
void Wordcrafter::setAntonym(const std::string &str, bool b) {
    antonym = str;
    antonymIsUsed = b;
}


#endif //WORDSMITH_WORDCRAFTER_H
