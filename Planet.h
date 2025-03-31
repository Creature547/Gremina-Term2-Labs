#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>

class Planet {
private:
    char* name;
    int diameter;
    bool hasLife;
    int moons;
    static int counter;
    int id;

    void allocateName(const char* source);

public:
    Planet();
    Planet(const char* n, int d, bool h, int m);
    ~Planet();

    Planet(const Planet& other);
    Planet& operator=(const Planet& other);
    Planet(Planet&& other) noexcept;
    Planet& operator=(Planet&& other) noexcept;

    const char* getName() const;
    int getDiameter() const;
    bool getHasLife() const;
    int getMoons() const;

    void setName(const char* n);
    void setDiameter(int d);
    void setHasLife(bool h);
    void setMoons(int m);

    void editDemo();
    void addDemo();
    void printInfo() const;

    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
    friend std::istream& operator>>(std::istream& is, Planet& planet);
    bool operator<(const Planet& other) const;
    bool operator==(const Planet& other) const;

    static void readFromFile(Planet*& planets, size_t& count, const char* filename);
    static void writeToFile(const Planet* planets, size_t count, const char* filename);
};

#endif
