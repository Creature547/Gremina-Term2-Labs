#include <iostream>
#include <cstring>
#include <utility>
#include "Planet.h"

const int BUFFER_SIZE = 256;

// Конструкторы и деструктор
Planet::Planet() : name(nullptr), diameter(0), hasLife(false), moons(0) {}

Planet::Planet(const char* n, int d, bool h, int m) :
    diameter(d), hasLife(h), moons(m) {
    allocateName(n);
}

Planet::~Planet() {
    delete[] name;
}

// Методы управления памятью
void Planet::allocateName(const char* source) {
    if (source) {
        name = new char[strlen(source) + 1];
        strcpy(name, source);
    } else {
        name = nullptr;
    }
}

// Конструктор копирования
Planet::Planet(const Planet& other) :
    diameter(other.diameter),
    hasLife(other.hasLife),
    moons(other.moons) {
    allocateName(other.name);
}

// Копирующее присваивание
Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {
        // Освобождаем старые ресурсы
        delete[] name;

        // Копируем новые данные
        allocateName(other.name);
        diameter = other.diameter;
        hasLife = other.hasLife;
        moons = other.moons;
    }
    return *this;
}

// Перемещающий конструктор
Planet::Planet(Planet&& other) noexcept :
    name(std::exchange(other.name, nullptr)),
    diameter(std::exchange(other.diameter, 0)),
    hasLife(std::exchange(other.hasLife, false)),
    moons(std::exchange(other.moons, 0)) {}

// Перемещающее присваивание
Planet& Planet::operator=(Planet&& other) noexcept {
    if (this != &other) {
        delete[] name;

        name = std::exchange(other.name, nullptr);
        diameter = std::exchange(other.diameter, 0);
        hasLife = std::exchange(other.hasLife, false);
        moons = std::exchange(other.moons, 0);
    }
    return *this;
}

// Геттеры
const char* Planet::getName() const { return name; }
int Planet::getDiameter() const { return diameter; }
bool Planet::getHasLife() const { return hasLife; }
int Planet::getMoons() const { return moons; }

// Сеттеры
void Planet::setName(const char* n) {
    delete[] name;
    allocateName(n);
}

void Planet::setDiameter(int d) { diameter = d; }
void Planet::setHasLife(bool h) { hasLife = h; }
void Planet::setMoons(int m) { moons = m; }

void Planet::printInfo() const {
    std::cout << "Name: " << (name ? name : "N/A")
              << "\nDiameter: " << diameter
              << " km\nHas life: " << (hasLife ? "Yes" : "No")
              << "\nMoons: " << moons << "\n\n";
}
