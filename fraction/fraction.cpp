#include <iostream>
#include <cstring>
#include <cmath>

#include "fraction.hpp"


namespace {

constexpr char Minus = '-';
constexpr char Space = ' ';
constexpr char Slash = '/';

constexpr size_t BufferSize = 1024;
constexpr int MaxInt = 1000000;
constexpr int NDec = 4;

int gcd(int a, int b) {
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }

    return a;
}

bool char_is_num(const char c) {
    return c >= '0' && c <= '9';
}

int char_to_int(const char c) {
    return c - '0';
}

bool is_char_in_str(const char* str, char ch) {
    return std::strchr(str, ch) != nullptr;
}

} // namespace


namespace fraction {

void Fraction::reduce() {
    int koef = gcd(numerator, denominator);
    numerator /= koef;
    denominator /= koef;
    base += static_cast<int>(numerator/denominator);
    numerator %= denominator;
}

void Fraction::is_correct() {
    if (denominator == 0) {
        throw std::runtime_error("Error: incorrect denominator in fraction.");
    }

    if (base >= MaxInt || numerator >= MaxInt || denominator >= MaxInt) {
        throw std::runtime_error("Error: fraction is very big.");
    }
}

void Fraction::parse_str(const char* str) {
    positive = true;
    base = 0;
    numerator = 0;
    denominator = 0;

    int str_len = std::strlen(str);

    enum class Mode {
        null,
        base,
        numerator,
        denominator,
    };

    Mode mode = is_char_in_str(str, Space) ? Mode::base : Mode::numerator;

    for (int i = 0; i < str_len; i++) {
        char current = str[i];
        if (current == Minus && i == 0) {
            positive = false;
        } else if (current == Space && mode == Mode::base) {
            mode = Mode::numerator;
        } else if (current == Slash && mode == Mode::numerator) {
            mode = Mode::denominator;
        } else if (char_is_num(current)) {

            if (mode == Mode::base) {
                base = base * 10 + char_to_int(current);
                if (base > MaxInt) throw std::runtime_error("Base is over big");

            } else if (mode == Mode::numerator) {
                numerator = numerator * 10 + char_to_int(current);
                if (numerator > MaxInt) throw std::runtime_error("Numerator is over big");

            } else if (mode == Mode::denominator) {
                denominator = denominator * 10 + char_to_int(current);
                if (denominator > MaxInt) throw std::runtime_error("Numerator is over big.");
            }

        } else {
            throw std::runtime_error("Invalid input string");
        }
    }

    if (mode == Mode::numerator) {
        throw std::runtime_error("Invalid input string");
    }
}

Fraction::Fraction() : base(0), numerator(0), denominator(1), positive(true) {}

Fraction::Fraction(const char* str) {
    parse_str(str);
    is_correct();
    reduce();
}

Fraction::Fraction(int base, int numerator, int denominator)
    : base(abs(base)), numerator(abs(numerator)), denominator(abs(denominator)), positive(base >= 0) {
    is_correct();
    reduce();
}

Fraction::Fraction(int numerator, int denominator) : base(0), numerator(abs(numerator)), denominator(abs(denominator)), positive(numerator >= 0) {
    is_correct();
    reduce();
}

Fraction::Fraction(double num) : base(0) {
    numerator = abs(static_cast<int>(std::pow(10, NDec) * num));
    denominator = std::pow(10, NDec);
    positive = num >= 0;
    reduce();
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction((this->positive ? 1 : -1) * (this->base * this->denominator + this->numerator) * other.denominator +
                        (other.positive ? 1 : -1) * (other.base * other.denominator + other.numerator) * this->denominator,
                    this->denominator * other.denominator);
}

Fraction Fraction::operator+(double number) const {
    return *this + Fraction(number);
}

// Fraction Fraction::operator+(int number) const {
//     return *this + Fraction(number, 0, 1);
// }

Fraction operator+(const Fraction& other, int number) {
    return other + Fraction(number, 1);
}

Fraction operator+(double number, const Fraction& other) {
    return other + number;
}

Fraction operator+(int number, const Fraction& other) {
    return other + number;
}

void Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
}

void Fraction::operator+=(double number) {
    *this = *this + number;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    if (!fraction.positive) {
        os << Minus;
    }
    if (fraction.base != 0) {
        os << fraction.base << Space;
    }
    if (fraction.numerator != 0) {
        os << fraction.numerator << Slash << fraction.denominator;
    }
    if (fraction.numerator == 0 && fraction.base == 0) {
        os << 0;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction) {
    char str[BufferSize];
    is.getline(str, sizeof(str));
    fraction = Fraction(str);
    return is;
}


} // namespace fraction
