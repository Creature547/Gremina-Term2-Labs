#include <iostream>
#include "src/app.hpp"

int main(int argc, char** argv) {
   std::cout << 100 << std::endl;
    // fraction::Fraction fraction1;
    // fraction.reduce();
    // std::cout << operator+(10, fraction1) << std::endl;
    app::run(argc, argv);
    return 0;
}
