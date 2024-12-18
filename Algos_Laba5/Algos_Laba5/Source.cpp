#include "Header.h"
#include <iostream>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low]; 
    int left = low + 1;   
    int right = high;     

    while (true) {
        while (left <= right && arr[left] <= pivot) {
            ++left;
        }

        while (left <= right && arr[right] > pivot) {
            --right;
        }

        if (left > right) {
            break;
        }

        std::swap(arr[left], arr[right]);
    }

    std::swap(arr[low], arr[right]);
    return right;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) {
            return false; 
        }
    }
    return true;
}

