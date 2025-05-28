#pragma once

#include "myvector.hpp"
#include "term.hpp"

enum class Order { Ascending, Descending };

class Polynomial {
private:
    MyVector<Term> poly;
    int degree;
    Order order;

public:
    Polynomial();
    explicit Polynomial(int constant);
    explicit Polynomial(Term term);
    Polynomial(const Polynomial& other);
    ~Polynomial();

    Polynomial& operator=(const Polynomial& other);
    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator*=(const Polynomial& other);

    friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);

    friend std::ostream& operator<<(std::ostream& out, Polynomial& p);
    friend std::istream& operator>>(std::istream& in, Polynomial& p);
};
