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

## Passing By Reference

## Const References

## What Is A Pointer?

## Address-of Operator

## Dereferencing

## Pointer Syntax

## nullptr

## Pointers vs References

## Pointers and Classes

## What Errors This Explains

## Things I Keep Confusing