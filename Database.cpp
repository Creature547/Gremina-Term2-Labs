#include "Database.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <utility>

const size_t INITIAL_CAPACITY = 8;

Database::Database() : planets(nullptr), count(0), capacity(0) {}

Database::~Database() {
    freeResources();
}

Database::Database(const Database& other) :
    count(other.count),
    capacity(other.capacity) {
    planets = new Planet[capacity];
    for(size_t i = 0; i < count; ++i) {
        planets[i] = other.planets[i];
    }
}

Database& Database::operator=(const Database& other) {
    if(this != &other) {
        freeResources();
        count = other.count;
        capacity = other.capacity;
        planets = new Planet[capacity];
        for(size_t i = 0; i < count; ++i) {
            planets[i] = other.planets[i];
        }
    }
    return *this;
}

Database::Database(Database&& other) noexcept :
    planets(std::exchange(other.planets, nullptr)),
    count(std::exchange(other.count, 0)),
    capacity(std::exchange(other.capacity, 0)) {}

Database& Database::operator=(Database&& other) noexcept {
    if(this != &other) {
        freeResources();
        planets = std::exchange(other.planets, nullptr);
        count = std::exchange(other.count, 0);
        capacity = std::exchange(other.capacity, 0);
    }
    return *this;
}

void Database::freeResources() {
    delete[] planets;
    planets = nullptr;
    count = capacity = 0;
}

void Database::resize(size_t newCapacity) {
    Planet* newArr = new Planet[newCapacity];
    for(size_t i = 0; i < count; ++i) {
        newArr[i] = std::move(planets[i]);
    }
    delete[] planets;
    planets = newArr;
    capacity = newCapacity;
}

void Database::add(const Planet& planet) {
    if(count >= capacity) {
        resize(capacity == 0 ? INITIAL_CAPACITY : capacity * 2);
    }
    planets[count++] = planet;
}

void Database::remove(size_t index) {
    if(index >= count) return;

    for(size_t i = index; i < count - 1; ++i) {
        planets[i] = std::move(planets[i + 1]);
    }
    --count;

    if(capacity > INITIAL_CAPACITY && count < capacity / 4) {
        resize(capacity / 2);
    }
}

void Database::edit(size_t index) {
    if(index >= count) return;
    planets[index].editInteractive();
}

void Database::sort(int (*compare)(const Planet*, const Planet*)) {
    for(size_t i = 0; i < count - 1; ++i) {
        for(size_t j = 0; j < count - i - 1; ++j) {
            if(compare(&planets[j], &planets[j+1]) > 0) {
                std::swap(planets[j], planets[j+1]);
            }
        }
    }
}

void Database::readFromFile(const char* filename) {
    std::ifstream file(filename);
    if(!file) {
        std::cerr << "Error opening file!\n";
        return;
    }
    else {
        std::cout << "File was successfully read!\n";
        freeResources();
        char buffer[256];
        int d, m;
        bool h;

        while(file.getline(buffer, sizeof(buffer), ',')) {
            file >> d >> h >> m;
            file.ignore();

            add(Planet(buffer, d, h, m));
        }
        file.close();
    }
}

void Database::writeToFile(const char* filename) const {
    std::ofstream file(filename);
    if(!file) {
        std::cerr << "Error creating file\n";
        return;
    }
    else {
        for(size_t i = 0; i < count; ++i) {
            file << planets[i].getName() << ","
                << planets[i].getDiameter() << " "
                << planets[i].getHasLife() << " "
                << planets[i].getMoons() << "\n";
        }
        file.close();
        std::cout << "File was successfully created\n";
    }
}

void Database::print() const {
    std::cout << "\n=== PLANET DATABASE (" << count << " entries) ===\n";
    for(size_t i = 0; i < count; ++i) {
        std::cout << "[" << i << "] ";
        planets[i].printInfo();
    }
}

size_t Database::getValidIndex() const {
    int input;
    while(true) {
        std::cout << "Enter index (0-" << count-1 << "): ";
        std::cin >> input;
        if(std::cin.fail() || input < 0 || static_cast<size_t>(input) >= count) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index! ";
        } else {
            std::cin.ignore();
            return static_cast<size_t>(input);
        }
    }
}

const Planet& Database::at(size_t index) const {
    return planets[index];
}
