#pragma once

#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int level;
    static int count;

public:
    Character(std::string name = "Hero", int health = 100, int level = 1);
    Character(const Character& other);
    Character(Character&& other) noexcept;

    Character& train(int gainedLevels);
    void show() const;
    const std::string& getName() const;
    int getHealth() const;
    int getLevel() const;
    static void showCount();

    Character operator+(const Character& other) const;
    Character& operator++();

    friend std::ostream& operator<<(std::ostream& out, const Character& character);
    friend std::istream& operator>>(std::istream& in, Character& character);
};
