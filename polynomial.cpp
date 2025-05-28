#include <sstream>
#include "polynomial.hpp"

Polynomial::Polynomial() : poly(), degree(0), order(Order::Descending) {}

Polynomial::Polynomial(int constant) : poly(), degree(0), order(Order::Descending) {
    if (constant != 0) {
        poly.add_element(Term(constant, 0));
    }
}

Polynomial::Polynomial(Term term) : poly(), order(Order::Descending) {
    if (term.getConstant() != 0) {
        poly.add_element(term);
        degree = term.getDegree();
    } else {
        degree = 0;
    }
}

Polynomial::~Polynomial() {}

Polynomial::Polynomial(const Polynomial& other)
    : poly(other.poly), degree(other.degree), order(other.order) {}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        poly = other.poly;
        degree = other.degree;
        order = other.order;
    }
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    for (size_t i = 0; i < other.poly.get_size(); ++i) {
        const Term& otherTerm = other.poly[i];
        if (otherTerm.getConstant() == 0) continue;

        bool found = false;
        for (size_t j = 0; j < poly.get_size(); ++j) {
            Term& currentTerm = poly[j];
            if (currentTerm.getDegree() == otherTerm.getDegree()) {
                int newConstant = currentTerm.getConstant() + otherTerm.getConstant();
                if (newConstant != 0) {
                    currentTerm.setConstant(newConstant);
                } else {
                    poly.delete_element(j);
                    j--;
                }
                found = true;
                break;
            }
        }

        if (!found) {
            poly.add_element(otherTerm);
        }
    }

    int maxDegree = 0;
    bool hasNonZero = false;
    if (poly.get_size() > 0) {
        for (size_t i = 0; i < poly.get_size(); ++i) {
            if (poly[i].getConstant() != 0) {
                hasNonZero = true;
                if (poly[i].getDegree() > maxDegree) {
                    maxDegree = poly[i].getDegree();
                }
            }
        }
    }
    degree = hasNonZero ? maxDegree : 0;
    return *this;
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result(p1);
    result += p2;
    return result;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    Polynomial result;
    for (size_t i = 0; i < poly.get_size(); ++i) {
        for (size_t j = 0; j < other.poly.get_size(); ++j) {
            int newConstant = poly[i].getConstant() * other.poly[j].getConstant();
            if (newConstant != 0) {
                Term product(newConstant, poly[i].getDegree() + other.poly[j].getDegree());
                result += Polynomial(product);
            }
        }
    }
    *this = result;
    return *this;
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result(p1);
    result *= p2;
    return result;
}

std::ostream& operator<<(std::ostream& out, Polynomial& p) {
    if (p.poly.get_size() == 0) {
        out << "0";
        return out;
    }

    p.poly.sort();
    if (p.order == Order::Descending) {
        size_t size = p.poly.get_size();
        for (size_t i = 0; i < size / 2; ++i) {
            std::swap(p.poly[i], p.poly[size - 1 - i]);
        }
    }

    bool first = true;
    for (size_t i = 0; i < p.poly.get_size(); ++i) {
        const Term& term = p.poly[i];
        if (term.getConstant() == 0) continue;

        if (!first) {
            out << (term.getConstant() > 0 ? " + " : " - ");
        } else if (term.getConstant() < 0) {
            out << "-";
        }

        int abs_coeff = std::abs(term.getConstant());
        if (abs_coeff != 1 || term.getDegree() == 0) {
            out << abs_coeff;
        }
        if (term.getDegree() != 0) {
            out << "x";
            if (term.getDegree() != 1 && term.getDegree() != -1) {
                out << "^" << term.getDegree();
            }
        }

        first = false;
    }

    if (first) {
        out << "0";
    }

    return out;
}

std::istream& operator>>(std::istream& in, Polynomial& p) {
    p = Polynomial();

    int current_sign = 1;

    while (in.peek() != '\n' && in.peek() != EOF) {
        while (std::isspace(in.peek())) {
            in.get();
        }

        char next = in.peek();
        if (next == '-') {
            current_sign = -1;
            in.get();
        } else if (next == '+') {
            current_sign = 1;
            in.get();
        }

        Term term;
        in >> term;

        term.setConstant(term.getConstant() * current_sign);
        p += Polynomial(term);

        current_sign = 1;
    }

    if (in.peek() == '\n') {
        in.get();
    }

    return in;
}
