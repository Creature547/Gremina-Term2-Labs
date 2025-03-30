#include <iostream>
#include <fstream>
#include <cstring>
#include "Planet.h"

const int BUFFER_SIZE = 256;

struct Database {
    Planet* planets;
    int count;
};

void readDB(Database& db, const char* filename);
void writeDB(const Database& db, const char* filename);
void sortDB(Database& db, int (*compare)(const Planet*, const Planet*));
void addPlanet(Database& db, const Planet& planet);
void deletePlanet(Database& db, int index);
void editPlanet(Planet& planet);
void printDB(const Database& db);
void freeDB(Database& db);

// Функции сравнения для сортировки
int compareByName(const Planet* a, const Planet* b);
int compareByDiameter(const Planet* a, const Planet* b);
int compareByMoons(const Planet* a, const Planet* b);

int main() {
    Database db{nullptr, 0};
    int choice;
    char filename[BUFFER_SIZE];

    do {
        std::cout << "1. Read DB\n2. Write DB\n3. Sort DB\n4. Add Planet\n"
                  << "5. Delete Planet\n6. Edit Planet\n7. Print DB\n0. Exit\n";
        std::cin >> choice;
        std::cin.ignore();

        switch(choice) {
            case 1: {
                std::cout << "Enter filename: ";
                std::cin.getline(filename, BUFFER_SIZE);
                readDB(db, filename);
                break;
            }
            case 2: {
                std::cout << "Enter filename: ";
                std::cin.getline(filename, BUFFER_SIZE);
                writeDB(db, filename);
                break;
            }
            case 3: {
                std::cout << "Sort by:\n1. Name\n2. Diameter\n3. Moons\n";
                int sortChoice;
                std::cin >> sortChoice;
                switch(sortChoice) {
                    case 1: sortDB(db, compareByName); break;
                    case 2: sortDB(db, compareByDiameter); break;
                    case 3: sortDB(db, compareByMoons); break;
                }
                break;
            }
            case 4: {
                char name[BUFFER_SIZE];
                int diameter, moons;
                bool hasLife;

                std::cout << "Enter name: ";
                std::cin.getline(name, BUFFER_SIZE);
                std::cout << "Enter diameter: ";
                std::cin >> diameter;
                std::cout << "Has life (0/1): ";
                std::cin >> hasLife;
                std::cout << "Moons: ";
                std::cin >> moons;
                std::cin.ignore();

                addPlanet(db, Planet(name, diameter, hasLife, moons));
                break;
            }
            case 5: {
                int index;
                std::cout << "Enter index to delete: ";
                std::cin >> index;
                deletePlanet(db, index);
                break;
            }
            case 6: {
                int index;
                std::cout << "Enter index to edit: ";
                std::cin >> index;
                if(index >= 0 && index < db.count) {
                    editPlanet(db.planets[index]);
                }
                break;
            }
            case 7:
                printDB(db);
                break;
        }
    } while(choice != 0);

    freeDB(db);
    return 0;
}

// Реализация функций работы с БД

void readDB(Database& db, const char* filename) {
    std::ifstream file(filename);
    if(!file) {
        std::cerr << "Error opening file!\n";
        return;
    }
    else {
        std::cout << "File was successfully read!\n";
        freeDB(db);
        Planet* temp = new Planet[8]; // Начальный размер
        int capacity = 8;
        int count = 0;

        char buffer[BUFFER_SIZE];
        int d, m;
        bool h;

        while(file.getline(buffer, BUFFER_SIZE, ',')) {
            file >> d >> h >> m;
            file.ignore();

            if(count >= capacity) {
                capacity *= 2;
                Planet* newArr = new Planet[capacity];
                for(int i = 0; i < count; i++) newArr[i] = temp[i];
                delete[] temp;
                temp = newArr;
            }

            temp[count].setName(buffer);
            temp[count].setDiameter(d);
            temp[count].setHasLife(h);
            temp[count].setMoons(m);
            count++;
        }

        db.planets = temp;
        db.count = count;
        file.close();
    }
}

void writeDB(const Database& db, const char* filename) {
    std::ofstream file(filename);
    if(!file) {
        std::cerr << "Error creating file!\n";
        return;
    }

    for(int i = 0; i < db.count; i++) {
        file << db.planets[i].getName() << ","
             << db.planets[i].getDiameter() << " "
             << db.planets[i].getHasLife() << " "
             << db.planets[i].getMoons() << "\n";
    }
    file.close();
}

void sortDB(Database& db, int (*compare)(const Planet*, const Planet*)) {
    // Используем безопасный алгоритм сортировки
    for (size_t i = 0; i < db.count - 1; ++i) {
        for (size_t j = 0; j < db.count - i - 1; ++j) {
            if (compare(&db.planets[j], &db.planets[j + 1]) > 0) {
                std::swap(db.planets[j], db.planets[j + 1]);
            }
        }
    }
}

void addPlanet(Database& db, const Planet& planet) {
    Planet* newArr = new Planet[db.count + 1];
    for (int i = 0; i < db.count; ++i) {
        newArr[i] = db.planets[i]; // Используем оператор присваивания
    }
    newArr[db.count] = planet;
    delete[] db.planets;
    db.planets = newArr;
    ++db.count;
}

void deletePlanet(Database& db, int index) {
    if (index < 0 || index >= db.count) return;

    Planet* newArr = new Planet[db.count - 1];
    for (int i = 0, j = 0; i < db.count; ++i) {
        if (i != index) {
            newArr[j++] = db.planets[i]; // Используем оператор присваивания
        }
    }
    delete[] db.planets;
    db.planets = newArr;
    --db.count;
}

void editPlanet(Planet& planet) {
    char buffer[BUFFER_SIZE];
    int value;
    bool bValue;

    std::cout << "Edit name (current: " << planet.getName() << "): ";
    std::cin.getline(buffer, BUFFER_SIZE);
    if(strlen(buffer) > 0) planet.setName(buffer);

    std::cout << "Edit diameter (current: " << planet.getDiameter() << "): ";
    std::cin >> value;
    planet.setDiameter(value);

    std::cout << "Edit has life (0/1): ";
    std::cin >> bValue;
    planet.setHasLife(bValue);

    std::cout << "Edit moons: ";
    std::cin >> value;
    planet.setMoons(value);
    std::cin.ignore();
}

void printDB(const Database& db) {
    for(int i = 0; i < db.count; i++) {
        std::cout << "[" << i << "]\n";
        db.planets[i].printInfo();
    }
}

void freeDB(Database& db) {
    delete[] db.planets;
    db.planets = nullptr;
    db.count = 0;
}

// Функции сравнения
int compareByName(const Planet* a, const Planet* b) {
    return strcmp(a->getName(), b->getName());
}

int compareByDiameter(const Planet* a, const Planet* b) {
    return a->getDiameter() - b->getDiameter();
}

int compareByMoons(const Planet* a, const Planet* b) {
    return a->getMoons() - b->getMoons();
}
