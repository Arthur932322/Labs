#pragma once

#include <vector>
#include <string>

std::vector<int> generateRandomArray(int size, int minValue, int maxValue);
void saveArrayToFile(const std::vector<int>& arr, const std::string& fileName);
std::vector<int> loadArrayFromFile(std::ifstream& file);
double measureSortTime(std::vector<int>& arr, int runs);