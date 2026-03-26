#include "vehicle.h"

#include <iostream>
#include <utility>

int main() {
    Squad squad;

    Knight* knight = new Knight("Andriy", 200, 55, Weapon("Lion Blade", 35), 45,
                                "Golden Order");
    Boss* boss = new Boss("Dragon", 320, 50, 5);

    Warrior baseWarrior("Bohdan", 170, 25, Weapon("Battle Axe", 28), 30);
    Warrior copiedWarrior(baseWarrior);
    Warrior movedWarrior(std::move(baseWarrior));
    Warrior assignedWarrior;
    assignedWarrior = copiedWarrior;

    squad.addMember(knight);
    squad.addMember(boss);
    squad.addMember(new Warrior(copiedWarrior));
    squad.addMember(new Warrior(std::move(movedWarrior)));
    squad.addMember(new Warrior(assignedWarrior));

    std::cout << "\n--- Squad contains: ---\n";
    squad.showAll();
    std::cout << "-----------------------\n";

    return 0;
}
