#include "boyer_more.h"

void buildBadCharacterTable(const std::string& pattern, int badCharTable[]) {
    int m = pattern.size();

    for (int i = 0; i < 256; ++i) {
        badCharTable[i] = m;
    }

    for (int i = 0; i < m - 1; ++i) {
        badCharTable[static_cast<unsigned char>(pattern[i])] = m - 1 - i;
    }
}

int boyerMooreFirst(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0 || n < m) return -1;

    int badCharTable[256];
    buildBadCharacterTable(pattern, badCharTable);

    int shift = 0;

    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            return shift;
        }

        shift += badCharTable[static_cast<unsigned char>(text[shift + j])];
    }

    return -1; 
}

std::vector<int> boyerMooreAll(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> positions;

    if (m == 0 || n < m) return positions;

    int badCharTable[256];
    buildBadCharacterTable(pattern, badCharTable);

    int shift = 0;

    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            positions.push_back(shift);
            shift += (shift + m < n) ? badCharTable[static_cast<unsigned char>(text[shift + m])] : 1;
        }
        else {
            shift += badCharTable[static_cast<unsigned char>(text[shift + j])];
        }
    }

    return positions;
}