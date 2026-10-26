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

## Automatic And Dynamic Storage

These two declarations create real `Combatant` objects, but their lifetimes follow different rules:

```cpp
Combatant enemy{"Wurm", 50};
Combatant* summoned = new Combatant{"Hydra", 40};
```

`enemy` has automatic storage duration. When its enclosing scope ends, its destructor runs automatically.

Hydra has dynamic storage duration. `new` obtains dynamic storage, constructs Hydra there, and returns its address. The local variable `summoned` is still an automatic pointer variable; it stores Hydra's address but is not Hydra itself.

Destroying the pointer variable does not destroy the dynamic object. If the pointer disappears before the object is released, the program loses its route to that object and leaks it.

## Manual Ownership And Dangling Pointers

With a raw owning pointer, cleanup is manual:

```cpp
delete summoned;
summoned = nullptr;
```

`delete summoned` invokes Hydra's destructor, ends Hydra's lifetime, and releases its dynamic storage. The pointer variable remains alive and still contains the old address until it is changed.

That old non-null address is a dangling pointer. The address bits may be unchanged and the old bytes may still look familiar, but no live `Combatant` exists there. Dereferencing it is undefined behavior.

Assigning `nullptr` does not release a resource. It resets this pointer's state after cleanup so a later null check can see that it identifies no object. Reversing the order would lose the only address before cleanup and leak Hydra:

```cpp
summoned = nullptr; // Hydra is still alive, but its address is lost
delete summoned;    // deleting nullptr does nothing
```

A null guard is useful only when dead pointers are reliably reset. A dangling pointer is usually non-null, so `pointer != nullptr` alone cannot prove that the pointee is alive.

## AddressSanitizer Evidence

The ordinary warning-clean build did not diagnose either a deliberate leak or a dereference after `delete`. Those are runtime lifetime errors, not necessarily compiler-warning errors.

The use-after-free variant was compiled with:

```bash
clang++ -std=c++17 -Wall -Wextra -Wpedantic \
  -g -fsanitize=address -fno-omit-frame-pointer \
  main.cpp -o terminal-velocity-asan
```

AddressSanitizer reported `heap-use-after-free` and connected the three relevant events:

```text
new Combatant  -> dynamic region allocated
delete         -> region freed and poisoned
*summoned      -> invalid read from the freed region
```

The failing read appeared inside `std::string` because `printCombatant` had already dereferenced the dead `Combatant` and was trying to inspect its destroyed `Name` member. The standard-library frame was where the invalid read became visible, not the source of the lifetime bug.

In ASan shadow memory, `fd` marked bytes in a freed heap region. After the dangling dereference was removed, a fresh instrumented build ran without an ASan diagnostic.

## `std::unique_ptr`: Ownership Through RAII

Manual ownership depends on remembering the matching `delete` across every control-flow path. `std::unique_ptr` makes one object's ownership responsibility explicit:

```cpp
std::unique_ptr<Combatant> summoned =
    std::make_unique<Combatant>("Hydra", 40);
```

There are still two objects:

- `summoned` is an automatic `unique_ptr` object.
- Hydra is the dynamically stored `Combatant` that `summoned` owns.

When `summoned` leaves scope, its destructor deletes Hydra. Hydra's destructor runs and its dynamic storage is released without an explicit `delete` in `main`. This is RAII: the owner's object lifetime controls the resource lifetime.

A `unique_ptr` cannot be copied because two independent owners could both try to delete the same object. The compiler rejected this attempted copy through its deleted copy constructor:

```cpp
std::unique_ptr<Combatant> secondOwner = summoned; // does not compile
```

Ownership can instead be transferred:

```cpp
std::unique_ptr<Combatant> secondOwner = std::move(summoned);
```

This does not move Hydra to a new address and does not copy it. `secondOwner` receives the same pointer and deletion responsibility, while `summoned` becomes empty. At scope exit, exactly one owner deletes Hydra.

## What Errors This Explains

- Why modifying a parameter passed by value did not change the caller's object.
- Why a string literal could not be passed through conversion to a non-const `std::string&`.
- Why a printing helper should accept `const Combatant&` while a state-changing helper needs `Combatant&`.
- Why changing a referenced member persists after the helper returns.
- Why changing an object through `selected->member` is visible through its original name.
- Why reseating a pointer changed which `Combatant` received damage.
- Why a null pointer must be checked before dereferencing.
- Why losing the only raw owning pointer leaks a dynamic object.
- Why dereferencing after `delete` produced an ASan `heap-use-after-free` report.
- Why `unique_ptr` rejects copying but permits ownership transfer.

## Things I Keep Confusing

- `&` declares a reference here; `*` declares a pointer.
- A reference prevents a copy, but it does not automatically prevent mutation.
- `const` on a reference is a promise about access through that alias, not universal immutability.
- The function parameter name is an alias; the object still belongs to the caller.
- A pointer stores an address, not the pointed-to object's contents.
- `selected->member` expands to `(*selected).member`, not `(selected*)`.
- A raw pointer does not automatically imply heap allocation or ownership.
- A pointer can be reseated or null; a reference cannot.
- Destroying a raw pointer variable does not destroy the object it points to.
- `delete` releases the dynamic object; assigning `nullptr` only resets this pointer's state.
- A non-null pointer can still be dangling.
- Moving a `unique_ptr` transfers ownership; it does not move the owned object in memory.
