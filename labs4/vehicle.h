#pragma once

#include <iostream>
#include <string>
#include <vector>

class Weapon {
private:
    std::string title;
    int power;

public:
    Weapon(std::string title = "Wooden Sword", int power = 5);
    Weapon(const Weapon& other);
    Weapon(Weapon&& other) noexcept;
    Weapon& operator=(const Weapon& other);
    ~Weapon();

    void show() const;
};

class Being {
protected:
    std::string name;

public:
    Being(std::string name = "Unknown");
    Being(const Being& other);
    Being(Being&& other) noexcept;
    Being& operator=(const Being& other);
    virtual ~Being();

    virtual void show() const;
};

class Character : public Being {
protected:
    int health;

public:
    Character(std::string name = "Character", int health = 100);
    Character(const Character& other);
    Character(Character&& other) noexcept;
    Character& operator=(const Character& other);
    ~Character() override;

    void show() const override;
};

class Hero : public Character {
protected:
    int mana;
    Weapon weapon;

public:
    Hero(std::string name = "Hero", int health = 120, int mana = 60,
         Weapon weapon = Weapon());
    Hero(const Hero& other);
    Hero(Hero&& other) noexcept;
    Hero& operator=(const Hero& other);
    ~Hero() override;

    void show() const override;
};

class Warrior : public Hero {
protected:
    int armor;

public:
    Warrior(std::string name = "Warrior", int health = 150, int mana = 30,
            Weapon weapon = Weapon("Steel Sword", 20), int armor = 25);
    Warrior(const Warrior& other);
    Warrior(Warrior&& other) noexcept;
    Warrior& operator=(const Warrior& other);
    ~Warrior() override;

    void show() const override;
};

class Knight : public Warrior {
private:
    std::string orderName;

public:
    Knight(std::string name = "Knight", int health = 180, int mana = 40,
           Weapon weapon = Weapon("Royal Blade", 30), int armor = 40,
           std::string orderName = "Silver Order");
    ~Knight() override;

    void show() const override;
};

class Enemy : public Character {
protected:
    int damage;

public:
    Enemy(std::string name = "Enemy", int health = 90, int damage = 15);
    ~Enemy() override;

    void show() const override;
};

class Boss : public Enemy {
private:
    int rageLevel;

public:
    Boss(std::string name = "Boss", int health = 220, int damage = 35,
         int rageLevel = 3);
    ~Boss() override;

    void show() const override;
};

class Squad {
private:
    std::vector<Being*> members;

public:
    void addMember(Being* member);
    void showAll() const;
    ~Squad();
};
