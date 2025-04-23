#include <iostream>
#include <iomanip>
#include <cstring>
#include "fraction.h"

void demo();
void interactive();

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    if (argc > 1 && strcmp(argv[1], "-i") == 0) {
        interactive();
    } else {
        demo();
    }
    return 0;
}

void demo() {
    std::cout << "=== Демонстрационный режим ===\n";

    Fraction z("-2 6/18");
    std::cout << "z = " << z << std::endl;

    Fraction fr1(10, 14), fr2;
    std::cout << "fr2 = " << fr2 << std::endl;
    std::cout << "fr1 = " << fr1 << std::endl;

    Fraction fr = "-1 4/8";
    std::cout << "fr = " << fr << std::endl;

    Fraction x(z), y;
    std::cout << "x = " << x << std::endl;

    double dbl = -1.25;
    Fraction f = dbl;
    std::cout << "f = " << f << std::endl;

    y = x + z;
    std::cout << "y = " << y << std::endl;

    y += x;
    f += dbl / 2;
    std::cout << "f += dbl/2: " << f << std::endl;

    y = x + dbl;
    std::cout << "y = x + dbl: " << y << std::endl;

    y = dbl + y;
    std::cout << "y = dbl + y: " << y << std::endl;

    y += dbl;
    std::cout << "y += dbl: " << y << std::endl;

    int i = 5;
    y += i;
    std::cout << "y += 5: " << y << std::endl;

    y = i + x;
    std::cout << "y = 5 + x: " << y << std::endl;

    y = x + i;
    std::cout << "y = x + 5: " << y << std::endl;

    y += dbl + i + x;
    std::cout << "y += dbl + 5 + x: " << y << std::endl;
}

void interactive() {
    std::cout << "=== Интерактивный режим ===\n";

    Fraction z;
    std::cout << "Введите дробь (пример: -2 6/18, 5/3, 4): ";
    std::cin >> z;
    std::cout << "z = " << z << "\n\n";

    Fraction x(z), y;
    std::cout << "x = " << x << std::endl;

    double dbl;
    std::cout << "Введите double значение: ";
    std::cin >> dbl;
    Fraction f = dbl;
    std::cout << "f = " << f << std::endl;

    y = x + z;
    std::cout << "y = x + z: " << y << std::endl;

    y += x;
    std::cout << "y += x: " << y << std::endl;

    f += dbl / 2;
    std::cout << "f += dbl/2: " << f << std::endl;

    y = x + dbl;
    std::cout << "y = x + dbl: " << y << std::endl;

    y = dbl + y;
    std::cout << "y = dbl + y: " << y << std::endl;

    y += dbl;
    std::cout << "y += dbl: " << y << std::endl;

    int i;
    std::cout << "Введите целое число: ";
    std::cin >> i;
    y += i;
    std::cout << "y += " << i << ": " << y << std::endl;

    y = i + x;
    std::cout << "y = " << i << " + x: " << y << std::endl;

    y = x + i;
    std::cout << "y = x + " << i << ": " << y << std::endl;

    y += dbl + i + x;
    std::cout << "y += dbl + " << i << " + x: " << y << std::endl;
}
