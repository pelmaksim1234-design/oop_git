#include "WarriorHero.h"

WarriorHero::WarriorHero(std::string name, int health, int level, int xp, Inventory inventory, int armor)
    : MainHero(std::move(name), health, level, xp, std::move(inventory)), armor(armor < 0 ? 0 : armor) {
}

WarriorHero::WarriorHero(const WarriorHero& other)
    : MainHero(other), armor(other.armor) {
}

WarriorHero::WarriorHero(WarriorHero&& other) noexcept
    : MainHero(std::move(other)), armor(other.armor) {
    other.armor = 0;
}

WarriorHero& WarriorHero::operator=(const WarriorHero& other) {
    if (this != &other) {
        MainHero::operator=(other);
        armor = other.armor;
    }
    return *this;
}

WarriorHero& WarriorHero::operator=(WarriorHero&& other) noexcept {
    if (this != &other) {
        MainHero::operator=(std::move(other));
        armor = other.armor;
        other.armor = 0;
    }
    return *this;
}

WarriorHero::~WarriorHero() = default;

int WarriorHero::getPower() const {
    return MainHero::getPower() + armor * 2;
}

void WarriorHero::printRole() const {
    std::cout << "Role: WarriorHero" << std::endl;
}
