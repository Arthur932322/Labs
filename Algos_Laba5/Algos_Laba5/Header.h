#pragma once
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high); 
int partition(std::vector<int>& arr, int low, int high); 
bool isSorted(const std::vector<int>& arr);