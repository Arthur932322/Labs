#include <iostream>
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::string text = "Примите лабу пожалуйста";
    std::string pattern = "лабу";

    BoyerMoore bm(pattern);
    int index = bm.findFirstOccurrence(text);

    if (index != -1) {
        std::cout << "Индекс вхожденя: " << index << std::endl;
    }
    else {
        std::cout << "Не найдено." << std::endl;
    }

    return 0;
}