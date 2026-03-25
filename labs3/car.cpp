#include <iostream>
#include "made.h"

using namespace std;

int main() {
    // Звичайний об'єкт[cite: 4]
    Car a("Touran", 2009);

    // 1. Copy constructor[cite: 4]
    Car b = a;

    // 2. Move constructor[cite: 4]
    Car c = Car("Caddy", 2009);

    // 4. const об'єкт[cite: 4]
    const Car d("Passat", 2012);
    d.show();

    // 5. static[cite: 4]
    Car::showCount();

    // 6. Оператор +[cite: 4]
    Car e = a + c;

    // 6. Оператор ++[cite: 4]
    ++e;

    // 7. Вивід[cite: 4]
    cout << "Car E after ++: " << e << endl;

    // 7. Ввід[cite: 4]
    Car f;
    cin >> f;
    cout << "New car added: " << f << endl;

    Car::showCount();

    return 0;
}