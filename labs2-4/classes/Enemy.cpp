#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int level, int damage)
    : Character(std::move(name), health, level), damage(damage < 0 ? 0 : damage) {
    std::cout << "Enemy constructor: " << getName() << std::endl;
}

Enemy::~Enemy() {
    std::cout << "Enemy destructor: " << getName() << std::endl;
}

int Enemy::getPower() const {
    return Character::getPower() + damage * 3;
}

void Enemy::printRole() const {
    std::cout << "Role: Enemy" << std::endl;
}
