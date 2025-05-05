#include <iostream>

class Person {
 public:
    const char* name;
    int age;
    void print() { std::cout << "Name: " << name << "\tAge: " << age << std::endl; }
    Person(const char* new_name = "WW", int new_age = 9) {
        name = new_name;
        age = new_age;
        std::cout << "Person has been created" << std::endl;
    }
    // Person(const char* new_name) {
    //     name = new_name;
    //     age = 20;
    //     std::cout << "Person has been created" << std::endl;
    // }
    // Person(int new_age) {
    //     name = "Random";
    //     age = 11;
    //     std::cout << "Person has been created" << std::endl;
    // }
};
int main() {
    Person tom("Tom", 38);  // создаем объект - вызываем конструктор
    tom.print();
    Person ann;  // создаем объект - вызываем конструктор
    ann.print();
}
