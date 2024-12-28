#include <iostream>
#include "boyer_more.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::string text = "фыджфды бадыфбэфы";
    std::string pattern = "бадыф";

    int firstIndex = boyerMooreFirst(text, pattern);
    if (firstIndex != -1) {
        std::cout << "Первое вхождение найдено на позиции: " << firstIndex << std::endl;
    }
    else {
        std::cout << "Подстрока не найдена." << std::endl;
    }

    std::vector<int> allIndexes = boyerMooreAll(text, pattern);
    if (!allIndexes.empty()) {
        std::cout << "Все вхождения подстроки найдены на позициях: ";
        for (int index : allIndexes) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Подстрока не найдена." << std::endl;
    }

    return 0;
}