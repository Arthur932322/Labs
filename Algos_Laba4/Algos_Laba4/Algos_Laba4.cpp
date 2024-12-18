#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "Header.h"
#include <iostream>
#include <string>


int main() {
    setlocale(LC_ALL, "Russian");

    srand(static_cast<unsigned>(time(0)));

    std::vector<int> sizes = { 10000, 100000, 1000000 };
    std::vector<std::pair<int, int>> ranges = { {-10, 10}, {-1000, 1000}, {-100000, 100000} };
    const int runs = 3;

    const std::string fileName = "data.txt";

    std::cout << "��������� � ���������� �������� � ����...\n";
    for (int size : sizes) {
        for (const auto& range : ranges) {
            int minValue = range.first;
            int maxValue = range.second;

            std::vector<int> arr = generateRandomArray(size, minValue, maxValue);
            saveArrayToFile(arr, fileName);

            std::cout << "������� ������: ������ = " << size
                << ", �������� = [" << minValue << ", " << maxValue << "]\n";
        }
    }

    std::cout << "\n������ �������� �� ����� � ������������ ����������...\n";
    std::ifstream file(fileName);
    if (!file) {
        throw std::runtime_error("�� ������� ������� ���� ��� ������");
    }

    try {
        while (file.peek() != EOF) {
            std::vector<int> arr = loadArrayFromFile(file);
            std::cout << "������ �������� " << arr.size() << " ��������� ��������.\n";

            double averageTime = measureSortTime(arr, runs);
            std::cout << "������� ����� ����������: " << averageTime << " ������\n";
        }
    }
    catch (...)
    {

    }



    return 0;
}
