#include "vehicle.h"

#include <iostream>

int main() {
    Garage g;

    Car* c1 = new Car("Caddy", 2009);
    ElectricCar* c2 = new ElectricCar("Tesla", 2022, 4, 100);

    g.addVehicle(c1);
    g.addVehicle(c2);

    std::cout << "\n--- Garage contains: ---\n";
    g.showAll();
    std::cout << "------------------------\n";

    return 0;
}
