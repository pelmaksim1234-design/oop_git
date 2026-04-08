#ifndef BOSS_ENEMY_H
#define BOSS_ENEMY_H

#include "Enemy.h"

class BossEnemy : public Enemy {
private:
    std::string specialSkill;

public:
    BossEnemy(std::string name = "Boss", int health = 200, int level = 5, int damage = 40,
              std::string specialSkill = "Meteor");
    BossEnemy(const BossEnemy& other);
    BossEnemy(BossEnemy&& other) noexcept;
    BossEnemy& operator=(const BossEnemy& other);
    BossEnemy& operator=(BossEnemy&& other) noexcept;
    ~BossEnemy() override;

    int getPower() const override;
    void printRole() const override;
};

#endif
