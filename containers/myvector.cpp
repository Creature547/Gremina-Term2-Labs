#include "myvector.h"
#include <cstring>

template<>
const int MyVector<char*>::compareItems(char* i, char* j) const {
    return std::strcmp(i, j);
}

template<>
MyVector<char*>::MyVector(char* el) : size(1), capacity(defaultCapacity) {
    pdata = new char*[capacity];
    pdata[0] = new char[std::strlen(el)];
    std::memcpy(pdata[0], el, std::strlen(el));
    pdata[0][std::strlen(el)] = '\0';
}

template<>
MyVector<char*>::MyVector(const MyVector& v) : size(v.size), capacity(v.capacity) {
    pdata = new char*[capacity];
    for (int i = 0; i < size; ++i) {
        pdata[i] = new char[std::strlen(v.pdata[i]) + 1];
        std::memcpy(pdata[i], v.pdata[i], std::strlen(v.pdata[i]));
        pdata[i][std::strlen(v.pdata[i])] = '\0';
    }
}

template<>
MyVector<char*>& MyVector<char*>::operator=(const MyVector<char*>& v) {
    if (this == &v) {
        return *this;
    }
    for (int i = 0; i < size; ++i) {
        delete[] pdata[i];
    }
    delete[] pdata;

    size = v.size;
    capacity = v.capacity;
    pdata = new char*[capacity];

    for (int i = 0; i < size; ++i) {
        pdata[i] = new char[std::strlen(v.pdata[i]) + 1];
        std::strcpy(pdata[i], v.pdata[i]);
    }

    return *this;
}


template<>
MyVector<char*>::~MyVector() {
    for (int i = 0; i < size; ++i) {
        delete pdata[i];
    }
    delete[] pdata;
}

template<>
void MyVector<char*>::add_element(char* el) {
    if (size >= capacity) {
        resize();
    }
    pdata[size] = new char[std::strlen(el) + 1];
    std::memcpy(pdata[size], el, std::strlen(el));
    pdata[size][std::strlen(el)] = '\0';
    size++;
}

template<>
bool MyVector<char*>::delete_element(int i) {
    if (i < 0 || i >= size) {
        return false;
    }

    delete [] pdata[i];
    for (int j = i; j < size - 1; ++j) {
        pdata[j] = pdata[j + 1];
    }
    --size;
    return true;
}
