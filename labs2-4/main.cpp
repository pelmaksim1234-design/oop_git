#include "BossEnemy.h"
#include "MainHero.h"
#include "Villager.h"
#include "WarriorHero.h"

#include <iostream>
#include <sstream>
#include <utility>

namespace {
void showThroughBasePointer(const Character* character) {
    std::cout << "Power via Character*: " << character->getPower() << std::endl;
    character->printRole();
}

void showThroughBaseReference(const Character& character) {
    std::cout << "Power via Character&: " << character.getPower() << std::endl;
    character.printRole();
}

void showNpcInteraction(const Npc& npc) {
    std::cout << npc.interact() << std::endl;
}
}

int main() {
    std::cout << "--- Static field and method ---" << std::endl;
    Character::printObjectCount();

    std::cout << "\n--- Multi-level inheritance and composition ---" << std::endl;
    MainHero hero("Andrii", 130, 2, 40, Inventory("Potion", 3));
    WarriorHero warrior("Taras", 180, 3, 70, Inventory("Sword", 1), 25);
    Villager villager("Petro", "Blacksmith", 65, 1);
    BossEnemy boss("Dragon", 240, 6, 45, "FireStorm");

    hero.printRole();
    warrior.printRole();
    villager.printRole();
    boss.printRole();
    Character::printObjectCount();

    std::cout << "\n--- Static method binding problem ---" << std::endl;
    hero.showBindingExample();
    boss.showBindingExample();
    Character* baseHero = &hero;
    Character* baseBoss = &boss;
    baseHero->showBindingExample();
    baseBoss->showBindingExample();

    std::cout << "\n--- Run-time polymorphism via base class pointer ---" << std::endl;
    showThroughBasePointer(&hero);
    showThroughBasePointer(&warrior);
    showThroughBasePointer(&boss);

    std::cout << "\n--- Run-time polymorphism via base class reference ---" << std::endl;
    showThroughBaseReference(hero);
    showThroughBaseReference(villager);
    showThroughBaseReference(boss);

    std::cout << "\n--- Pure virtual function and interface-like Npc ---" << std::endl;
    showNpcInteraction(villager);

    std::cout << "\n--- Virtual destructor through base pointer ---" << std::endl;
    Character* dynamicBoss = new BossEnemy("Hydra", 210, 5, 38, "PoisonRain");
    delete dynamicBoss;

    std::cout << "\n--- final modifier demonstration ---" << std::endl;
    std::cout << "WarriorHero and BossEnemy/Villager are marked final in the hierarchy." << std::endl;
    std::cout << "WarriorHero::printRole is also marked final." << std::endl;

    std::cout << "\n--- this pointer demonstration ---" << std::endl;
    hero.rename("AndriiTheBrave").heal(20).addXp(15);
    std::cout << hero << std::endl;

    std::cout << "\n--- Const object demonstration ---" << std::endl;
    const MainHero constHero("ConstHero", 110, 2, 25, Inventory("Scroll", 2));
    std::cout << constHero << std::endl;
    std::cout << "Const hero power: " << constHero.getPower() << std::endl;
    std::cout << "Const hero inventory: " << constHero.getInventory() << std::endl;

    std::cout << "\n--- Copy constructor ---" << std::endl;
    MainHero copiedHero(hero);
    std::cout << copiedHero << std::endl;

    std::cout << "\n--- Move constructor ---" << std::endl;
    MainHero movedHero(std::move(copiedHero));
    std::cout << movedHero << std::endl;

    std::cout << "\n--- Copy assignment operator ---" << std::endl;
    MainHero assignedHero;
    assignedHero = hero;
    std::cout << assignedHero << std::endl;

    std::cout << "\n--- Unary operator ---" << std::endl;
    ++hero;
    std::cout << "After ++hero: " << hero << std::endl;

    std::cout << "\n--- Binary operator ---" << std::endl;
    std::cout << "Hero power difference vs boss: " << (hero - boss) << std::endl;

    std::cout << "\n--- Stream insertion and extraction ---" << std::endl;
    MainHero parsedHero;
    std::istringstream heroInput("InputHero 140 4 80 Elixir 5");
    heroInput >> parsedHero;
    std::cout << parsedHero << std::endl;

    std::cout << "\n--- Constructor / destructor order in deeper hierarchy ---" << std::endl;
    {
        WarriorHero tempWarrior("Bohdan", 170, 4, 60, Inventory("Axe", 1), 30);
        std::cout << "Temporary warrior power: " << tempWarrior.getPower() << std::endl;
    }

    std::cout << "\n--- Final static count before program end ---" << std::endl;
    Character::printObjectCount();

    return 0;
}
