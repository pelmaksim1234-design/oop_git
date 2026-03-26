#include "vehicle.h"

#include <utility>

using namespace std;

Weapon::Weapon(string title, int power) : title(std::move(title)), power(power) {
    cout << "[Constructor] Weapon: " << this->title << endl;
}

Weapon::Weapon(const Weapon& other) : title(other.title), power(other.power) {
    cout << "[Copy Constructor] Weapon: " << title << endl;
}

Weapon::Weapon(Weapon&& other) noexcept
    : title(std::move(other.title)), power(other.power) {
    cout << "[Move Constructor] Weapon: " << title << endl;
}

Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        title = other.title;
        power = other.power;
    }
    cout << "[Operator=] Weapon: " << title << endl;
    return *this;
}

Weapon::~Weapon() {
    cout << "[Destructor] Weapon: " << title << endl;
}

void Weapon::show() const {
    cout << "Weapon: " << title << ", Power: " << power;
}

Being::Being(string name) : name(std::move(name)) {
    cout << "[Constructor] Being: " << this->name << endl;
}

Being::Being(const Being& other) : name(other.name) {
    cout << "[Copy Constructor] Being: " << name << endl;
}

Being::Being(Being&& other) noexcept : name(std::move(other.name)) {
    cout << "[Move Constructor] Being: " << name << endl;
}

Being& Being::operator=(const Being& other) {
    if (this != &other) {
        name = other.name;
    }
    cout << "[Operator=] Being: " << name << endl;
    return *this;
}

Being::~Being() {
    cout << "[Destructor] Being: " << name << endl;
}

void Being::show() const {
    cout << "Name: " << name;
}

Character::Character(string name, int health)
    : Being(std::move(name)), health(health) {
    cout << "[Constructor] Character: " << this->name << endl;
}

Character::Character(const Character& other)
    : Being(other), health(other.health) {
    cout << "[Copy Constructor] Character: " << name << endl;
}

Character::Character(Character&& other) noexcept
    : Being(std::move(other)), health(other.health) {
    cout << "[Move Constructor] Character: " << name << endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        Being::operator=(other);
        health = other.health;
    }
    cout << "[Operator=] Character: " << name << endl;
    return *this;
}

Character::~Character() {
    cout << "[Destructor] Character: " << name << endl;
}

void Character::show() const {
    Being::show();
    cout << ", HP: " << health;
}

Hero::Hero(string name, int health, int mana, Weapon weapon)
    : Character(std::move(name), health), mana(mana), weapon(std::move(weapon)) {
    cout << "[Constructor] Hero: " << this->name << endl;
}

Hero::Hero(const Hero& other)
    : Character(other), mana(other.mana), weapon(other.weapon) {
    cout << "[Copy Constructor] Hero: " << name << endl;
}

Hero::Hero(Hero&& other) noexcept
    : Character(std::move(other)), mana(other.mana), weapon(std::move(other.weapon)) {
    cout << "[Move Constructor] Hero: " << name << endl;
}

Hero& Hero::operator=(const Hero& other) {
    if (this != &other) {
        Character::operator=(other);
        mana = other.mana;
        weapon = other.weapon;
    }
    cout << "[Operator=] Hero: " << name << endl;
    return *this;
}

Hero::~Hero() {
    cout << "[Destructor] Hero: " << name << endl;
}

void Hero::show() const {
    Character::show();
    cout << ", Mana: " << mana << ", ";
    weapon.show();
}

Warrior::Warrior(string name, int health, int mana, Weapon weapon, int armor)
    : Hero(std::move(name), health, mana, std::move(weapon)), armor(armor) {
    cout << "[Constructor] Warrior: " << this->name << endl;
}

Warrior::Warrior(const Warrior& other)
    : Hero(other), armor(other.armor) {
    cout << "[Copy Constructor] Warrior: " << name << endl;
}

Warrior::Warrior(Warrior&& other) noexcept
    : Hero(std::move(other)), armor(other.armor) {
    cout << "[Move Constructor] Warrior: " << name << endl;
}

Warrior& Warrior::operator=(const Warrior& other) {
    if (this != &other) {
        Hero::operator=(other);
        armor = other.armor;
    }
    cout << "[Operator=] Warrior: " << name << endl;
    return *this;
}

Warrior::~Warrior() {
    cout << "[Destructor] Warrior: " << name << endl;
}

void Warrior::show() const {
    Hero::show();
    cout << ", Armor: " << armor;
}

Knight::Knight(string name, int health, int mana, Weapon weapon, int armor,
               string orderName)
    : Warrior(std::move(name), health, mana, std::move(weapon), armor),
      orderName(std::move(orderName)) {
    cout << "[Constructor] Knight: " << this->name << endl;
}

Knight::~Knight() {
    cout << "[Destructor] Knight: " << name << endl;
}

void Knight::show() const {
    Warrior::show();
    cout << ", Order: " << orderName;
}

Enemy::Enemy(string name, int health, int damage)
    : Character(std::move(name), health), damage(damage) {
    cout << "[Constructor] Enemy: " << this->name << endl;
}

Enemy::~Enemy() {
    cout << "[Destructor] Enemy: " << name << endl;
}

void Enemy::show() const {
    Character::show();
    cout << ", Damage: " << damage;
}

Boss::Boss(string name, int health, int damage, int rageLevel)
    : Enemy(std::move(name), health, damage), rageLevel(rageLevel) {
    cout << "[Constructor] Boss: " << this->name << endl;
}

Boss::~Boss() {
    cout << "[Destructor] Boss: " << name << endl;
}

void Boss::show() const {
    Enemy::show();
    cout << ", Rage level: " << rageLevel;
}

void Squad::addMember(Being* member) {
    members.push_back(member);
}

void Squad::showAll() const {
    for (const auto member : members) {
        member->show();
        cout << endl;
    }
}

Squad::~Squad() {
    cout << "--- Clearing Squad ---" << endl;
    for (auto member : members) {
        delete member;
    }
    members.clear();
}
