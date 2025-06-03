#include <iostream>
#include <string>
class Animal {
protected:
    std::string name;
public:
    Animal(const std::string &name) {
        this->name = name;
    }
    ~Animal() {
        std::cout << "~Animal\n";
    }
    void print() {
        std::cout << "Animal: " << name << "\n";
    }
};

class Cat : public Animal {
public:
    Cat(const std::string &name)
        : Animal(name)
    {}
    ~Cat() {
        std::cout << "~Cat\n";
    }
    void print() {
        std::cout << "Cat: " << name << '\n';
    }
};

int main () {
    Animal** animals = new Animal*[3];
    for (int i = 0; i < 3; ++i) {
        animals[i] = new Animal("Random animal");
    }
    for (int i = 0; i < 3; ++i) {
        animals[i] -> print();
    }
    for (int i = 0; i < 3; ++i) {
        delete animals[i];
    }
    delete[] animals;
    std::cout << "myanimal\n";
    return 0;
}
