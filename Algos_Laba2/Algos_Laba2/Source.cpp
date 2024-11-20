#include "Header.h"
#include <algorithm>

BoyerMoore::BoyerMoore(const std::string& pattern) : pattern_(pattern) {
    preprocessBadCharacterRule();
}

void BoyerMoore::preprocessBadCharacterRule() {
    int patternLength = pattern_.size();
    for (int i = 0; i < patternLength; ++i) {
        badCharacterTable_[pattern_[i]] = i;
    }
}

int BoyerMoore::findFirstOccurrence(const std::string& text) const {
    int textLength = text.size();
    int patternLength = pattern_.size();

    if (patternLength == 0  (textLength == 0  (patternLength > textLength))) {
        return -1; 
    }

    int shift = 0;
    while (shift <= (textLength - patternLength)) {
        int j = patternLength - 1;

        while (j >= 0 && pattern_[j] == text[shift + j]) {
            --j;
        }

        if (j < 0) {
            return shift; 
        }

        char badChar = text[shift + j];
        int badCharShift = badCharacterTable_.count(badChar) > 0 ? badCharacterTable_.at(badChar) : -1;
        shift += std::max(1, j - badCharShift);
    }

    return -1; 
}