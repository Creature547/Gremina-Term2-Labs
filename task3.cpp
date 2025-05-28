#include <iostream>
#include <fstream>
#include <cctype>

void task3() {
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");

    if (!inFile || !outFile) {
        std::cout << "Ошибка открытия файла.\n";
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        outFile << (isdigit(ch) ? '*' : ch);
    }

    std::cout << "Готово. Проверьте файл output.txt.\n";
}
