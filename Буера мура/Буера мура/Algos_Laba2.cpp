#include <iostream>
#include "boyer_more.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::string text = "������� ���������";
    std::string pattern = "�����";

    int firstIndex = boyerMooreFirst(text, pattern);
    if (firstIndex != -1) {
        std::cout << "������ ��������� ������� �� �������: " << firstIndex << std::endl;
    }
    else {
        std::cout << "��������� �� �������." << std::endl;
    }

    std::vector<int> allIndexes = boyerMooreAll(text, pattern);
    if (!allIndexes.empty()) {
        std::cout << "��� ��������� ��������� ������� �� ��������: ";
        for (int index : allIndexes) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "��������� �� �������." << std::endl;
    }

    return 0;
}