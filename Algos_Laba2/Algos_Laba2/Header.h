#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <unordered_map>

class BoyerMoore {
public:
    BoyerMoore(const std::string& pattern);
    int findFirstOccurrence(const std::string& text) const;

private:
    void preprocessBadCharacterRule();
    std::string pattern_;
    std::unordered_map<char, int> badCharacterTable_;
};

#endif 