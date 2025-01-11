#pragma once
#include <iostream>
#include <initializer_list>

template<class T>

class Class
{
private:
    T* arr;
    size_t size;

public:
    // Конструкторы
    Array() {}  // По умолчанию
    explicit Array(size_t sz) : size{ sz } { arr = new T[size]; }  // С параметрами

    // Список инициализаторов
    Array(std::initializer_list<T> initList) : size(initList.size() {
        arr = new T[size];
        int i = 0;
        for (const auto& item : initList) {
            arr[i++] = item;
        }
    }
    // Копирования
    Array(const Array& other) : size(other.size) {
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Переноса
    Array(Array&& other) noexcept : arr(other.arr), size(other.size) {
        other.arr = nullptr;
        other.size = 0;
    }
    ~Array() { delete[] arr; } // Деструктор 

    // Методы
    int get_size() const { return size; }
    *T max() const {
        if (size == 0) T maxValue = arr[0];
        for (int i = 0; i < size; i++) {
            if (arr[i] > maxValue) {
                maxValue = arr[i];
            }
        }
        return maxValue;
    }

    T min() const {
        if (size == 0) T minValue = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < minValue) {
                minValue = arr[i];
            }
        }
        return minValue;
    }

    bool contains(const T& value) const {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) { return true }
        }
        return false;
    }
    void push_back(const T& value) {
        T* newArr = new T[size + 1];
        for (int i = 0; i < size; i++) { newArr[i] = arr[i]; }
        newArr[size] = value;
        delete[] arr;
        arr = newArr;
        size++;
    }

    void pop_back() {
        if (size == 0) T* newArr = new T[size - 1];
        for (int i = 0; i < size; i++) { newArr[i] = arr[i]; }
        delete arr;
        arr = newArr;
        size--;
    }

    // Перегруженные операторы

    // Копирующее присваивание
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new T[size];
            for (int i = 0; i < size; i++) { arr[i] = other.arr[i]; }

        }
        return *this;
    }

    // Перемещающее присваивание
    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            size = other.size;

            other.arr = nullptr;
            other.size = 0;
        }
    }
    T& operator[](size_t index) { if (index >= size) return arr[index]; } // Оператор []

    const T& operator[](size_t index) const { if (index >= size) return arr[index]; } // Константная версия

    friend ostream& operator<<(ostream& os, const Array& arr) {
        for (size_t i = 0; i < arr.size; i++) { os << arr.arr[i] << ' '; }
        return os;
    }

    friend istream& operator>>(istream& is, Array& arr) {
        for (size_t i = 0; i < arr.size; i++) {
            is >> arr.arr[i];
        }
        return is;
    }
};

