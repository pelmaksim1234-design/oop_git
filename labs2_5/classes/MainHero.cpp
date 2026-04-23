#include "MainHero.h"

#include "GameExceptions.h"

MainHero::MainHero(std::string name, int health, int level, int xp, Inventory inventory)
    : Character(std::move(name), health, level), xp(xp), inventory(std::move(inventory)) {
    if (this->xp < 0) {
        throw InvalidCharacterState("Hero XP cannot be negative.");
    }
}

MainHero::MainHero(const MainHero& other)
    : Character(other), xp(other.xp), inventory(other.inventory) {
}

MainHero::MainHero(MainHero&& other) noexcept
    : Character(std::move(other)), xp(other.xp), inventory(std::move(other.inventory)) {
    other.xp = 0;
}

MainHero& MainHero::operator=(const MainHero& other) {
    if (this != &other) {
        if (other.xp < 0) {
            throw InvalidCharacterState("Hero XP cannot be negative.");
        }
        Character::operator=(other);
        xp = other.xp;
        inventory = other.inventory;
    }
    return *this;
}

MainHero& MainHero::operator=(MainHero&& other) noexcept {
    if (this != &other) {
        Character::operator=(std::move(other));
        xp = other.xp;
        inventory = std::move(other.inventory);
        other.xp = 0;
    }
    return *this;
}

MainHero::~MainHero() = default;

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
    if (amount < 0) {
        throw InvalidCharacterState("Heal amount cannot be negative.");
    }
    this->health += amount;
    return *this;
}

MainHero& MainHero::addXp(int amount) {
    if (amount < 0) {
        throw InvalidCharacterState("XP increment cannot be negative.");
    }
    xp += amount;
    return *this;
}

MainHero& MainHero::rename(const std::string& newName) {
    if (newName.empty()) {
        throw InvalidCharacterState("Hero name cannot be empty.");
    }
    this->name = newName;
    return *this;
}

void MainHero::introduce() const {
    std::cout << "MainHero introduce (hides non-virtual): " << name << std::endl;
}

int MainHero::getPower() const {
    return Character::getPower() + xp + inventory.getItemCount() * 5;
}

void MainHero::printRole() const {
    std::cout << "Role: MainHero" << std::endl;
}

std::string MainHero::getBattleTitle() const {
    return "Hero " + name;
}

int MainHero::useAbilityPower() const {
    return getPower() + xp / 2;
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
    std::string newName;
    int newHealth = 0;
    int newLevel = 0;
    int newXp = 0;
    Inventory newInventory;

    is >> newName >> newHealth >> newLevel >> newXp >> newInventory;
    if (!is) {
        throw InvalidCharacterState("Failed to read hero from stream.");
    }
    if (newName.empty()) {
        throw InvalidCharacterState("Hero name cannot be empty.");
    }
    if (newHealth < 0) {
        throw InvalidCharacterState("Hero health cannot be negative.");
    }
    if (newLevel < 1) {
        throw InvalidCharacterState("Hero level must be at least 1.");
    }
    if (newXp < 0) {
        throw InvalidCharacterState("Hero XP cannot be negative.");
    }

    hero.name = std::move(newName);
    hero.health = newHealth;
    hero.level = newLevel;
    hero.xp = newXp;
    hero.inventory = std::move(newInventory);
    return is;
}
