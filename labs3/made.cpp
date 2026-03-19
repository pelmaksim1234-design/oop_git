#include "made.h"
#include <iostream>
using namespace std;

// static
int Car::count = 0;

// конструктор
Car::Car(string model, int year) {
    this->model = model;
    this->year = year;
    count++;
}

// copy
Car::Car(const Car& other) {
    model = other.model;
    year = other.year;
    count++;
}

// move
Car::Car(Car&& other) {
    model = move(other.model);
    year = other.year;
}

// const метод
void Car::show() const {
    cout << model << " " << year << endl;
}

// static метод
void Car::showCount() {
    cout << "Count: " << count << endl;
}

// +
Car Car::operator+(const Car& other) {
    return Car(model + "+" + other.model, year);
}

// ++
Car Car::operator++() {
    year++;
    return *this;
}

// <<
ostream& operator<<(ostream& out, const Car& c) {
    out << c.model << " " << c.year;
    return out;
}

// >>
istream& operator>>(istream& in, Car& c) {
    in >> c.model >> c.year;
    return in;
}