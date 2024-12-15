#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "bitwise_sort.h"

std::vector<int> generateArray(int size, int minValue, int maxValue) {
    std::vector<int> arr(size);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(minValue, maxValue);
    for (int& num : arr) {
        num = dist(rng);
    }
    return arr;
}

double measureSortTime(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    bitwiseSort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bitwiseSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    if (isSorted(arr)) {
        std::cout << "Массив отсортирован правильно." << std::endl;
    }
    else {
        std::cout << "Ошибка: массив отсортирован неправильно." << std::endl;
    }

    std::vector<int> sizes = { 10000, 100000, 1000000 };
    std::vector<std::pair<int, int>> ranges = { {-10, 10}, {-1000, 1000}, {-100000, 100000} };

    for (int size : sizes) {
        for (const auto& range : ranges) {
            int minValue = range.first;
            int maxValue = range.second;

            std::vector<int> array = generateArray(size, minValue, maxValue);

            if (minValue < 0) {
                int offset = -minValue;
                for (int& num : array) {
                    num += offset;
                }
            }

            double totalTime = 0.0;
            const int iterations = 3;
            for (int i = 0; i < iterations; ++i) {
                std::vector<int> tempArray = array;
                totalTime += measureSortTime(tempArray);
            }

            std::cout << "Размер: " << size
                << ", Диапазон: [" << range.first << ", " << range.second << "]"
                << ", Среднее время: " << (totalTime / iterations) << " сек."
                << std::endl;
        }
    }

    return 0;
}
