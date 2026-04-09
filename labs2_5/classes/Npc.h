#ifndef NPC_H
#define NPC_H

#include "Character.h"

class Npc : public Character {
public:
    Npc(std::string name = "Npc", int health = 70, int level = 1);
    ~Npc() override;

    void printRole() const override;
    // Task 7: pure virtual function in a regular class.
    virtual std::string getDialogue() const = 0;
};

#endif
