#ifndef VILLAGER_H
#define VILLAGER_H

#include "Npc.h"

class Villager final : public Npc {
private:
    std::string profession;

public:
    Villager(std::string name = "Villager", std::string profession = "Farmer", int health = 60, int level = 1);
    ~Villager() override;

    void printRole() const override;
    std::string interact() const override;
};

#endif
