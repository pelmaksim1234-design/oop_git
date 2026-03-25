#include "vehicle.h"

using namespace std;

Vehicle::Vehicle(string m, int y) : model(m), year(y) {
    cout << "[Constructor] Vehicle: " << model << endl;
}

Vehicle::~Vehicle() {
    cout << "[Destructor] Vehicle: " << model << endl;
}

void Vehicle::show() const {
    cout << "Model: " << model << ", Year: " << year;
}

Vehicle::Vehicle(const Vehicle& other) : model(other.model), year(other.year) {}

Vehicle::Vehicle(Vehicle&& other) noexcept : model(move(other.model)), year(other.year) {}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        model = other.model;
        year = other.year;
    }
    return *this;
}

Car::Car(string m, int y, int d) : Vehicle(m, y), doors(d) {
    cout << "[Constructor] Car: " << model << " with " << doors << " doors" << endl;
}

void Car::show() const {
    Vehicle::show();
    cout << ", Doors: " << doors;
}

Car::Car(const Car& other) : Vehicle(other), doors(other.doors) {}

Car::Car(Car&& other) noexcept : Vehicle(move(other)), doors(other.doors) {}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        doors = other.doors;
    }
    return *this;
}

ElectricCar::ElectricCar(string m, int y, int d, int b) : Car(m, y, d), battery(b) {
    cout << "[Constructor] ElectricCar: " << model << " (" << battery << " kWh)" << endl;
}

void ElectricCar::show() const {
    Car::show();
    cout << ", Battery: " << battery << " kWh" << endl;
}

void Garage::addVehicle(Vehicle* v) {
    vehicles.push_back(v);
}

void Garage::showAll() const {
    for (const auto v : vehicles) {
        v->show();
        cout << endl;
    }
}

Garage::~Garage() {
    cout << "--- Clearing Garage ---" << endl;
    for (auto v : vehicles) {
        delete v;
    }
    vehicles.clear();
}
