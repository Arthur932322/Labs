#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>
#include "Header.h"

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

std::vector<int> generateRandomArray(int size, int minValue, int maxValue) {
    std::vector<int> arr(size);
    for (int& num : arr) {
        num = minValue + rand() % (maxValue - minValue + 1);
    }
    return arr;
}

void saveArrayToFile(const std::vector<int>& arr, const std::string& fileName) {
    std::ofstream file(fileName, std::ios::app);
    if (!file) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }
    file << arr.size() << "\n";  
    for (const int& num : arr) {
        file << num << " ";      
    }
    file << "\n";               
    file.close();
}

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