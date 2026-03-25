#pragma once

#include <iostream>
#include <string>
#include <vector>

class Vehicle {
protected:
    std::string model;
    int year;

public:
    Vehicle(std::string m = "Unknown", int y = 0);
    virtual ~Vehicle();

    virtual void show() const;

    Vehicle(const Vehicle& other);
    Vehicle(Vehicle&& other) noexcept;
    Vehicle& operator=(const Vehicle& other);
};

class Car : public Vehicle {
    int doors;

public:
    Car(std::string m = "Unknown", int y = 0, int d = 4);
    void show() const override;

    Car(const Car& other);
    Car(Car&& other) noexcept;
    Car& operator=(const Car& other);
};

class ElectricCar : public Car {
    int battery;

public:
    ElectricCar(std::string m, int y, int d, int b);
    void show() const override;
};

class Garage {
    std::vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* v);
    void showAll() const;
    ~Garage();
};
