#include <cstring>
#include <iostream>

#include "../fraction/fraction.hpp"
#include "app.hpp"

namespace app {

void runDemonstrativeMode() {
    fraction::Fraction z(3, 5);
    std::cout << "z=" << z << std::endl;

    fraction::Fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    fraction::Fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    fraction::Fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    fraction::Fraction f = dbl;
    std::cout << "f=" << f << std::endl;

    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
}

void runInteractiveMode() {
    std::cout << "Enter a fraction, z=" << std::endl;
    fraction::Fraction z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;

    fraction::Fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    fraction::Fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    fraction::Fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    fraction::Fraction f = dbl;
    std::cout << "f=" << f << std::endl;

    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
}

void run(int argc, char** argv) {
    if (argc == 2 && std::strcmp(argv[1], "-i") == 0) {
        runInteractiveMode();
        return;
    }
    runDemonstrativeMode();
}

}  // namespace app
