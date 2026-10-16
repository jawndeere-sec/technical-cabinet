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

A pointer is a variable whose value is a memory address.

```cpp
Combatant* selected = &enemy;
```

`selected` stores the address of the existing `enemy`. It does NOT store `enemy`'s member values, and this line creates zero additional `Combatant` objects.

In this example, the pointer is non-owning. It does not create, destroy, or extend the lifetime of the object it points to. If that object is destroyed first, the pointer becomes dangling and must not be dereferenced.

## Address-of Operator

In an expression, `&` obtains an existing object's address:

```cpp
Combatant* selected = &enemy;
```

The two uses of punctuation describe different things:

- `Combatant*` declares a pointer-to-`Combatant` type.
- `&enemy` produces `enemy`'s address.

This is different from `Combatant& target`, where `&` is part of a reference type declaration.

## Dereferencing

Dereferencing follows a stored address back to the existing object:

```cpp
printCombatant("Selected", *selected);
```

`*selected` is the `Combatant` at the stored address. It is not a copy.

Dereferencing only makes sense while the pointer identifies a live object. Dereferencing `nullptr` or a dangling pointer is undefined behavior.

## Pointer Syntax

The arrow operator accesses a member through a pointer:

```cpp
selected->applyDamage(5);
```

It is shorthand for:

```cpp
(*selected).applyDamage(5);
```

The parentheses matter. Unary `*` first produces the pointed-to object, and then `.` accesses that object's member.

A pointer can also be reseated:

```cpp
selected = &player;
```

After this assignment, later dereferences reach `player`, not the object that `selected` previously identified. In Terminal Velocity, placing this reassignment before the damage call changed Leto from 30 to 25 while Wurm remained at 50. The pointer followed its current address exactly.

## nullptr

`nullptr` explicitly represents a pointer that identifies no object:

```cpp
Combatant* selected = nullptr;
```

Guard the pointer before member access:

```cpp
if (selected != nullptr) {
    selected->applyDamage(5);
}
```

A null check does not make dereferencing null safe. It prevents the invalid dereference from happening.

The null-target experiment also exposed an output bug: the program initially printed `Damage applied!` outside the successful branch even though no call happened. Observable messages need to follow the same control-flow branch as the event they claim occurred.

## Pointers vs References

Both pointers and references can provide access to an existing object, but they express different contracts.

A reference:

- is an alias for one existing object;
- must be bound during initialization;
- cannot be reseated;
- cannot normally represent no object;
- uses ordinary object syntax.

A pointer:

- is a variable whose value is an address;
- can be reseated to identify another object;
- can hold `nullptr`;
- requires dereferencing with `*` or member access with `->`;
- does not imply ownership or heap allocation.

Pointers are not merely "for memory" while references are "for values." Both reach objects and their values. Nullability and reseating are the useful distinctions here.

## Pointers and Classes

When a pointer identifies a class or struct object, `->` calls a member on that same receiving object:

```cpp
Combatant* selected = &enemy;
selected->applyDamage(5);
```

The data flow is:

```text
selected stores &enemy
-> dereferences that address
applyDamage receives enemy as its implicit object
enemy's state changes
```

No copied `Combatant` is involved. A raw pointer also says nothing by itself about who owns the object. Ownership has to come from the surrounding design.

## What Errors This Explains

- Why modifying a parameter passed by value did not change the caller's object.
- Why a string literal could not be passed through conversion to a non-const `std::string&`.
- Why a printing helper should accept `const Combatant&` while a state-changing helper needs `Combatant&`.
- Why changing a referenced member persists after the helper returns.
- Why changing an object through `selected->member` is visible through its original name.
- Why reseating a pointer changed which `Combatant` received damage.
- Why a null pointer must be checked before dereferencing.

## Things I Keep Confusing

- `&` declares a reference here; `*` declares a pointer.
- A reference prevents a copy, but it does not automatically prevent mutation.
- `const` on a reference is a promise about access through that alias, not universal immutability.
- The function parameter name is an alias; the object still belongs to the caller.
- A pointer stores an address, not the pointed-to object's contents.
- `selected->member` expands to `(*selected).member`, not `(selected*)`.
- A raw pointer does not automatically imply heap allocation or ownership.
- A pointer can be reseated or null; a reference cannot.
