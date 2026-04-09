#include "BossEnemy.h"
#include "MainHero.h"
#include "Villager.h"
#include "WarriorHero.h"
#include "AbilityUser.h"

#include <iostream>
#include <sstream>
#include <utility>

static void showByBasePointer(const Character* character) {
    std::cout << "[Base pointer] ";
    character->printRole();
    std::cout << "Power = " << character->getPower() << std::endl;
}

static void showByBaseReference(const Character& character) {
    std::cout << "[Base reference] ";
    character.printRole();
    std::cout << "Power = " << character.getPower() << std::endl;
}

int main() {
    MainHero hero("Andrii", 130, 2, 40, Inventory("Potion", 3));
    WarriorHero warrior("Taras", 180, 3, 70, Inventory("Sword", 1), 25);
    Villager villager("Petro", "Blacksmith", 65, 1);
    BossEnemy boss("Dragon", 240, 6, 45, "FireStorm");

    // Task 1
    std::cout << "\n1) Static method binding problem" << std::endl;
    Character* baseToHero = &hero;
    baseToHero->introduce();
    hero.introduce();
    std::cout << "printRole() is virtual, so this one is dynamic:" << std::endl;
    baseToHero->printRole();

    // Task 2
    std::cout << "\n2) Virtual functions in base class" << std::endl;
    std::cout << "Character has virtual getPower() and printRole()." << std::endl;

    // Task 3
    std::cout << "\n3) Override + run-time polymorphism (base pointer)" << std::endl;
    showByBasePointer(&hero);
    showByBasePointer(&warrior);
    showByBasePointer(&boss);
    showByBasePointer(&villager);

    // Task 4
    std::cout << "\n4) Virtual destructor demonstration" << std::endl;
    Character* dynCharacter = new BossEnemy("Hydra", 220, 5, 38, "VenomWave");
    delete dynCharacter;
    std::cout << "Deleted through Character*: derived destructors were called." << std::endl;

    // Task 5
    std::cout << "\n5) final demonstration" << std::endl;
    warrior.printRole();
    std::cout << "WarriorHero::printRole is final; BossEnemy class is final too." << std::endl;

    // Task 6
    std::cout << "\n6) Run-time polymorphism (base reference)" << std::endl;
    showByBaseReference(hero);
    showByBaseReference(boss);

    // Task 7
    std::cout << "\n7) Pure virtual function in class" << std::endl;
    Npc* npcRef = &villager;
    std::cout << npcRef->getDialogue() << std::endl;
    std::cout << "Npc is abstract because getDialogue() is pure virtual." << std::endl;

    // Task 8
    std::cout << "\n8) Interface via pure virtual functions" << std::endl;
    AbilityUser* abilityUsers[] = {&hero, &boss};
    for (AbilityUser* user : abilityUsers) {
        std::cout << user->getBattleTitle() << " -> ability power = " << user->useAbilityPower() << std::endl;
    }

    std::cout << "\nExtra: copy/move and operators from previous lab requirements" << std::endl;
    hero.rename("AndriiTheBrave").heal(20).addXp(15);
    MainHero copiedHero(hero);
    MainHero movedHero(std::move(copiedHero));
    MainHero assignedHero;
    assignedHero = hero;
    ++hero;
    std::cout << "Hero power difference vs boss: " << (hero - boss) << std::endl;
    std::istringstream heroInput("InputHero 140 4 80 Elixir 5");
    heroInput >> assignedHero;
    std::cout << assignedHero << std::endl;

    std::cout << "\nStatic object count:" << std::endl;
    Character::printObjectCount();

    return 0;
}
