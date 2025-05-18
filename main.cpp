#include <iostream>
#include <cstring>

class Person {
//  public:
    // const char* name;
    char name[20];
    int age = 0;
    inline static int counter = 0;
public:
    void print() { std::cout << "1 Name: " << name << "\tAge: " << age << std::endl; }
    void print(int) { std::cout << "2 Name: " << name << "\tAge: " << age << std::endl; }
    Person()
        : name("Name")
        , age(12)
    {
        std::cout << "Person(1) Default ctr" << std::endl;
        counter++;
    }

    Person(const char* new_name, int new_age = 9) {
        std::cout << "Person(2)" << std::endl;
        // name = new_name;
        for (int i=0;i<strlen(new_name);i++) {
            name[i] = new_name[i];
        }
        age = new_age;
        std::cout << "Person has been created" << std::endl;
        counter++;
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
    int homework(int);
    int homework(int) const;
    int homework(double) ;

    static int total() {
        // std::cout << age << std::endl;
        return counter;
    }
};

// int Person::counter = 0;



int Person::homework(int newage) {
    std::cout << "homework(int newage) "<< age << std::endl;
    age = newage;
    return this->age;
}

int Person::homework(int newage) const{
    std::cout << "homework(int newage) const "<< age << std::endl;
    return this->age;
}

int Person::homework(double newage) {
    std::cout << "homework(double newage) "<< age << std::endl;
    return this->age;
}

int main() {
    Person tom("Tom", 38);  // создаем объект - вызываем конструктор
    tom.print(12);
    int a = tom.homework(190);
    std::cout << "counter: " << Person::total() << std::endl;
    std::cout << a << std::endl;
    const Person Ben("ben", 20);
    std::cout << "counter: " << Person::total() << std::endl;
    std::cout << Ben.homework(10) << std::endl;
    std::cout << tom.homework(78.3) << std::endl;
    std::cout << Ben.homework(50.2) << std::endl;
    Person ann;  // создаем объект - вызываем конструктор
    std::cout << "counter: " << Person::total() << std::endl;
    ann.print();
    // std::cin >> tom;
    // std::cin >> ann;
    // std::cout << &tom << " " << tom << std::endl;
    // std::cout << &ann << " " << ann << std::endl;
    // Person::print();
    std::cout << ann.total() << std::endl;
    std::cout << Person::total() << std::endl;
}
