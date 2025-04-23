#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstring>

class Fraction {
private:
    int numerator;
    int denominator;
    static int N_DEC;

    void reduce();
    int gcd(int a, int b) const;
    void parseString(const char* str);

public:
    // Конструкторы
    Fraction(int num = 0, int denom = 1);
    Fraction(const char* str);
    Fraction(double d);

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);

    // Арифметические операции
    Fraction operator+(const Fraction& other) const;
    Fraction& operator+=(const Fraction& other);
    Fraction operator+(int i) const;
    Fraction& operator+=(int i);
    Fraction operator+(double d) const;
    Fraction& operator+=(double d);

    // Дружественные функции для операций с разными типами
    friend Fraction operator+(int i, const Fraction& f);
    friend Fraction operator+(double d, const Fraction& f);

    // Утилиты
    static void setNDec(int n);
};

#endif // FRACTION_H
