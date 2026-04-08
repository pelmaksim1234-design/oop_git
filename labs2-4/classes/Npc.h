#ifndef NPC_H
#define NPC_H

#include "Character.h"

class Npc : public Character {
public:
    Npc(std::string name = "Npc", int health = 70, int level = 1);
    ~Npc() override;

    void printRole() const override;
};

#endif
