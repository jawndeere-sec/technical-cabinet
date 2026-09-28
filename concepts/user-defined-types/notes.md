# User-Defined Types in C++
- Surprising no one, user-defined types are types that the user can define.

## Enumerations
- The simplest.
- The values that an enumeration can take are restricted to a set of possible values.
- Excellent for modelling categorical concepts.

## Classes
- More fully featured types that give you flexibility to pair data and functions.
- Classes that only contain data are called "plain-old-data" classes.

## Unions
- Boutique user-defined type.
- All members share the same memory location.
- Unions are dangerous and easy to misuse.

### Enumeration Types
- Declare enums using keyword enum class, followed by the type name and a listing og the values it can take.
- The values are arbitrary alphanumeric strings that will represent whatever categories you want to represent.
- Under the hood these values are just integers.
- However, these allow you to write safer, more expressive code by using programmer-defined types rather than integeres that could mean anything.
- To intialize an enumeration variable to a value, use the name of the type, followed by two colons (::) and the desired value.

### Plain-old-data Classes (PODs)
- Classes are user-defined types that contain data and functions.
- They are the heart and soul of C++ that allow you to express yourself.
- Plain-old-date classes are simple containers. 
- Think of them as a sort of array of elements of potentially DIFFERENT types.
- Each element within a class is called a MEMBER.
- PODs are C compatible, they are efficiently represented in memory, and you can employ machine instructions that are highly efficient to copy/move them.
- C++ also guarantees that members will be sequential in memory.
- In general, you should order members from largest to smallest within POD definitions.
- Every POD begins with the keyword struct followed by the PODs desired name.
- Next, list the members types and names.
- So in usertypes.cpp, you can see we created a POD by using struct Book{}.
- To access or set one of those members, you use dot-operators.
- So if I create a Book object Dune, I can set the page count by using dune.pages