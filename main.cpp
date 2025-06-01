#include <iostream>
#include "polynomial.hpp"
#include <limits>

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

    int choice = 1;
    while (choice) {
        std::cout << "\nEnter polynomial: ";

        Polynomial p5;
        std::cin >> p5;
        std::cout << "Your polynomial: " << p5 << '\n';

        Polynomial p6 = p5 * p5 * p5;
        std::cout << "Cubed polynomial: " << p6 << '\n';

        std::cout << "\nContinue? (1/0): ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
