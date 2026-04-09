#include "BossEnemy.h"

BossEnemy::BossEnemy(std::string name, int health, int level, int damage, std::string specialSkill)
    : Enemy(std::move(name), health, level, damage), specialSkill(std::move(specialSkill)) {
    std::cout << "BossEnemy constructor: " << getName() << std::endl;
}

BossEnemy::BossEnemy(const BossEnemy& other)
    : Enemy(other), specialSkill(other.specialSkill) {
    std::cout << "BossEnemy copy constructor: " << getName() << std::endl;
}

BossEnemy::BossEnemy(BossEnemy&& other) noexcept
    : Enemy(std::move(other)), specialSkill(std::move(other.specialSkill)) {
    std::cout << "BossEnemy move constructor: " << getName() << std::endl;
}

BossEnemy& BossEnemy::operator=(const BossEnemy& other) {
    if (this != &other) {
        Enemy::operator=(other);
        specialSkill = other.specialSkill;
    }
    std::cout << "BossEnemy copy operator=: " << getName() << std::endl;
    return *this;
}

BossEnemy& BossEnemy::operator=(BossEnemy&& other) noexcept {
    if (this != &other) {
        Enemy::operator=(std::move(other));
        specialSkill = std::move(other.specialSkill);
    }
    std::cout << "BossEnemy move operator=: " << getName() << std::endl;
    return *this;
}

BossEnemy::~BossEnemy() {
    std::cout << "BossEnemy destructor: " << getName() << std::endl;
}

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
