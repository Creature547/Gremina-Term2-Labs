#include <iostream>
#include <list>
#include <string>

class Inventory {
    std::string item;
    double cost;
    int on_hand;

public:
    Inventory() : item(""), cost(0), on_hand(0) {}
    Inventory(std::string i, double c, int q) : item(i), cost(c), on_hand(q) {}

    void print() const {
        std::cout << item << " - " << cost << " - " << on_hand << "\n";
    }

    bool isEmpty() const { return on_hand == 0; }

    bool operator<(const Inventory& other) const {
        return item < other.item;
    }

    bool operator==(const Inventory& other) const {
        return item == other.item && cost == other.cost && on_hand == other.on_hand;
    }
};

void printList(const std::list<Inventory>& lst) {
    for (const auto& item : lst) item.print();
}

void task7() {
    std::list<Inventory> items = {
        {"Отверка", 99, 0}, {"Молоток", 430, 10},
        {"Гайки", 70, 100}, {"Профиль", 540, 0},
        {"Уголок", 230, 9}, {"Доска", 350, 17}
    };

    std::cout << "Все товары:\n";
    printList(items);

    std::list<Inventory> emptyItems;
    for (const auto& i : items)
        if (i.isEmpty()) emptyItems.push_back(i);

    std::cout << "\nЗакончились:\n";
    printList(emptyItems);
}
