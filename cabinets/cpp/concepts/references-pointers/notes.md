# REFERENCES AND POINTERS

## What Problem Are References and Pointers Solving?

When you pass something into a function by value, the function gets a copy of the original value. Changing that parameter changes only the function’s local copy, not the original object’s stored value.

References and pointers solve this problem of working with a local copy by referencing or pointing to the actual stored value.

## References vs Copies

The simplest way to separate these two is as follows:

Copies have the same VALUE as another object, but are crucially NOT the same object.

References are just another name for the SAME object.

## What Is A Reference?

A reference is an alias for an existing object.

It does not create a separate object with its own value. It gives me another way to access the original object.

## Reference Rules

1) A reference must be initalized.

A reference cannot exist as an empty nickname. It HAS to be a nickname for something.

So this is VALID:

int health = 100;
int& healthRef = health;

But this is INVALID:

int& ref;

A reference is an alias for an existing object.

It does not create a separate object with its own value. It gives me another way to access the original object.


2) A reference cannot be rebound.

Assigning to a reference changes the object it already refers to. It does not make the reference point somewhere else.

Once a reference refers to an object, it keeps referring to that object. 
So as an example:

================

int health = 100;
int armor = 50;

int& ref = health;

ref = armor;

=================

This does NOT make ref refer to armor.

It means health = armor. The reference still points to health.

The values afterwards would be health = 50 and armor = 50.


3) A reference cannot normally refer to nothing.

4) Changing through a reference changes the original.

int health = 100;
int& ref = health;

ref = 80;

After this, health = 80 and ref = 80.

References are ALIASES, not COPIES.

5) Reference types must match.

## Passing By Value

Passing by value gives the function a separate local object or value.

```cpp
void applyDamageCopy(Combatant target, int damage);
```

`target` would contain the same member values as the caller's combatant, but it would NOT be the same object. Changing `target.health` would change only the copy.

## Passing By Reference

Passing by reference aliases the caller's existing object.

```cpp
void applyDamage(Combatant& target, int damage)
{
    target.health = target.health - damage;
}
```

In Terminal Velocity, calling `applyDamage(enemy, player.combatDamage)` made `target` another name for `enemy`. Assigning through `target.health` therefore changed `enemy.health` from 50 to 45 after the function returned.

The two pieces do different jobs:

- `&` means alias the existing object instead of copying it.
- Leaving off `const` means mutation through that alias is allowed.

The `damage` parameter is still passed by value. It receives its own copy of the integer value because the function only needs to read that small value.

## Const References

A const reference is a read-only alias:

```cpp
void printCombatant(const std::string& role, const Combatant& combatant);
```

- `&` avoids copying the existing object.
- `const` prevents this function from modifying the object through that alias.

This does not make the original object universally immutable. Other code may still change it. The promise is narrower: this function cannot mutate it through this parameter.

### Binding A Temporary String

The call `printCombatant("Enemy", enemy)` begins with a string literal whose type is a const character array. C++ can create a temporary `std::string` from it for the call.

This first attempt failed:

```cpp
void printCombatant(std::string& role, const Combatant& combatant);
```

A non-const lvalue reference cannot bind to that temporary `std::string`. Changing the role parameter to `const std::string&` allowed the temporary to remain alive through the call while preserving the function's read-only intent.

### The Confusion To Avoid

`&` does NOT mean read-only. It means reference.

```cpp
Combatant& target             // aliases and may mutate
const Combatant& combatant    // aliases and may only read through this name
```

References avoid the object copy. `const` is what blocks mutation through the reference.

## What Is A Pointer?

## Address-of Operator

## Dereferencing

## Pointer Syntax

## nullptr

## Pointers vs References

## Pointers and Classes

## What Errors This Explains

- Why modifying a parameter passed by value did not change the caller's object.
- Why a string literal could not be passed through conversion to a non-const `std::string&`.
- Why a printing helper should accept `const Combatant&` while a state-changing helper needs `Combatant&`.
- Why changing a referenced member persists after the helper returns.

## Things I Keep Confusing

- `&` declares a reference here; `*` declares a pointer.
- A reference prevents a copy, but it does not automatically prevent mutation.
- `const` on a reference is a promise about access through that alias, not universal immutability.
- The function parameter name is an alias; the object still belongs to the caller.
