#ifndef WARRIOR_HERO_H
#define WARRIOR_HERO_H

#include "MainHero.h"

class WarriorHero : public MainHero {
private:
    int armor;

public:
    WarriorHero(std::string name = "Warrior", int health = 150, int level = 1, int xp = 0,
                Inventory inventory = Inventory("Sword", 1), int armor = 20);
    WarriorHero(const WarriorHero& other);
    WarriorHero(WarriorHero&& other) noexcept;
    WarriorHero& operator=(const WarriorHero& other);
    WarriorHero& operator=(WarriorHero&& other) noexcept;
    ~WarriorHero() override;

    int getPower() const override;
    // Task 5: final method demo.
    void printRole() const final;
};

#endif
