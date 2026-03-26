#include "made.h"

#include <utility>

using namespace std;

int Character::count = 0;

Character::Character(string name, int health, int level)
    : name(std::move(name)), health(health), level(level) {
    count++;
}

Character::Character(const Character& other)
    : name(other.name), health(other.health), level(other.level) {
    count++;
}

Character::Character(Character&& other) noexcept
    : name(std::move(other.name)), health(other.health), level(other.level) {
    count++;
}

Character& Character::train(int gainedLevels) {
    this->level += gainedLevels;
    this->health += gainedLevels * 5;
    return *this;
}

void Character::show() const {
    cout << "Character: " << name
         << ", HP: " << health
         << ", Level: " << level << endl;
}

const string& Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getLevel() const {
    return level;
}

void Character::showCount() {
    cout << "Created characters: " << count << endl;
}

Character Character::operator+(const Character& other) const {
    return Character(
        name + "-" + other.name,
        (health + other.health) / 2,
        (level + other.level) / 2
    );
}

Character& Character::operator++() {
    ++level;
    health += 10;
    return *this;
}

ostream& operator<<(ostream& out, const Character& character) {
    out << "Name: " << character.name
        << ", HP: " << character.health
        << ", Level: " << character.level;
    return out;
}

istream& operator>>(istream& in, Character& character) {
    cout << "Enter name: ";
    in >> character.name;
    cout << "Enter health: ";
    in >> character.health;
    cout << "Enter level: ";
    in >> character.level;
    return in;
}
