#pragma once

#include <cstring>
#include <iostream>

namespace {
const size_t kDefaultVectorCapacity = 5;
const size_t kGrowthFactor = 2;
const size_t kDecreaseFactor = 4;

size_t getNeededSize(size_t size, size_t capacity) {
    if (size >= capacity) {
        return capacity * kGrowthFactor;
    } else if (size < capacity / kDecreaseFactor) {
        return std::max(capacity / kGrowthFactor, kDefaultVectorCapacity);
    }

    return size;
}

}  // namespace

template<typename T>
class MyVector {
 protected:
    size_t capacity;
    size_t size;
    T* ptr;

    void resize(size_t newCapacity) {
        if (!ptr) {
            throw std::runtime_error("invalid vector");
        }

        capacity = newCapacity;
        T* buffer = new T[capacity];
        std::copy(ptr, ptr + size, buffer);
        delete[] ptr;
        ptr = buffer;
    }

 public:
    MyVector(size_t capacity = kDefaultVectorCapacity) : capacity(capacity), size(0), ptr(new T[capacity]) {}

    MyVector(const T element, size_t capacity = kDefaultVectorCapacity) : capacity(capacity), size(1), ptr(new T[capacity]) { ptr[0] = element; }

    virtual ~MyVector() { delete[] ptr; }

    MyVector(const MyVector& other) : capacity(other.capacity), size(other.size), ptr(new T[capacity]) {
        std::copy(other.ptr, other.ptr + size, ptr);
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] ptr;
            capacity = other.capacity;
            size = other.size;
            ptr = new T[capacity];
            std::copy(other.ptr, other.ptr + size, ptr);
        }
        return *this;
    }

    void add_element(T element) {
        size_t neededSize = getNeededSize(size, capacity);
        if (size != neededSize) {
            resize(neededSize);
        }
        ptr[size++] = element;
    }

    bool delete_element(size_t index) {
        if (!ptr || index >= size) {
            return false;
        }
        for (size_t i = index; i < size - 1; ++i) {
            ptr[i] = ptr[i + 1];
        }
        size--;
        size_t neededSize = getNeededSize(size, capacity);
        if (size != neededSize) {
            resize(neededSize);
        }
        return true;
    }

    T& operator[](size_t index) {
        if (!ptr)
            throw std::runtime_error("invalid vector");
        if (index >= size)
            throw std::runtime_error("index out of range");
        return ptr[index];
    }

    const T& operator[](size_t index) const {
        if (!ptr)
            throw std::runtime_error("invalid vector");
        if (index >= size)
            throw std::runtime_error("index out of range");
        return ptr[index];
    }

    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }

    int find(T element) const {
        for (size_t i = 0; i < size; ++i) {
            if (ptr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void sort() {
        if (!ptr) {
            throw std::runtime_error("invalid vector");
        }
        if (size <= 1) {
            return;
        }
        for (size_t i = 0; i < size - 1; ++i) {
            size_t swappingElementIndex = i;
            for (size_t j = i + 1; j < size; ++j) {
                if (ptr[j] < ptr[swappingElementIndex]) {
                    swappingElementIndex = j;
                }
            }
            if (i != swappingElementIndex) {
                std::swap(ptr[i], ptr[swappingElementIndex]);
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const MyVector<T>& vector) {
        if (!vector.ptr) {
            throw std::runtime_error("invalid vector");
        }
        out << '{';
        if (vector.size != 0) {
            for (size_t i = 0; i < vector.size - 1; ++i) {
                out << vector.ptr[i] << ", ";
            }
            out << vector.ptr[vector.size - 1];
        }
        return out << '}';
    }
};

template<>
inline MyVector<char*>::MyVector(char* element, size_t capacity) : capacity(capacity), size(0), ptr(new char*[capacity]) {
    if (element) {
        ptr[0] = new char[std::strlen(element) + 1];
        std::strcpy(ptr[0], element);
        size = 1;
    }
}

template<>
inline MyVector<char*>::~MyVector() {
    for (size_t i = 0; i < size; ++i) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

template<>
inline MyVector<char*>::MyVector(const MyVector& other) : capacity(other.capacity), size(other.size), ptr(new char*[capacity]) {
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = new char[std::strlen(other[i]) + 1];
        std::strcpy(ptr[i], other.ptr[i]);
    }
}

template<>
inline MyVector<char*>& MyVector<char*>::operator=(const MyVector& other) {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete[] ptr[i];
        }
        delete[] ptr;
        capacity = other.capacity;
        size = other.size;
        ptr = new char*[capacity];
        for (size_t i = 0; i < size; ++i) {
            ptr[i] = new char[strlen(other.ptr[i]) + 1];
            strcpy(ptr[i], other.ptr[i]);
        }
    }
    return *this;
}

template<>
inline bool MyVector<char*>::delete_element(size_t index) {
    if (!ptr || index >= size) {
        return false;
    }
    delete[] ptr[index];
    for (size_t i = index; i < size - 1; ++i) {
        ptr[i] = ptr[i + 1];
    }
    --size;
    size_t neededSize = getNeededSize(size, capacity);
    if (size != neededSize) {
        resize(neededSize);
    }
    return true;
}

template<>
inline void MyVector<char*>::add_element(char* element) {
    if (!element) {
        return;
    }
    size_t neededSize = getNeededSize(size, capacity);
    if (size != neededSize) {
        resize(neededSize);
    }
    ptr[size] = new char[std::strlen(element) + 1];
    std::strcpy(ptr[size++], element);
}

template<>
inline void MyVector<char*>::sort() {
    if (!ptr || size <= 1) {
        return;
    }
    for (size_t i = 0; i < size - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (std::strcmp(ptr[j], ptr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(ptr[i], ptr[min_idx]);
        }
    }
}

MyVector(const char*) -> MyVector<char*>;
