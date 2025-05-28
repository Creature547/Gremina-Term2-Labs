#include <iostream>
#include <map>

void task8() {
    std::map<std::string, int> people = {
        {"Иванов", 99}, {"Петров", 430}, {"Семенов", 70},
        {"Котов", 540}, {"Белых", 230}, {"Черных", 350}
    };

    std::cout << "До увеличения:\n";
    for (const auto& [k, v] : people)
        std::cout << k << ": " << v << "\n";

    for (auto& [_, v] : people)
        ++v;

    std::cout << "\nПосле увеличения:\n";
    for (const auto& [k, v] : people)
        std::cout << k << ": " << v << "\n";
}
