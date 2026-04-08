#include "WarriorHero.h"

WarriorHero::WarriorHero(std::string name, int health, int level, int xp, Inventory inventory, int armor)
    : MainHero(std::move(name), health, level, xp, std::move(inventory)), armor(armor < 0 ? 0 : armor) {
    std::cout << "WarriorHero constructor: " << getName() << std::endl;
}

WarriorHero::WarriorHero(const WarriorHero& other)
    : MainHero(other), armor(other.armor) {
    std::cout << "WarriorHero copy constructor: " << getName() << std::endl;
}

WarriorHero::WarriorHero(WarriorHero&& other) noexcept
    : MainHero(std::move(other)), armor(other.armor) {
    other.armor = 0;
    std::cout << "WarriorHero move constructor: " << getName() << std::endl;
}

WarriorHero& WarriorHero::operator=(const WarriorHero& other) {
    if (this != &other) {
        MainHero::operator=(other);
        armor = other.armor;
    }
    std::cout << "WarriorHero copy operator=: " << getName() << std::endl;
    return *this;
}

WarriorHero& WarriorHero::operator=(WarriorHero&& other) noexcept {
    if (this != &other) {
        MainHero::operator=(std::move(other));
        armor = other.armor;
        other.armor = 0;
    }
    std::cout << "WarriorHero move operator=: " << getName() << std::endl;
    return *this;
}

WarriorHero::~WarriorHero() {
    std::cout << "WarriorHero destructor: " << getName() << std::endl;
}

int WarriorHero::getPower() const {
    return MainHero::getPower() + armor * 2;
}

void WarriorHero::printRole() const {
    std::cout << "Role: WarriorHero" << std::endl;
}
