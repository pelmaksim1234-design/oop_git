#include "BossEnemy.h"

BossEnemy::BossEnemy(std::string name, int health, int level, int damage, std::string specialSkill)
    : Enemy(std::move(name), health, level, damage), specialSkill(std::move(specialSkill)) {
    std::cout << "BossEnemy constructor: " << getName() << std::endl;
}

BossEnemy::~BossEnemy() {
    std::cout << "BossEnemy destructor: " << getName() << std::endl;
}

int BossEnemy::getPower() const {
    return Enemy::getPower() + 50;
}

void BossEnemy::printRole() const {
    std::cout << "Role: BossEnemy, skill = " << specialSkill << std::endl;
}
