#include "BossEnemy.h"

BossEnemy::BossEnemy(std::string name, int health, int level, int damage, std::string specialSkill)
    : Enemy(std::move(name), health, level, damage), specialSkill(std::move(specialSkill)) {
}

BossEnemy::BossEnemy(const BossEnemy& other)
    : Enemy(other), specialSkill(other.specialSkill) {
}

BossEnemy::BossEnemy(BossEnemy&& other) noexcept
    : Enemy(std::move(other)), specialSkill(std::move(other.specialSkill)) {
}

BossEnemy& BossEnemy::operator=(const BossEnemy& other) {
    if (this != &other) {
        Enemy::operator=(other);
        specialSkill = other.specialSkill;
    }
    return *this;
}

BossEnemy& BossEnemy::operator=(BossEnemy&& other) noexcept {
    if (this != &other) {
        Enemy::operator=(std::move(other));
        specialSkill = std::move(other.specialSkill);
    }
    return *this;
}

BossEnemy::~BossEnemy() = default;

void BossEnemy::introduce() const {
    std::cout << "BossEnemy introduce (hides non-virtual): " << getName() << std::endl;
}

int BossEnemy::getPower() const {
    return Enemy::getPower() + 50;
}

void BossEnemy::printRole() const {
    std::cout << "Role: BossEnemy, skill = " << specialSkill << std::endl;
}

std::string BossEnemy::getBattleTitle() const {
    return "Boss " + getName();
}

int BossEnemy::useAbilityPower() const {
    return getPower() + 25;
}
