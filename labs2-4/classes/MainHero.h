#ifndef MAIN_HERO_H
#define MAIN_HERO_H

#include "Character.h"
#include "Inventory.h"

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

#endif
