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

    void printInfo() const;
    void editInteractive();
};

#endif
