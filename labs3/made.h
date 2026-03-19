#pragma once
#include <iostream>
using namespace std;

class Car {
private:
    string model;
    int year;

public:
    Car(string model, int year);

    // 1. Copy constructor
    Car(const Car& other);

    // 2. Move constructor
    Car(Car&& other);

    // 4. const метод
    void show() const;

    // 5. static
    static int count;
    static void showCount();

    // оператори
    Car operator+(const Car& other);
    Car operator++();

    friend ostream& operator<<(ostream& out, const Car& c);
    friend istream& operator>>(istream& in, Car& c);
};