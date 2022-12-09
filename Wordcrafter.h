//
// Created by Noah Barnard on 12/6/22.
//

#ifndef WORDSMITH_WORDCRAFTER_H
#define WORDSMITH_WORDCRAFTER_H


class Wordcrafter {

public:
    Wordcrafter() {
        InitializeBools();
    }

    std::string BoolToString(bool b){
        if (b) return "True";
        else return "False";
    };

    void outputAllVariables();

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
    bool getSyllablesBool(){return syllablesIsUsed;}
    bool getHomophoneBool(){return homophoneIsUsed;}
    bool getOmitLettersBool(){return omitLettersIsUsed;}
    bool getPalindromeBool(){return palindromeIsUsed;}
    bool getKangarooWordBool(){return kangarooWordIsUsed;}
    bool getCompoundWordBool(){return compoundWordIsUsed;}
    bool getProperNounBool(){return properNounIsUsed;}
    bool getLongListBool(){return longListIsUsed;}
    bool getPerfectRhymeBool(){return perfectRhymeIsUsed;}

private:

    void InitializeBools();

    std::string output, startsWith, endsWith, contains, letters, rhymesWith,
             wordType, homophone, omitLetters, synonym, antonym;

    bool outputIsUsed, startsWithIsUsed, endsWithIsUsed, containsIsUsed, lettersIsUsed, anagramIsUsed, lengthIsUsed,
            syllablesIsUsed, rhymesWithIsUsed, wordTypeIsUsed, palindromeIsUsed, kangarooWordIsUsed, compoundWordIsUsed,
            properNounIsUsed, longListIsUsed, perfectRhymeIsUsed, homophoneIsUsed, omitLettersIsUsed, synonymIsUsed,
            antonymIsUsed;

    int length, syllables;

};

void Wordcrafter::InitializeBools(){

    //SET ALL BOOLS TO FALSE
    outputIsUsed = startsWithIsUsed = endsWithIsUsed = containsIsUsed = lettersIsUsed = anagramIsUsed =
    lengthIsUsed = syllablesIsUsed = rhymesWithIsUsed = wordTypeIsUsed = palindromeIsUsed = kangarooWordIsUsed =
    compoundWordIsUsed = properNounIsUsed = longListIsUsed = perfectRhymeIsUsed = homophoneIsUsed =
    omitLettersIsUsed = synonymIsUsed = antonymIsUsed = false;

    length = syllables = 0;
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
    std::cout << "Rhymes with: " << rhymesWith << " [" << BoolToString(rhymesWithIsUsed) << "]" << std::endl;
    std::cout << "Word Type: " << wordType << " [" << BoolToString(wordTypeIsUsed) << "]" << std::endl;
    std::cout << "Palindrome" << " [" << BoolToString(palindromeIsUsed) << "]" << std::endl;
    std::cout << "Kangaroo Word" << " [" << BoolToString(kangarooWordIsUsed) << "]" << std::endl;
    std::cout << "Compound Word" << " [" << BoolToString(compoundWordIsUsed) << "]" << std::endl;
    std::cout << "Proper Noun" << " [" << BoolToString(properNounIsUsed) << "]" << std::endl;
    std::cout << "Long List" << " [" << BoolToString(longListIsUsed) << "]" << std::endl;
    std::cout << "Perfect Rhyme" << " [" << BoolToString(perfectRhymeIsUsed) << "]" << std::endl;
    std::cout << "Omit Letters: " << omitLetters << " [" << BoolToString(omitLettersIsUsed) << "]" << std::endl;
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
