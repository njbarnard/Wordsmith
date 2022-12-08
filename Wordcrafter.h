//
// Created by Noah Barnard on 12/6/22.
//

#ifndef WORDSMITH_WORDCRAFTER_H
#define WORDSMITH_WORDCRAFTER_H


class Wordcrafter {

private:

    std::string output, startsWith, endsWith, contains, letters, rhymesWith,
             wordType, homophone, omitLetters, synonym, antonym;

    bool outputIsUsed, startsWithIsUsed, endsWithIsUsed, containsIsUsed, lettersIsUsed, anagramIsUsed, lengthIsUsed,
            syllablesIsUsed, rhymesWithIsUsed, wordTypeIsUsed, palindromeIsUsed, kangarooWordIsUsed, compoundWordIsUsed,
            properNounIsUsed, longListIsUsed, perfectRhymeIsUsed, homophoneIsUsed, omitLettersIsUsed, synonymIsUsed,
            antonymIsUsed;

    int length, syllables;

    void outputAllVariables();

    std::string BoolToString(bool b){
        if (b) return "True";
        else return "False";
    };

    //setters
    void setOutput (const std::string &str, bool b);
    void setStartsWith (const std::string &str, bool b);
    void setEndsWith (const std::string &str, bool b);
    void setContain(const std::string &str, bool b);
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
    void setOmitLetters(const std::string &str, bool b);
    void setSynonym(const std::string &str, bool b);
    void setAntonym(const std::string &str, bool b);



};


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
    outputIsUsed = b;
}

void Wordcrafter::setContain(const std::string &str, bool b) {
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
