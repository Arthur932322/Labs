#include <iostream>
#include <vector>
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = { 10, 3, 76, 34, 23, 32 };

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    if (isSorted(arr)) {
        std::cout << "Массив отсортирован корректно." << std::endl;
    }
    else {
        std::cout << "Массив не отсортирован." << std::endl;
    }

    return 0;
}
