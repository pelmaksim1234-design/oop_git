#include "Characters1.h"

int Character::nextId = 1;
int Character::objectCount = 0;

Inventory::Inventory(std::string item, int itemCount)
    : item(std::move(item)), itemCount(itemCount < 0 ? 0 : itemCount) {
    std::cout << "Inventory created: " << this->item << " x" << this->itemCount << std::endl;
}

Inventory::~Inventory() {
    std::cout << "Inventory destroyed for item: " << item << std::endl;
}

const std::string& Inventory::getItem() const {
    return item;
}

int Inventory::getItemCount() const {
    return itemCount;
}

void Inventory::setItem(const std::string& newItem) {
    item = newItem;
}

void Inventory::setItemCount(int newCount) {
    itemCount = newCount < 0 ? 0 : newCount;
}

std::ostream& operator<<(std::ostream& os, const Inventory& inventory) {
    os << inventory.item << ' ' << inventory.itemCount;
    return os;
}

std::istream& operator>>(std::istream& is, Inventory& inventory) {
    is >> inventory.item >> inventory.itemCount;
    if (inventory.itemCount < 0) {
        inventory.itemCount = 0;
    }
    return is;
}

Character::Character(std::string name, int health, int level)
    : name(std::move(name)), health(health < 0 ? 0 : health), level(level < 1 ? 1 : level), id(nextId++) {
    ++objectCount;
    std::cout << "Character constructor: " << this->name << ", id = " << id << std::endl;
}

Character::Character(const Character& other)
    : name(other.name), health(other.health), level(other.level), id(nextId++) {
    ++objectCount;
    std::cout << "Character copy constructor: " << name << ", new id = " << id << std::endl;
}

Character::Character(Character&& other) noexcept
    : name(std::move(other.name)), health(other.health), level(other.level), id(nextId++) {
    ++objectCount;
    other.health = 0;
    other.level = 1;
    std::cout << "Character move constructor: " << name << ", new id = " << id << std::endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        health = other.health;
        level = other.level;
    }
    std::cout << "Character copy operator=: " << name << ", id = " << id << std::endl;
    return *this;
}

Character& Character::operator=(Character&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        health = other.health;
        level = other.level;
        other.health = 0;
        other.level = 1;
    }
    std::cout << "Character move operator=: " << name << ", id = " << id << std::endl;
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor: " << name << ", id = " << id << std::endl;
    --objectCount;
}

const std::string& Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getLevel() const {
    return level;
}

int Character::getId() const {
    return id;
}

void Character::setHealth(int newHealth) {
    health = newHealth < 0 ? 0 : newHealth;
}

void Character::levelUp() {
    ++level;
}

int Character::getPower() const {
    return health + level * 10;
}

void Character::printRole() const {
    std::cout << "Character role: base character" << std::endl;
}

int Character::getObjectCount() {
    return objectCount;
}

void Character::printObjectCount() {
    std::cout << "Static object count = " << objectCount << std::endl;
}

MainHero::MainHero(std::string name, int health, int level, int xp, Inventory inventory)
    : Character(std::move(name), health, level), xp(xp < 0 ? 0 : xp), inventory(std::move(inventory)) {
    std::cout << "MainHero constructor: " << this->name << std::endl;
}

MainHero::MainHero(const MainHero& other)
    : Character(other), xp(other.xp), inventory(other.inventory) {
    std::cout << "MainHero copy constructor: " << name << std::endl;
}

MainHero::MainHero(MainHero&& other) noexcept
    : Character(std::move(other)), xp(other.xp), inventory(std::move(other.inventory)) {
    other.xp = 0;
    std::cout << "MainHero move constructor: " << name << std::endl;
}

MainHero& MainHero::operator=(const MainHero& other) {
    if (this != &other) {
        Character::operator=(other);
        xp = other.xp;
        inventory = other.inventory;
    }
    std::cout << "MainHero copy operator=: " << name << std::endl;
    return *this;
}

MainHero& MainHero::operator=(MainHero&& other) noexcept {
    if (this != &other) {
        Character::operator=(std::move(other));
        xp = other.xp;
        inventory = std::move(other.inventory);
        other.xp = 0;
    }
    std::cout << "MainHero move operator=: " << name << std::endl;
    return *this;
}

