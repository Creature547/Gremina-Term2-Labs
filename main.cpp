#include <iostream>
#include <cstring>

class Person {
//  public:
    // const char* name;
    char name[20];
    int age;
public:
    void print() { std::cout << "1 Name: " << name << "\tAge: " << age << std::endl; }
    void print(int) { std::cout << "2 Name: " << name << "\tAge: " << age << std::endl; }
    Person()
        : name("Name")
        , age(12)
    {std::cout << "Person(1) Default ctr" << std::endl;}
    Person(const char* new_name, int new_age = 9) {
        std::cout << "Person(2)" << std::endl;
        // name = new_name;
        for (int i=0;i<strlen(new_name);i++) {
            name[i] = new_name[i];
        }
        age = new_age;
        std::cout << "Person has been created" << std::endl;
    }

    friend std::ostream& operator << (std::ostream &out, const Person& p) {
        // p.age = 130;
        out << "fr Name: " << p.name << "\tAge: " << p.age << " " << &p << std::endl;
        return out;
    }

    friend std::istream& operator >> (std::istream &input, Person& p) {
        std::cout << "Enter name" << std::endl;
        // char name[20];
        // char* name = new char[20];
        input >> p.name;
        // std::cout << name << std::endl;
        // p.name = name;
        std::cout << "Enter age" << std::endl;
        input >> p.age;
        return input;
    }
    int homework(age);
};

int Person::homework(age) {
    std::cout << age << std::endl;
    return age;
}

int main() {
    Person tom("Tom", 38);  // создаем объект - вызываем конструктор
    tom.print(12);
    tom.homework(12);
    Person ann;  // создаем объект - вызываем конструктор
    ann.print();
    // std::cin >> tom;
    // std::cin >> ann;
    // std::cout << &tom << " " << tom << std::endl;
    // std::cout << &ann << " " << ann << std::endl;
}
