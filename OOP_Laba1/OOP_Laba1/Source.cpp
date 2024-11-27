#include "Header.h"
#include <cmath>   


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return std::abs(a); 
}

void Fraction::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    reduce();
}

void Fraction::setNumerator(int numerator) {
    this->numerator = numerator;
    reduce();
}

void Fraction::setDenominator(int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    this->denominator = denominator;
    reduce();
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Fraction(num, den);
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.numerator << '/' << fraction.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char separator;
    in >> fraction.numerator >> separator >> fraction.denominator;
    if (fraction.denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    fraction.reduce();
    return in;
}

// ”никальные методы
double Fraction::toDecimal() const {
    return static_cast<double>(numerator) / denominator;
}

Fraction Fraction::fromDecimal(double value, int precision) {
    int multiplier = static_cast<int>(std::pow(10, precision));
    int num = static_cast<int>(std::round(value * multiplier));
    return Fraction(num, multiplier);
}