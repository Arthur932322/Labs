#include "Header.h"
#include <iostream>
#include <vector>

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = { 34, 7, 23, 32, 5, 62 };

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    if (isSorted(arr)) {
        std::cout << "Массив отсортирован корректно." << std::endl;
    }
    else {
        std::cout << "Ошибка: массив не отсортирован." << std::endl;
    }

    return 0;
}
