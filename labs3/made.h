#pragma once
#include <iostream>
#include <string> // Обов'язково для std::string

class Car {
private:
    std::string model;
    int year;
    static int count; // Статичне поле краще тримати в private[cite: 6]

public:
    Car(std::string model = "", int year = 0);

    // 1. Copy constructor
    Car(const Car& other);

    // 2. Move constructor
    Car(Car&& other) noexcept; // Рекомендується додавати noexcept[cite: 6]

    // 4. const метод
    void show() const;

    // 5. static метод
    static void showCount();

    // 6. Оператори
    Car operator+(const Car& other) const;
    Car& operator++(); // Префіксний ++ зазвичай повертає посилання &[cite: 6]

    // 7. Дружні оператори вводу/виводу[cite: 6]
    friend std::ostream& operator<<(std::ostream& out, const Car& c);
    friend std::istream& operator>>(std::istream& in, Car& c);
};