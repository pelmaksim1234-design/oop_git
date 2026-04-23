#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int level, int damage)
    : Character(std::move(name), health, level), damage(damage < 0 ? 0 : damage) {
}

Enemy::~Enemy() = default;

int Enemy::getPower() const {
    return Character::getPower() + damage * 3;
}

void Enemy::printRole() const {
    std::cout << "Role: Enemy" << std::endl;
}