MainHero::~MainHero() {
    std::cout << "MainHero destructor: " << name << std::endl;
}

int MainHero::getXp() const {
    return xp;
}

const Inventory& MainHero::getInventory() const {
    return inventory;
}

Inventory& MainHero::getInventory() {
    return inventory;
}

MainHero& MainHero::heal(int amount) {
    this->health += amount;
    if (this->health < 0) {
        this->health = 0;
    }
    return *this;
}

MainHero& MainHero::addXp(int amount) {
    xp += amount;
    if (xp < 0) {
        xp = 0;
    }
    return *this;
}

MainHero& MainHero::rename(const std::string& newName) {
    this->name = newName;
    return *this;
}

int MainHero::getPower() const {
    return Character::getPower() + xp + inventory.getItemCount() * 5;
}

void MainHero::printRole() const {
    std::cout << "Role: MainHero" << std::endl;
}

MainHero& MainHero::operator++() {
    ++level;
    xp += 10;
    return *this;
}

int MainHero::operator-(const Character& other) const {
    return getPower() - other.getPower();
}

std::ostream& operator<<(std::ostream& os, const MainHero& hero) {
    os << "Hero{name=" << hero.name
       << ", health=" << hero.health
       << ", level=" << hero.level
       << ", xp=" << hero.xp
       << ", inventory=" << hero.inventory
       << ", id=" << hero.id
       << "}";
    return os;
}

std::istream& operator>>(std::istream& is, MainHero& hero) {
    is >> hero.name >> hero.health >> hero.level >> hero.xp >> hero.inventory;
    if (hero.health < 0) {
        hero.health = 0;
    }
    if (hero.level < 1) {
        hero.level = 1;
    }
    if (hero.xp < 0) {
        hero.xp = 0;
    }
    return is;
}

WarriorHero::WarriorHero(std::string name, int health, int level, int xp, Inventory inventory, int armor)
    : MainHero(std::move(name), health, level, xp, std::move(inventory)), armor(armor < 0 ? 0 : armor) {
    std::cout << "WarriorHero constructor: " << getName() << std::endl;
}

WarriorHero::WarriorHero(const WarriorHero& other)
    : MainHero(other), armor(other.armor) {
    std::cout << "WarriorHero copy constructor: " << getName() << std::endl;
}

WarriorHero::WarriorHero(WarriorHero&& other) noexcept
    : MainHero(std::move(other)), armor(other.armor) {
    other.armor = 0;
    std::cout << "WarriorHero move constructor: " << getName() << std::endl;
}

WarriorHero& WarriorHero::operator=(const WarriorHero& other) {
    if (this != &other) {
        MainHero::operator=(other);
        armor = other.armor;
    }
    std::cout << "WarriorHero copy operator=: " << getName() << std::endl;
    return *this;
}

WarriorHero& WarriorHero::operator=(WarriorHero&& other) noexcept {
    if (this != &other) {
        MainHero::operator=(std::move(other));
        armor = other.armor;
        other.armor = 0;
    }
    std::cout << "WarriorHero move operator=: " << getName() << std::endl;
    return *this;
}

WarriorHero::~WarriorHero() {
    std::cout << "WarriorHero destructor: " << getName() << std::endl;
}

int WarriorHero::getPower() const {
    return MainHero::getPower() + armor * 2;
}

void WarriorHero::printRole() const {
    std::cout << "Role: WarriorHero" << std::endl;
}

Npc::Npc(std::string name, int health, int level)
    : Character(std::move(name), health, level) {
    std::cout << "Npc constructor: " << getName() << std::endl;
}

Npc::~Npc() {
    std::cout << "Npc destructor: " << getName() << std::endl;
}

void Npc::printRole() const {
    std::cout << "Role: Npc" << std::endl;
}

Villager::Villager(std::string name, std::string profession, int health, int level)
    : Npc(std::move(name), health, level), profession(std::move(profession)) {
    std::cout << "Villager constructor: " << getName() << std::endl;
}

Villager::~Villager() {
    std::cout << "Villager destructor: " << getName() << std::endl;
}

void Villager::printRole() const {
    std::cout << "Role: Villager (" << profession << ")" << std::endl;
}

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
