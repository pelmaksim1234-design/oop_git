#include "Villager.h"

Villager::Villager(std::string name, std::string profession, int health, int level)
    : Npc(std::move(name), health, level), profession(std::move(profession)) {
    std::cout << "Villager constructor: " << getName() << std::endl;
}

Villager::~Villager() {
    std::cout << "Villager destructor: " << getName() << std::endl;
}

void Villager::printRole() const {
    std::cout << "Role: Villager (" << profession << ")" << std::endl;
}

std::string Villager::interact() const {
    return "Villager " + getName() + " says: I can trade as a " + profession + '.';
}
