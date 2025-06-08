#include <iostream>
#include "MyClasses.h"
#include "vector.h"

void print(const Vector<PrintedEdition*>& container) {
    std::cout << "\n--- Printed Editions in container ---\n";
    for (size_t i = 0; i < container.getSize(); ++i) {
        std::cout << "[" << i << "] ";
        container[i]->show();
    }
    std::cout << "-----------------------------\n";
}

void remove(Vector<PrintedEdition*>& container, size_t index) {
    if (index >= container.getSize()) {
        std::cout << "Invalid index!\n";
        return;
    }
    delete container[index];
    container.remove(index);
    std::cout << "Removed item at index " << index << "\n";
}

void clear(Vector<PrintedEdition*>& container) {
    for (size_t i = 0; i < container.getSize(); ++i) {
        delete container[i];
    }
    container.clear();
    std::cout << "Container cleared\n";
}

void demoMode() {
    std::cout << "\n=== DEMO MODE ===\n";

    Vector<PrintedEdition*> editions;

    editions.push_back(new Magazine("Science Monthly", 2023, 48, "Science", 5));
    editions.push_back(new Book("War and Peace", 1869, 1225, "Leo Tolstoy", 15));
    editions.push_back(new Textbook("Linear Algebra", 2022, 300, "Mathematics", "MSU"));

    print(editions);

    remove(editions, 1);
    print(editions);

    clear(editions);
    print(editions);
}

void interactiveMode() {
    std::cout << "\n=== INTERACTIVE MODE ===\n";

    Vector<PrintedEdition*> editions;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Magazine\n";
        std::cout << "2. Add Book\n";
        std::cout << "3. Add Textbook\n";
        std::cout << "4. Print all\n";
        std::cout << "5. Remove by index\n";
        std::cout << "6. Clear all\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        char title[100], theme[100], author[100], subject[100], institution[100];
        int year, pages, issue, chapters;

        switch (choice) {
            case 1:
                std::cout << "Title: "; std::cin >> title;
                std::cout << "Year: "; std::cin >> year;
                std::cout << "Pages: "; std::cin >> pages;
                std::cout << "Theme: "; std::cin >> theme;
                std::cout << "Issue number: "; std::cin >> issue;
                editions.push_back(new Magazine(title, year, pages, theme, issue));
                break;
            case 2:
                std::cout << "Title: "; std::cin >> title;
                std::cout << "Year: "; std::cin >> year;
                std::cout << "Pages: "; std::cin >> pages;
                std::cout << "Author: "; std::cin >> author;
                std::cout << "Chapters: "; std::cin >> chapters;
                editions.push_back(new Book(title, year, pages, author, chapters));
                break;
            case 3:
                std::cout << "Title: "; std::cin >> title;
                std::cout << "Year: "; std::cin >> year;
                std::cout << "Pages: "; std::cin >> pages;
                std::cout << "Subject: "; std::cin >> subject;
                std::cout << "Institution: "; std::cin >> institution;
                editions.push_back(new Textbook(title, year, pages, subject, institution));
                break;
            case 4:
                print(editions);
                break;
            case 5: {
                size_t index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                remove(editions, index);
                break;
            }
            case 6:
                clear(editions);
                break;
            case 0:
                clear(editions);
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

int main() {
    int mode;
    std::cout << "Select mode:\n1. Demo mode\n2. Interactive mode\nChoice: ";
    std::cin >> mode;

    if (mode == 1) {
        demoMode();
    } else if (mode == 2) {
        interactiveMode();
    } else {
        std::cout << "Invalid choice!\n";
    }

    return 0;
}
