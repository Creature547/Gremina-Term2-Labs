#include <iostream>
#include <string>

void task2() {
    std::string input, result;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    for (char c : input) {
        if (c == ' ') continue;
        if (c == '=') result += "==";
        else result += c;
    }

    std::cout << "Результат: " << result << "\n";
}
