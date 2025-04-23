#include "fraction.h"
#include <cstdio>
#include <sstream>
#include <cstring>

int Fraction::N_DEC = 4;

void Fraction::setNDec(int n) {
    N_DEC = n > 0 ? n : 4;
}

// Конструкторы
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) throw std::invalid_argument("Denominator cannot be zero");
    reduce();
}

Fraction::Fraction(const char* str) {
    parseString(str);
    reduce();
}

Fraction::Fraction(double d) {
    int precision = N_DEC;
    double scaled = d * pow(10, precision);
    int num = static_cast<int>(round(scaled));
    numerator = num;
    denominator = static_cast<int>(pow(10, precision));
    reduce();
}

// Парсинг строки
void Fraction::parseString(const char* str) {
    int whole = 0, num = 0, den = 1;
    int sign = 1;
    int chars_read = 0;
    const char* p = str;

    // Обработка знака
    if (*p == '-') {
        sign = -1;
        p++;
    } else if (*p == '+') {
        p++;
    }

    // Парсинг разных форматов
    if (sscanf(p, "%d %d/%d%n", &whole, &num, &den, &chars_read) == 3) {
        p += chars_read;
    } else if (sscanf(p, "%d/%d%n", &num, &den, &chars_read) == 2) {
        p += chars_read;
    } else if (sscanf(p, "%d%n", &whole, &chars_read) == 1) {
        p += chars_read;
    } else {
        throw std::invalid_argument("Invalid fraction format");
    }

    if (*p != '\0') throw std::invalid_argument("Extra characters in input");
    if (den == 0) throw std::invalid_argument("Zero denominator");

    numerator = sign * (whole * den + num);
    denominator = den;
}

// Сокращение дроби
void Fraction::reduce() {
    if (denominator == 0) throw std::logic_error("Zero denominator");
    int common = gcd(abs(numerator), denominator);
    numerator /= common;
    denominator /= common;

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

// НОД
int Fraction::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    int num = f.numerator;
    int den = f.denominator;

    if (den == 1) {
        os << num;
    } else {
        int whole = num / den;
        int remainder = abs(num % den);

        if (whole != 0) {
            os << whole << " " << remainder << "/" << den;
        } else {
            os << num << "/" << den;
        }
    }
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, Fraction& f) {
    char buffer[256];
    is.getline(buffer, sizeof(buffer));

    try {
        f = Fraction(buffer);
    } catch (const std::exception& e) {
        is.setstate(std::ios::failbit);
    }
    return is;
}

// Арифметические операции
Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(
        numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator
    );
}

Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction Fraction::operator+(int i) const {
    return *this + Fraction(i);
}

Fraction& Fraction::operator+=(int i) {
    *this = *this + Fraction(i);
    return *this;
}

Fraction Fraction::operator+(double d) const {
    return *this + Fraction(d);
}

Fraction& Fraction::operator+=(double d) {
    *this = *this + Fraction(d);
    return *this;
}

Fraction operator+(int i, const Fraction& f) {
    return Fraction(i) + f;
}

Fraction operator+(double d, const Fraction& f) {
    return Fraction(d) + f;
}
