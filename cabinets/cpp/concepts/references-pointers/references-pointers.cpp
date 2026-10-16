#include <iostream>
#include <string>

struct Combatant {
    std::string name;
    int health;

    void applyDamage(int damage)
    {
        health = health - damage;
    }
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
    Combatant player{"Leto", 30};
    Combatant enemy{"Wurm", 50};

    printCombatant("Enemy", enemy);
    applyDamage(enemy, 5);
    printCombatant("Enemy", enemy);

    Combatant* selected = &player;
    selected->applyDamage(5);
    printCombatant("Selected", *selected);

    selected = &enemy;
    printCombatant("Selected", *selected);

    selected = nullptr;
    if (selected == nullptr) {
        std::cout << "No combatant selected\n";
    }

    return 0;
}
