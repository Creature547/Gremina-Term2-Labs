#include <iostream>
#include "polynomial.hpp"

int main() {
    Term a(-1, -3);
    Term b(10, 3);

    Polynomial p1;
    std::cout << p1 << '\n';

    Polynomial p2(123);
    std::cout << p2 << '\n';

    Polynomial p3(a);
    std::cout << p3 << '\n';

    Polynomial p4(b);
    std::cout << p4 << '\n';

    Polynomial p5;
    std::cin >> p5;
    std::cout << p5 << '\n';

    Polynomial p6 = p5 * p5 * p5;
    std::cout << p6 << '\n';

    return 0;
}
