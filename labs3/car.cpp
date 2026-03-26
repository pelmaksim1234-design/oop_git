#include <iostream>
#include <utility>

#include "made.h"

using namespace std;

int main() {
    Character hero("Andriy", 120, 5);

    Character copyHero = hero;
    Character tempHero("Master", 180, 9);
    Character movedHero = std::move(tempHero);

    hero.train(2);
    cout << "After train() with this pointer: " << hero << endl;

    const Character support("Healer", 90, 4);
    support.show();
    cout << "Const character name: " << support.getName()
         << ", level: " << support.getLevel() << endl;

    Character::showCount();

    Character squadLeader = hero + movedHero;
    ++squadLeader;

    cout << "Combined character after level up: " << squadLeader << endl;
    cout << "Copied character: " << copyHero << endl;

    Character newHero;
    cin >> newHero;
    cout << "New character: " << newHero << endl;

    Character::showCount();

    return 0;
}
