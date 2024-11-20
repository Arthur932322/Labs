#include <iostream>
#include <vector>
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = { 12, 34, 54, 2, 3, 1, 7 };

    std::cout << "Исходный массив: ";
    printArray(arr);

    shellSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    if (isSorted(arr)) {
        std::cout << "Массив отсортирован корректно." << std::endl;
    }
    else {
        std::cout << "Массив отсортирован некорректно." << std::endl;
    }

    return 0;
}