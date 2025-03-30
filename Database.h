#ifndef DATABASE_H
#define DATABASE_H

#include <cstddef>
#include "Planet.h"

class Database {
 private:
    Planet* planets;
    size_t count;
    size_t capacity;

    void resize(size_t newCapacity);
    void freeResources();

 public:
    Database();
    ~Database();
    Database(const Database& other);
    Database& operator=(const Database& other);
    Database(Database&& other) noexcept;
    Database& operator=(Database&& other) noexcept;

    void add(const Planet& planet);
    void remove(size_t index);
    void edit(size_t index);
    void sort(int (*compare)(const Planet*, const Planet*));
    void readFromFile(const char* filename);
    void writeToFile(const char* filename) const;
    void print() const;

    size_t getValidIndex() const;
    size_t size() const { return count; }
    const Planet& at(size_t index) const;
};

#endif
