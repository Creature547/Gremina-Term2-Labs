#include "term.hpp"
#include <cctype>

Term::Term() : constant(0), degree(0) {
}
Term::Term(int constant) : constant(constant), degree(0) {
}
Term::Term(int constant, int degree) : constant(constant), degree(degree) {
}

Term::~Term() {
}

Term Term::operator+(const Term& other) const {
    if (degree != other.degree) {
        throw std::runtime_error("Summing terms with different degrees");
    }
    return {constant + other.constant, degree};
}

std::ostream& operator<<(std::ostream& out, Term& term) {
    if (term.constant == 0) {
        out << "0";
        return out;
    }
    if (term.degree == 0) {
        out << term.constant;
        return out;
    }
    if (term.constant == -1) {
        out << "-";
    } else if (term.constant != 1) {
        out << term.constant;
    }
    out << "x";
    if (term.degree != 1 && term.degree != -1) {
        out << "^" << term.degree;
    }
    return out;
}

bool Term::operator<(const Term& other) const {
    return degree < other.degree;
}

bool Term::operator>(const Term& other) const {
    return degree > other.degree;
}

bool Term::operator==(const Term& other) const {
    return (constant == other.constant) && (degree == other.degree);
}

bool Term::operator!=(const Term& other) const {
    return !(*this == other);
}

int Term::getConstant() const {
    return constant;
}
int Term::getDegree() const {
    return degree;
}

void Term::setConstant(int newConstant) {
    constant = newConstant;
}

std::istream& operator>>(std::istream& in, Term& term) {
    int coeff = 1;
    int degree = 0;
    int sign = 1;

    while (std::isspace(in.peek()) && in.peek() != '\n') {
        in.get();
    }

    if (in.peek() == '\n' || in.peek() == EOF) {
        term = Term(0, 0);
        return in;
    }

    char ch = in.peek();
    if (ch == '-') {
        sign = -1;
        in.get();
    } else if (ch == '+') {
        in.get();
    }

    while (std::isspace(in.peek()) && in.peek() != '\n') {
        in.get();
    }

    if (std::isdigit(in.peek())) {
        int num = 0;
        while (std::isdigit(in.peek())) {
            num = num * 10 + (in.get() - '0');
        }
        coeff = num * sign;
    } else if (in.peek() == 'x') {
        coeff = sign;
    } else {
        throw std::runtime_error("Invalid term format");
    }

    while (std::isspace(in.peek()) && in.peek() != '\n') {
        in.get();
    }

    if (in.peek() == 'x') {
        in.get();
        while (std::isspace(in.peek()) && in.peek() != '\n') {
            in.get();
        }
        if (in.peek() == '^') {
            in.get();

            while (std::isspace(in.peek())) {
                in.get();
            }

            int degreeSign = 1;
            if (in.peek() == '-') {
                degreeSign = -1;
                in.get();
            } else if (in.peek() == '+') {
                in.get();
            }

            while (std::isspace(in.peek())) {
                in.get();
            }

            if (!std::isdigit(in.peek())) {
                throw std::runtime_error("Expected digit after ^");
            }

            int degreeValue = 0;
            while (std::isdigit(in.peek())) {
                degreeValue = degreeValue * 10 + (in.get() - '0');
            }
            degree = degreeSign * degreeValue;
        } else {
            degree = 1;
        }
    } else {
        degree = 0;
    }

    term = Term(coeff, degree);
    return in;
}
