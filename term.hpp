#pragma once
#include <iostream>

class Term {
 private:
    int constant;
    int degree;

 public:
    Term();
    Term(int constant);
    Term(int constant, int degree);

    ~Term();

    Term operator+(const Term& other) const;

    friend std::ostream& operator<<(std::ostream& out, Term& term);
    friend std::istream& operator>>(std::istream& in, Term& term);

    bool operator<(const Term& other) const;
    bool operator>(const Term& other) const;
    bool operator==(const Term& other) const;
    bool operator!=(const Term& other) const;

    int getConstant() const;
    int getDegree() const;

    void setConstant(int newConstant);

    friend class Polynomial;
};
