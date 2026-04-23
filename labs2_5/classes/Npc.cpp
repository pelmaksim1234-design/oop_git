#include "Npc.h"

Npc::Npc(std::string name, int health, int level)
    : Character(std::move(name), health, level) {
}

Npc::~Npc() = default;

void Npc::printRole() const {
    std::cout << "Role: Npc" << std::endl;
}
