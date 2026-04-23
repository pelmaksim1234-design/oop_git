#include "Villager.h"

Villager::Villager(std::string name, std::string profession, int health, int level)
    : Npc(std::move(name), health, level), profession(std::move(profession)) {
}

Villager::~Villager() = default;

void Villager::printRole() const {
    std::cout << "Role: Villager (" << profession << ")" << std::endl;
}

std::string Villager::getDialogue() const {
    return "Welcome to our village. I am a " + profession + ".";
}
