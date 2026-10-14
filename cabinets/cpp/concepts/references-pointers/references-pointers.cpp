#include <iostream>
#include <string>

struct Combatant {
    std::string name;
    int health;
};

void printCombatant(const std::string& role, const Combatant& combatant)
{
    std::cout << role << " Name: " << combatant.name
              << ", Health: " << combatant.health << '\n';
}

void applyDamage(Combatant& target, int damage)
{
    target.health = target.health - damage;
}

int main()
{
    Combatant enemy{"Wurm", 50};

    printCombatant("Enemy", enemy);
    applyDamage(enemy, 5);
    printCombatant("Enemy", enemy);

    return 0;
}
