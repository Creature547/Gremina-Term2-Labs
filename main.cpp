#include <iostream>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();

int main() {
    bool running = true;

    while (running) {
        int choice;
        std::cout << "\nВведите номер задания (1-9): ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            default: std::cout << "Неверный номер задания.\n"; break;
        }

        std::cout << "\nХотите продолжить выполнение программы? (1 — да / 0 — нет): ";
        std::cin >> running;
        std::cin.ignore();
    }

    std::cout << "Завершение программы.\n";
}
