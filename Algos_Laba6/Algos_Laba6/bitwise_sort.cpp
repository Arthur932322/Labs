#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "bitwise_sort.h"

std::vector<int> loadArrayFromFile(std::ifstream& file) {
    size_t size;
    if (!(file >> size)) {
        throw std::runtime_error("Ошибка чтения размера массива из файла");
    }
    std::vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        if (!(file >> arr[i])) {
            throw std::runtime_error("Ошибка чтения элементов массива из файла");
        }
    }
    return arr;
}


double bitwiseSortTime(std::vector<int>& arr, int runs) {
    double totalTime = 0.0;
    for (int i = 0; i < runs; ++i) {
        std::vector<int> tempArr = arr;
        auto start = std::chrono::high_resolution_clock::now();
        bitwiseSort(tempArr);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }
    return totalTime / runs;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(0)));

    std::vector<int> sizes = { 10000, 100000, 1000000 };
    std::vector<std::pair<int, int>> ranges = { {-10, 10}, {-1000, 1000}, {-100000, 100000} };
    const int runs = 1;

    const std::string fileName = "data.txt";

   

    std::cout << "\nReading arrays from a file and checking sorting...\n";
    std::ifstream file(fileName);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading");
    }

    try {
        while (file.peek() != EOF) {
            std::vector<int> arr = loadArrayFromFile(file);
            std::cout << "Array size " << arr.size() << " items loaded.\n";

            double averageTime = bitwiseSortTime(arr, runs);
            std::cout << "Average sorting time: " << averageTime << " seconds\n";
        }
    }
    catch (...)
    {

    }



    return 0;
}
