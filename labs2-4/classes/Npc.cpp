#include "Npc.h"

Npc::Npc(std::string name, int health, int level)
    : Character(std::move(name), health, level) {
    std::cout << "Npc constructor: " << getName() << std::endl;
}

Npc::~Npc() {
    std::cout << "Npc destructor: " << getName() << std::endl;
}

void Npc::printRole() const {
    std::cout << "Role: Npc" << std::endl;
}
