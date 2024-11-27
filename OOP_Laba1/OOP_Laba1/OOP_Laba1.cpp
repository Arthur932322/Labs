#include "Header.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        Fraction f1(3, 4);       // 3/4
        Fraction f2(2, 5);       // 2/5

        std::cout << "f1 + f2 = " << (f1 + f2) << '\n';
        std::cout << "f1 - f2 = " << (f1 - f2) << '\n';
        std::cout << "f1 * f2 = " << (f1 * f2) << '\n';
        std::cout << "f1 / f2 = " << (f1 / f2) << '\n';

        std::cout << "f1 == f2: " << (f1 == f2) << '\n';
        std::cout << "f1 > f2: " << (f1 > f2) << '\n';

        Fraction f3;
        std::cout << "Введите дробь (в формате числитель/знаменатель): ";
        std::cin >> f3;
        std::cout << "Вы ввели дробь: " << f3 << '\n';

        // Уникальные методы
        double decimal = f3.toDecimal();
        std::cout << "Десятичное значение дроби: " << decimal << '\n';

        Fraction f4 = Fraction::fromDecimal(0.75, 4);
        std::cout << "Дробь из десятичного числа 0.75: " << f4 << '\n';

    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << '\n';
    }

    return 0;
}
