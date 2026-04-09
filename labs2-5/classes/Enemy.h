#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
protected:
    int damage;

public:
    Enemy(std::string name = "Enemy", int health = 90, int level = 1, int damage = 15);
    ~Enemy() override;

    int getPower() const override;
    void printRole() const override;
};

#endif
