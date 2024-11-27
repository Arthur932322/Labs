#pragma once
#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce(); 

public:
    Fraction();
    Fraction(int numerator, int denominator);

    void setNumerator(int numerator);
    void setDenominator(int denominator);
    int getNumerator() const;
    int getDenominator() const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);

    // Уникальные методы
    double toDecimal() const; // Преобразование дроби в десятичное число
    static Fraction fromDecimal(double value, int precision); // Преобразование из десятичного числа
};

