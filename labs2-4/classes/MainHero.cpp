#include "MainHero.h"

MainHero::MainHero(std::string name, int health, int level, int xp, Inventory inventory)
    : Character(std::move(name), health, level), xp(xp < 0 ? 0 : xp), inventory(std::move(inventory)) {
    std::cout << "MainHero constructor: " << this->name << std::endl;
}

MainHero::MainHero(const MainHero& other)
    : Character(other), xp(other.xp), inventory(other.inventory) {
    std::cout << "MainHero copy constructor: " << name << std::endl;
}

MainHero::MainHero(MainHero&& other) noexcept
    : Character(std::move(other)), xp(other.xp), inventory(std::move(other.inventory)) {
    other.xp = 0;
    std::cout << "MainHero move constructor: " << name << std::endl;
}

MainHero& MainHero::operator=(const MainHero& other) {
    if (this != &other) {
        Character::operator=(other);
        xp = other.xp;
        inventory = other.inventory;
    }
    std::cout << "MainHero copy operator=: " << name << std::endl;
    return *this;
}

MainHero& MainHero::operator=(MainHero&& other) noexcept {
    if (this != &other) {
        Character::operator=(std::move(other));
        xp = other.xp;
        inventory = std::move(other.inventory);
        other.xp = 0;
    }
    std::cout << "MainHero move operator=: " << name << std::endl;
    return *this;
}

MainHero::~MainHero() {
    std::cout << "MainHero destructor: " << name << std::endl;
}

int MainHero::getXp() const {
    return xp;
}

const Inventory& MainHero::getInventory() const {
    return inventory;
}

Inventory& MainHero::getInventory() {
    return inventory;
}

MainHero& MainHero::heal(int amount) {
    this->health += amount;
    if (this->health < 0) {
        this->health = 0;
    }
    return *this;
}

MainHero& MainHero::addXp(int amount) {
    xp += amount;
    if (xp < 0) {
        xp = 0;
    }
    return *this;
}

MainHero& MainHero::rename(const std::string& newName) {
    this->name = newName;
    return *this;
}

int MainHero::getPower() const {
    return Character::getPower() + xp + inventory.getItemCount() * 5;
}

void MainHero::printRole() const {
    std::cout << "Role: MainHero" << std::endl;
}

MainHero& MainHero::operator++() {
    ++level;
    xp += 10;
    return *this;
}

int MainHero::operator-(const Character& other) const {
    return getPower() - other.getPower();
}

std::ostream& operator<<(std::ostream& os, const MainHero& hero) {
    os << "Hero{name=" << hero.name
       << ", health=" << hero.health
       << ", level=" << hero.level
       << ", xp=" << hero.xp
       << ", inventory=" << hero.inventory
       << ", id=" << hero.id
       << "}";
    return os;
}

std::istream& operator>>(std::istream& is, MainHero& hero) {
    is >> hero.name >> hero.health >> hero.level >> hero.xp >> hero.inventory;
    if (hero.health < 0) {
        hero.health = 0;
    }
    if (hero.level < 1) {
        hero.level = 1;
    }
    if (hero.xp < 0) {
        hero.xp = 0;
    }
    return is;
}
