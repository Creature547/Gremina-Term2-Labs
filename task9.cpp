#include <iostream>
#include <map>

void printMap(const std::map<std::string, int>& m) {
    for (const auto& [k, v] : m)
        std::cout << k << ": " << v << "\n";
}

void task9() {
    std::map<std::string, int> m1 = {
        {"яблоки", 100}, {"груши", 13}, {"арбузы", 20},
        {"картофель", 15}, {"алыча", 22}
    };

    std::map<std::string, int> m2 = {
        {"яблоки", 150}, {"груши", 18}, {"ананасы", 45},
        {"апельсины", 30}, {"киви", 35}
    };

    std::map<std::string, int> result = m1;
    for (const auto& [key, val] : m2) {
        result[key] = std::max(result[key], val);
    }

    std::cout << "Итоговый прайс:\n";
    printMap(result);
}
