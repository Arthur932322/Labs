#include "bitwise_sort.h"

void bitwiseSort(std::vector<int>& arr) {
    const int BITS = 32; 
    std::vector<int> temp(arr.size());

    for (int bit = 0; bit < BITS; ++bit) {
        int mask = 1 << bit;

        int zeroCount = 0;
        for (int num : arr) {
            if ((num & mask) == 0) {
                zeroCount++;
            }
        }

        int zeroIndex = 0;
        int oneIndex = zeroCount;

        for (int num : arr) {
            if ((num & mask) == 0) {
                temp[zeroIndex++] = num;
            }
            else {
                temp[oneIndex++] = num;
            }
        }

        arr = temp;
    }
}

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}
