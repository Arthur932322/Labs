#pragma once
#include <string>
#include <vector>

int boyerMooreFirst(const std::string& text, const std::string& pattern);

std::vector<int> boyerMooreAll(const std::string& text, const std::string& pattern);
