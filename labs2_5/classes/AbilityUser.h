#ifndef ABILITY_USER_H
#define ABILITY_USER_H

#include <string>

class AbilityUser {
public:
    virtual ~AbilityUser() = default;
    // Task 8: pure-virtual interface contract.
    virtual std::string getBattleTitle() const = 0;
    virtual int useAbilityPower() const = 0;
};

#endif
