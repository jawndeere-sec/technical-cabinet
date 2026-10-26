#include <iostream>
#include <memory>
#include <string>
#include <utility>

struct Combatant {
    std::string name;
    int health;

    Combatant(std::string initialName, int initialHealth)
        : name{std::move(initialName)}, health{initialHealth}
    {
    }

    ~Combatant()
    {
        std::cout << "Destroying " << name << '\n';
    }
};

void printCombatant(const std::string& role, const Combatant& combatant)
{
    std::cout << role << " Name: " << combatant.name
              << ", Health: " << combatant.health << '\n';
}

int main()
{
    std::unique_ptr<Combatant> summoned =
        std::make_unique<Combatant>("Hydra", 40);

    // Copying would create two owners, so unique_ptr deletes its copy operation.
    // std::unique_ptr<Combatant> duplicate = summoned;

    std::unique_ptr<Combatant> currentOwner = std::move(summoned);

    if (summoned == nullptr) {
        std::cout << "Original owner is empty\n";
    }

    printCombatant("Current owner", *currentOwner);

    return 0;
}
