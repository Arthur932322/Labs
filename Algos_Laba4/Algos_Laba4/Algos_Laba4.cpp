#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Header.h"

std::vector<int> generateRandomArray(int size, int minValue, int maxValue) {
    std::vector<int> arr(size);
    for (int& num : arr) {
        num = minValue + rand() % (maxValue - minValue + 1);
    }
    return arr;
}

double measureSortTime(std::vector<int>& arr, int runs) {
    double totalTime = 0.0;
    for (int i = 0; i < runs; ++i) {
        std::vector<int> tempArr = arr;
        auto start = std::chrono::high_resolution_clock::now();
        heapSort(tempArr);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }
    return totalTime / runs;
}

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

    srand(static_cast<unsigned>(time(0)));

    std::vector<int> sizes = { 10000, 100000, 1000000 };
    std::vector<std::pair<int, int>> ranges = { {-10, 10}, {-1000, 1000}, {-100000, 100000} };
    const int runs = 3; 

    for (int size : sizes) {
        for (const auto& range : ranges) {
            int minValue = range.first;
            int maxValue = range.second;

            std::cout << "Тестирование массива размером " << size
                << " с диапазоном значений [" << minValue << ", " << maxValue << "]\n";

            std::vector<int> arr = generateRandomArray(size, minValue, maxValue);

            double averageTime = measureSortTime(arr, runs);
            std::cout << "Среднее время сортировки: " << averageTime << " секунд\n";
        }
    }

  
    return 0;
}
