#include "Character.h"

int Character::nextId = 1;
int Character::objectCount = 0;

Character::Character(std::string name, int health, int level)
    : name(std::move(name)), health(health < 0 ? 0 : health), level(level < 1 ? 1 : level), id(nextId++) {
    ++objectCount;
    std::cout << "Character constructor: " << this->name << ", id = " << id << std::endl;
}

Character::Character(const Character& other)
    : name(other.name), health(other.health), level(other.level), id(nextId++) {
    ++objectCount;
    std::cout << "Character copy constructor: " << name << ", new id = " << id << std::endl;
}

Character::Character(Character&& other) noexcept
    : name(std::move(other.name)), health(other.health), level(other.level), id(nextId++) {
    ++objectCount;
    other.health = 0;
    other.level = 1;
    std::cout << "Character move constructor: " << name << ", new id = " << id << std::endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        health = other.health;
        level = other.level;
    }
    std::cout << "Character copy operator=: " << name << ", id = " << id << std::endl;
    return *this;
}

Character& Character::operator=(Character&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        health = other.health;
        level = other.level;
        other.health = 0;
        other.level = 1;
    }
    std::cout << "Character move operator=: " << name << ", id = " << id << std::endl;
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor: " << name << ", id = " << id << std::endl;
    --objectCount;
}

const std::string& Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getLevel() const {
    return level;
}

int Character::getId() const {
    return id;
}

void Character::setHealth(int newHealth) {
    health = newHealth < 0 ? 0 : newHealth;
}

void Character::levelUp() {
    ++level;
}

int Character::getPower() const {
    return health + level * 10;
}

void Character::printRole() const {
    std::cout << "Character role: base character" << std::endl;
}

int Character::getObjectCount() {
    return objectCount;
}

void Character::printObjectCount() {
    std::cout << "Static object count = " << objectCount << std::endl;
}
