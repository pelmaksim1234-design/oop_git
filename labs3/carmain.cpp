#include <iostream>
#include "made.h"
#include "made.cpp"

using namespace std;

int main() {

    // звичайний об'єкт
    Car a("touran", 2012);

    // 1. Copy constructor
    Car b = a;

    // 2. Move constructor
    Car c = Car("caddy", 2009);

    // 4. const об'єкт
    const Car d("passat", 2012);
    d.show();

    // 5. static
    Car::showCount();

    // 6. оператор +
    Car e = a + c;

    // 6. оператор ++
    ++e;

    // 7. <<
    cout << "e: " << e << endl;

    // 7. >>
    Car f("", 0);
    cout << "Enter car:\n";
    cin >> f;
    cout << "You entered: " << f << endl;

    return 0;
}