//
// Created by Noah Barnard on 12/6/22.
//

#include "Wordcrafter.h"

void Wordcrafter::outputAllVariables() {

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
}

