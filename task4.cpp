#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

void printVector(const std::vector<double>& vec) {
    for (double x : vec) std::cout << x << " ";
    std::cout << "\n";
}

void task4() {
    std::vector<double> vec(6);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-100, 100);

    std::generate(vec.begin(), vec.end(), [&]() { return dist(gen); });

    std::cout << "Исходный вектор:\n";
    printVector(vec);

    double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    std::cout << "Сумма: " << sum << "\n";

    if (vec.size() > 2) vec.erase(vec.begin() + 2);

    std::cout << "После удаления:\n";
    printVector(vec);
}
