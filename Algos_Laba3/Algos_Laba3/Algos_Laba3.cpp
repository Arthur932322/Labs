#include <iostream>
#include <vector>
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = { 12, 34, 54, 2, 3, 1, 7 };

    std::cout << "�������� ������: ";
    printArray(arr);

    shellSort(arr);

    std::cout << "��������������� ������: ";
    printArray(arr);

    if (isSorted(arr)) {
        std::cout << "������ ������������ ���������." << std::endl;
    }
    else {
        std::cout << "������ ������������ �����������." << std::endl;
    }

    return 0;
}