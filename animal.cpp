#include <iostream>
#include <string>
class Animal {
protected:
    std::string name;
public:
    Animal(const std::string &name) {
        this->name = name;
    }
    virtual ~Animal() {
        std::cout << "~Animal" << std::endl;
    }
    virtual void print() const {
        std::cout << "Class Animal: " << name << std::endl;
    }
};
class Dog : public Animal {
public:
    Dog(const std::string &name)
        : Animal(name)
    {

    }
    ~Dog() {
        std::cout << "~Dog" << std::endl;
    }
    void print() const {
        std::cout << "Class Dog: " << name << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string &name)
        : Animal(name)
    {

    }
    ~Cat() {
        std::cout << "~Cat" << std::endl;
    }
    void print() const {
        std::cout << "Class Cat: " << name << std::endl;
    }
};

int main() {
    Animal** animals = new Animal*[4];
    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter: ";
        int n;
        std::cin >> n;
        if (n == 1) {
            animals[i] = new Cat("Мурзик");
        }
        else if (n == 2) {
            animals[i] = new Animal("Anim");
        }
        else {
            animals[i] = new Dog("Шарик");
        }
    }
    for (int i = 0; i < 4; ++i) {
        animals[i] -> print();
    }
    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }
    delete [] animals;
}


