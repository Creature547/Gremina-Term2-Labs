#pragma once

#include <iostream>

namespace fraction {

class Fraction {
 private:
    bool positive;
    int base;
    int numerator;
    int denominator;

    void simplify();
    void is_correct();
    void parse_str(const char* str);

 public:
    Fraction();
    Fraction(int whole); // нада сделать
    Fraction(int whole, int numerator, int denominator);
    Fraction(const char* str);
    Fraction(int numerator, int denominator);
    Fraction(double num);
    Fraction Sum(double number, const Fraction& other);

   //  Fraction operator+(const Fraction& other) const;
   //  Fraction operator+(double number) const;
   //  Fraction operator+(int number) const;

   //  friend Fraction operator+(double number, const Fraction& other);
   //  friend Fraction operator+(int number, const Fraction& other);
    friend Fraction operator+(Fraction lhs, const Fraction& rhs); // lhs копия, будем += к этой копии НАДА СДЕЛАТЬ

    void operator+=(const Fraction& other);
   //  void operator+=(double number);

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);
};

}  // namespace fraction  operator+(3, F) =  F.operator+(3) = F + 3
// 3 + F
