#ifndef PLANET_H
#define PLANET_H

class Planet {
private:
    char* name;
    int diameter;
    bool hasLife;
    int moons;

    void allocateName(const char* source);

public:
    Planet();
    Planet(const char* n, int d, bool h, int m);
    ~Planet();

    // Правило пяти
    Planet(const Planet& other);                // Конструктор копирования
    Planet& operator=(const Planet& other);     // Копирующее присваивание
    Planet(Planet&& other) noexcept;            // Перемещающий конструктор
    Planet& operator=(Planet&& other) noexcept; // Перемещающее присваивание

    // Геттеры
    const char* getName() const;
    int getDiameter() const;
    bool getHasLife() const;
    int getMoons() const;

    // Сеттеры
    void setName(const char* n);
    void setDiameter(int d);
    void setHasLife(bool h);
    void setMoons(int m);

    void printInfo() const;
};

#endif
