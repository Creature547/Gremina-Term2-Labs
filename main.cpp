#include <iostream>
#include "mymath/mymath.h"
#include "subtraction/subtraction.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;

    std::cout << "Я умею вычитать! Зацени 1-1=";
    std::cout << subtraction::subtract(10, 32) << std::endl;

    return 0;
}
