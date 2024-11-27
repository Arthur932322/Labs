#include <iostream>
#include <vector>
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = { 10, 3, 76, 34, 23, 32 };

    std::cout << "�������� ������: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "��������������� ������: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    if (isSorted(arr)) {
        std::cout << "������ ������������ ���������." << std::endl;
    }
    else {
        std::cout << "������ �� ������������." << std::endl;
    }

    return 0;
}
