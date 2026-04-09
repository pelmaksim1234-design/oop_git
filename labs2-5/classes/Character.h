#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <utility>

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
    // Task 1: non-virtual method for static binding demo.
    void introduce() const;
    // Task 2: virtual methods in base class.
    virtual int getPower() const;
    virtual void printRole() const;
    void showBindingExample() const;

    static int getObjectCount();
    static void printObjectCount();
};

#endif
