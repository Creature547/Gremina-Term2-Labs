#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <limits>
#include "Planet.h"
#include "RailwayTicket.h"

using namespace std;

// Демонстрационный режим для Planet
void demoMode() {
    Planet* planets = nullptr;
    size_t count = 0;
    int choice;
    char filename[256];

    cout << "\n=== Демонстрационный режим (Planet) ===" << endl;

    do {
        cout << "\n1. Загрузить из файла\n2. Сохранить в файл\n3. Добавить планету\n"
             << "4. Удалить планету\n5. Редактировать планету\n6. Вывести все\n7. Сортировать по диаметру\n0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                cout << "Введите имя файла: ";
                cin.getline(filename, sizeof(filename));
                Planet::readFromFile(planets, count, filename);
                break;
            }
            case 2: {
                cout << "Введите имя файла: ";
                cin.getline(filename, sizeof(filename));
                Planet::writeToFile(planets, count, filename);
                break;
            }
            case 3: {
                if (count == 0) {
                    std::cout << "База данных пуста!\n";
                    break;
                }
                size_t index;
                std::cout << "Введите индекс (0-" << count-1 << "): ";
                std::cin >> index;
                std::cin.ignore();
                if (index > count) {
                    planets[index].addDemo(); // Вызов метода editDemo()
                }
                break;
            }
            case 4: {
                if (count == 0) {
                    cout << "База данных пуста!\n";
                    break;
                }
                size_t index;
                cout << "Введите индекс (0-" << count-1 << "): ";
                cin >> index;
                if (index >= count) {
                    cout << "Неверный индекс!\n";
                    break;
                }
                Planet* newArr = new Planet[count - 1];
                for (size_t i = 0, j = 0; i < count; ++i) {
                    if (i != index) newArr[j++] = std::move(planets[i]);
                }
                delete[] planets;
                planets = newArr;
                --count;
                break;
            }
            case 5: {
                if (count == 0) {
                    std::cout << "База данных пуста!\n";
                    break;
                }
                size_t index;
                std::cout << "Введите индекс (0-" << count-1 << "): ";
                std::cin >> index;
                std::cin.ignore();
                if (index < count) {
                    planets[index].editDemo(); // Вызов метода editDemo()
                }
                break;
            }
            case 6: {
                if (count == 0) {
                    cout << "База данных пуста!\n";
                    break;
                }
                for (size_t i = 0; i < count; ++i) {
                    cout << "[" << i << "] " << planets[i] << endl;
                }
                break;
            }
            case 7: {
                if (count == 0) {
                    cout << "База данных пуста!\n";
                    break;
                }
                sort(planets, planets + count);
                cout << "Данные отсортированы!\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    delete[] planets;
}

// Интерактивный режим для RailwayTicket
void interactiveMode() {
    RailwayTicket* tickets = nullptr;
    size_t count = 0;
    int choice;
    char filename[256];

    cout << "\n=== Интерактивный режим (RailwayTicket) ===" << endl;

    do {
        cout << "\n1. Загрузить из файла\n2. Сохранить в файл\n3. Добавить билет\n"
             << "4. Удалить билет\n5. Редактировать билет\n6. Вывести все\n7. Сортировать по месту\n0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                cout << "Введите имя файла: ";
                cin.getline(filename, sizeof(filename));
                RailwayTicket::readFromFile(tickets, count, filename);
                break;
            }
            case 2: {
                cout << "Введите имя файла: ";
                cin.getline(filename, sizeof(filename));
                RailwayTicket::writeToFile(tickets, count, filename);
                break;
            }
            case 3: {
                RailwayTicket t;
                cout << "Введите данные билета:\n";
                cin >> t;
                RailwayTicket* newArr = new RailwayTicket[count + 1];
                for (size_t i = 0; i < count; ++i) newArr[i] = tickets[i];
                newArr[count++] = t;
                delete[] tickets;
                tickets = newArr;
                break;
            }
            case 4: {
                if (count == 0) {
                    cout << "База данных пуста!\n";
                    break;
                }
                size_t index;
                cout << "Введите индекс (0-" << count-1 << "): ";
                cin >> index;
                if (index >= count) {
                    cout << "Неверный индекс!\n";
                    break;
                }
                RailwayTicket* newArr = new RailwayTicket[count - 1];
                for (size_t i = 0, j = 0; i < count; ++i) {
                    if (i != index) newArr[j++] = tickets[i];
                }
                delete[] tickets;
                tickets = newArr;
                --count;
                break;
            }
            case 5: {
                if (count == 0) {
                    cout << "База данных пуста!\n";
                    break;
                }
                size_t index;
                cout << "Введите индекс (0-" << count-1 << "): ";
                cin >> index;
                cin.ignore();
                if (index < count) {
                    cout << "Введите новые данные:\n";
                    RailwayTicket t;
                    cin >> t;
                    tickets[index] = t;
                }
                break;
            }
            case 6: {
                if (count == 0) {
                    cout << "База данных пуста!\n";
                    break;
                }
                for (size_t i = 0; i < count; ++i) {
                    cout << "[" << i << "] " << tickets[i] << endl;
                }
                break;
            }
            case 7: {
                if (count == 0) {
                    cout << "База данных пуста!\n";
                    break;
                }
                sort(tickets, tickets + count);
                cout << "Данные отсортированы!\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    delete[] tickets;
}

int main(int argc, char* argv[]) {
    if (argc > 1 && strcmp(argv[1], "-i") == 0) {
        interactiveMode(); // Режим для RailwayTicket
    } else {
        demoMode(); // Режим для Planet
    }
    return 0;
}
