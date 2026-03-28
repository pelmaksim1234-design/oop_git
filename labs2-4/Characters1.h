#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>
#include <utility>

class Inventory {
private:
    std::string item;
    int itemCount;

public:
    Inventory(std::string item = "Potion", int itemCount = 1);
    ~Inventory();

    const std::string& getItem() const;
    int getItemCount() const;
    void setItem(const std::string& newItem);
    void setItemCount(int newCount);

    friend std::ostream& operator<<(std::ostream& os, const Inventory& inventory);
    friend std::istream& operator>>(std::istream& is, Inventory& inventory);
};

class Character {
protected:
    std::string name;
    int health;
    int level;
    const int id;

private:
    static int nextId;
    static int objectCount;

public:
    Character(std::string name = "Unknown", int health = 100, int level = 1);
    Character(const Character& other);
    Character(Character&& other) noexcept;
    Character& operator=(const Character& other);
    Character& operator=(Character&& other) noexcept;
    virtual ~Character();

    const std::string& getName() const;
    int getHealth() const;
    int getLevel() const;
    int getId() const;

    void setHealth(int newHealth);
    void levelUp();
    virtual int getPower() const;
    virtual void printRole() const;

    static int getObjectCount();
    static void printObjectCount();
};

class MainHero : public Character {
private:
    int xp;
    Inventory inventory;

public:
    MainHero(std::string name = "Hero", int health = 120, int level = 1, int xp = 0,
             Inventory inventory = Inventory());
    MainHero(const MainHero& other);
    MainHero(MainHero&& other) noexcept;
    MainHero& operator=(const MainHero& other);
    MainHero& operator=(MainHero&& other) noexcept;
    ~MainHero() override;

    int getXp() const;
    const Inventory& getInventory() const;
    Inventory& getInventory();

    MainHero& heal(int amount);
    MainHero& addXp(int amount);
    MainHero& rename(const std::string& newName);

    int getPower() const override;
    void printRole() const override;

    MainHero& operator++();
    int operator-(const Character& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MainHero& hero);
    friend std::istream& operator>>(std::istream& is, MainHero& hero);
};

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
    void printRole() const override;
};

class Npc : public Character {
public:
    Npc(std::string name = "Npc", int health = 70, int level = 1);
    ~Npc() override;

    void printRole() const override;
};

class Villager : public Npc {
private:
    std::string profession;

public:
    Villager(std::string name = "Villager", std::string profession = "Farmer", int health = 60, int level = 1);
    ~Villager() override;

    void printRole() const override;
};

class Enemy : public Character {
protected:
    int damage;

public:
    Enemy(std::string name = "Enemy", int health = 90, int level = 1, int damage = 15);
    ~Enemy() override;

    int getPower() const override;
    void printRole() const override;
};

class BossEnemy : public Enemy {
private:
    std::string specialSkill;

public:
    BossEnemy(std::string name = "Boss", int health = 200, int level = 5, int damage = 40,
              std::string specialSkill = "Meteor");
    ~BossEnemy() override;

    int getPower() const override;
    void printRole() const override;
};

#endif
