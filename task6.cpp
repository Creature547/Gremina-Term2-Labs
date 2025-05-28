#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include <random>

void printList(const std::list<double>& lst) {
    for (double x : lst) std::cout << x << " ";
    std::cout << "\n";
}

void task6() {
    std::list<double> lst;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-100, 100);

    for (int i = 0; i < 6; ++i)
        lst.push_back(dist(gen));

    std::cout << "Список:\n";
    printList(lst);

    double sum = std::accumulate(lst.begin(), lst.end(), 0.0);
    std::cout << "Сумма: " << sum << "\n";

    auto it = lst.begin();
    std::advance(it, 2);
    if (it != lst.end()) lst.erase(it);

    std::cout << "После удаления:\n";
    printList(lst);
}
