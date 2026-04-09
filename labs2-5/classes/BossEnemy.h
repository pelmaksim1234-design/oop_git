#ifndef BOSS_ENEMY_H
#define BOSS_ENEMY_H

#include "Enemy.h"
#include "AbilityUser.h"

// Task 5: final class demo.
class BossEnemy final : public Enemy, public AbilityUser {
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

    void introduce() const;
    int getPower() const override;
    void printRole() const override;
    // Task 8: interface implementation in a different class.
    std::string getBattleTitle() const override;
    int useAbilityPower() const override;
};

#endif
