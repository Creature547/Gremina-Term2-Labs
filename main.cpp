#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <limits>
#include "Planet.h"
#include "Database.h"

const int BUFFER_SIZE = 256;

int compareByName(const Planet* a, const Planet* b);
int compareByDiameter(const Planet* a, const Planet* b);
int compareByMoons(const Planet* a, const Planet* b);

int main() {
    Database db;
    int choice;
    char filename[BUFFER_SIZE];

    do {
        std::cout << "\n1. Read DB\n2. Write DB\n3. Sort DB\n4. Add Planet\n"
                  << "5. Delete Planet\n6. Edit Planet\n7. Print DB\n0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1: {
                std::cout << "Enter filename: ";
                std::cin.getline(filename, BUFFER_SIZE);
                db.readFromFile(filename);
                break;
            }
            case 2: {
                std::cout << "Enter filename: ";
                std::cin.getline(filename, BUFFER_SIZE);
                db.writeToFile(filename);
                break;
            }
            case 3: {
                std::cout << "Sort by:\n1. Name\n2. Diameter\n3. Moons\n";
                int sortChoice;
                std::cin >> sortChoice;
                std::cin.ignore();
                switch(sortChoice) {
                    case 1: db.sort(compareByName); break;
                    case 2: db.sort(compareByDiameter); break;
                    case 3: db.sort(compareByMoons); break;
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

                db.add(Planet(name, diameter, hasLife, moons));
                break;
            }
            case 5: {
                try {
                    size_t index = db.getValidIndex();
                    db.remove(index);
                } catch(...) {
                    std::cout << "Invalid input!\n";
                }
                break;
            }
            case 6: {
                try {
                    size_t index = db.getValidIndex();
                    db.edit(index);
                } catch(...) {
                    std::cout << "Invalid input!\n";
                }
                break;
            }
            case 7:
                db.print();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}

int compareByName(const Planet* a, const Planet* b) {
    return strcmp(a->getName(), b->getName());
}

int compareByDiameter(const Planet* a, const Planet* b) {
    return a->getDiameter() - b->getDiameter();
}

int compareByMoons(const Planet* a, const Planet* b) {
    return a->getMoons() - b->getMoons();
}
