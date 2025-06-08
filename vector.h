#pragma once

#include <stdexcept>

template<typename T>
class Vector {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t newCapacity);

public:
    Vector();
    Vector(size_t initialCapacity);
    ~Vector();

    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    void push_back(const T& value);
    void remove(size_t index);
    void clear();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};

template<typename T>
Vector<T>::Vector() : data(nullptr), capacity(0), size(0) {}

template<typename T>
Vector<T>::Vector(size_t initialCapacity)
    : data(new T[initialCapacity]), capacity(initialCapacity), size(0) {}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
Vector<T>::Vector(const Vector& other)
    : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        data = new T[other.capacity];
        capacity = other.capacity;
        size = other.size;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
void Vector<T>::resize(size_t newCapacity) {
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void Vector<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template<typename T>
void Vector<T>::clear() {
    size = 0;
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
