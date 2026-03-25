#include "made.h"

using namespace std;

// Ініціалізація статичної змінної
int Car::count = 0;

// Конструктор
Car::Car(string model, int year) : model(model), year(year) {
    count++;
}

// Copy constructor
Car::Car(const Car& other) : model(other.model), year(other.year) {
    count++;
}

// Move constructor
Car::Car(Car&& other) noexcept : model(move(other.model)), year(other.year) {
    // При move-конструкторі кількість об'єктів не змінюється (один створюється,
    // але інший зазвичай скоро буде знищений), проте для точності лічильника
    // у складних системах краще враховувати створення нового.
    count++;
}

// const метод[cite: 5]
void Car::show() const {
    cout << model << " " << year << endl;
}

// static метод[cite: 5]
void Car::showCount() {
    cout << "Total cars: " << count << endl;
}

// Оператор +[cite: 5]
Car Car::operator+(const Car& other) const {
    return Car(model + " & " + other.model, (year + other.year) / 2);
}

// Оператор ++ (префіксний)[cite: 5]
Car& Car::operator++() {
    this->year++;
    return *this;
}

// Оператор <<[cite: 5]
ostream& operator<<(ostream& out, const Car& c) {
    out << "Model: " << c.model << ", Year: " << c.year;
    return out;
}

// Оператор >>[cite: 5]
istream& operator>>(istream& in, Car& c) {
    cout << "Enter model: ";
    in >> c.model;
    cout << "Enter year: ";
    in >> c.year;
    return in;
}