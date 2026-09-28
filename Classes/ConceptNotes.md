# CLASSES

## What Is A Class?

- A class, put simply, is a user-defined type that groups data and behavior together.  In plain-old-data (POD) classes in C++, you can only have data members within them.

- Sometimes, that's all you need from a class and POD classes are totally fine. However, you're gonna have a bad time writing a complex program using only PODs and separate functions to operate on them.

- C++ lets you use a design pattern called **encapsulation**, which binds data with the functions that manipulate that data. This has two major benefits:

1) Related code stays in one place, which helps you reason about your program and explain it to...literally anyone.

2) You can understand how a code segment works because it descries both program state and how the code you wrote **modifies** that state.

## Methods

- You achieve encapsulation by adding METHODS and access controls to the classes you define Methods are functions that are members of a class, an upgrade from a POD class for sure.

- The idea is that you create an explicit connection between the class, the data members it has and whatever code you're writing to do something to that data. You just define a method by adding your function to the class definition.

- The method will have access to all of a class's members. Take a look at an example below to see what this looks like in practice:

struct ClockOfTheLongNow {
    void addYear(){
        year++;
    }
    int year;
};

- The ClockOfTheLongNow class keeps track of the year, the int year is our data member, and add_year is a method within our class that increments the year. The addYear() method declaration looks like any other function that takes 0 parameters and returns no value - it just does the thing and doesn't need to share that result with any other code.

## Structs vs Classes

- A STRUCT is a user-defined type that groups related data together into one coherent entity.

- Instead of keeping separate loose variables like `name`, `health`, and `level`, a struct lets us describe one thing that owns all of those values together. Structs are often used for simple data objects where the members are meant to be accessed directly.

- A CLASS is also a user-defined type, but it is usually used when we want to group data together with the behavior that **operates** on that data. Classes are commonly used when we want the object to control its own state through member functions instead of letting outside code freely change its internal data.

- In C++, structs and classes are nearly the same mechanically. The main default difference is:

- struct members are PUBLIC by default.
- class members are PRIVATE by default.

- The bigger practical difference is convention:
    - Use a struct when the type is mostly a simple bundle of data.
    - Use a class when the type has rules, behavior, or internal state that should be protected.

- Classes are useful when the data has rules that need following.

## Access Control

- The idea of access control is that C++ lets you decide which parts of your program get to touch the internals of a struct or class.

- There are three types of access control labels:
    1) private
    2) protected
    3) public
    
    We mostly deal with just public and private for the most part. 

- **Private** members of a class are accessible only from within other members of the same class (or from their "friends").
- **Protected** members are accessible from other members of the same class (or from their "friends"), but also from members of their derived classes.
- Finally, **public** members are accessible from anywhere where the object is visible.

- By default, all members of a class declared with the class keyword have have private access for all of its members. Any member declared BEFORE any other access specifier, automatically has private access.

- Take a look at the following example from https://cplusplus.com/doc/tutorial/classes/

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area (void);
} rect;

- We're declaring a class **Rectangle** and object (i.e. a variable we can do something with) of that class **rect**.

- This class has four members:
    1) int width (data member)
    2) int height (data member)
    3) void set_values (int,int) (function member)
    4) int area (void) (function member)

- Because int width, height were declared before the public: access specifier, those two members have PRIVATE access by default.

- After the declarations of Rectangle and rect, any of the public members of object rect can be accessed as if they were normal functions or normal variables, by simply inserting a dot (.) between object name and member name. This follows the same syntax as accessing the members of plain data structures. For example:

rect.set_values (3,4);
myarea = rect.area();

- The only members of rect that cannot be accessed from outside the class are width and height, since they have private access and they can only be referred to from within other members of that same class.


## Constructors

- A CONSTRUCTOR is a special member function that runs automatically when an object is created. Constructors are used to initialize an object's data members so that the object starts its life in a valid state.

- A constructor has the same name as the class and does not have a return type.

- Without using constructors, you can create objects whose internal data starts out undefined, incomplete, or just nonsense.

- As an example, imagine a clock, defined as a class:

class Clock {
private:
    int hour;
    int minute;
};

- If you then go Clock clock in your code, what are the values of hour and minute? They might be garbage values or cause UB errors - you're gonna have a bad time, either way.

- Constructors solve that by saying "when you initialize a clock, start it at a valid time". They stop objects from being born in a broken or unknown state.

- Let's add a constructor to our Clock class, like so:

class Clock {
public:
    Clock() {
        hour = 0;
        minute = 0;
    }

private:
    int hour;
    int minute;
};

- The constructor runs automatically and you don't need to call it like a method after the fact.

- The example above is called a **default constructor**, a constructor that takes no arguments. You can also write a **parameterized constructor**, which is a constructor that takes parameters. Who knew?

- The example ABOVE lets you do Clock clock;  The example BELOW lets you do Clock clock(10,30); which may be more useful for you in your program:

class Clock {
public:
    Clock(int startingHour, int startingMinute) {
        hour = startingHour;
        minute = startingMinute;
    }

private:
    int hour;
    int minute;
};

- Constructors make sure an object does not enter the program half-built.


## Member Initializer Lists (MIL)

- A constructor's job is to get an object into a valid starting state, and member initializer lists are a way to cleanly and idiomatically do that.

- It's part cleaner C++ code, part that some types legitimately need to be "born with a value", or you get errors.

class Clock {
public:
    Clock(int startingHour, int startingMinute)
        : hour{startingHour}, minute{startingMinute}
        ^^^ THIS IS THE MEMBER INITIALIZER LIST ^^^
    {
    }

private:
    int hour;
    int minute;
};

- An MIL initializes data members BEFORE the constructor body runs. 

- This is different from assigning these members values from WITHIN the constructor body. Initalizer lists directly construct the members WITH their initial values.

- Think:
    - initializer list = “be born with this value”
    - constructor body assignment = “be born, then get changed”

- A const member MUST be initailized immediately, it can't be created and then filled in later. For example:

class Character {
public:
    Character(int id)
        : characterId{id}
    {
    }

private:
    const int characterId;
};

- ^^^ This would work, characterID is born with a value.

class Character {
public:
    Character(int id) {
        characterId = id; // error
    }

private:
    const int characterId;
};

- ^^^ This would NOT work, because by the time the constructor body runs, characterID already exists. Because it's a const, you can't assign to it either once this happens.

- Reference data members also need to bind to something immediately, or they don't work. References CANNOT exist in a "here, but not referring to anything yet" state.

class PlayerView {
public:
    PlayerView(int& playerHealth)
        : healthRef{playerHealth}
    {
    }

private:
    int& healthRef;
};

- ^^^^ This would work.

class PlayerView {
public:
    PlayerView(int& playerHealth) {
        healthRef = playerHealth; // not binding the reference here
    }

private:
    int& healthRef;
};

- ^^^ This would NOT work. Constructor body assignment is too late, so playerHealth isn't actually getting bound to healthRef, so int& healthRef doesn't work either.


## Destructors

- If constructors are how objects are born correctly, initalizer lists are how an object's members are born correctly, DESTRUCTORS are all about what happens when an object dies.

- They're used to clean up resources owned by an object BEFORE that object goes away.

- A destructor has the same name as the class, starts with a `~`, takes no parameters, and has no return type. They run automatically when an object is destroyed. Here's an example:

class Character {
public:
    ~Character() {
        // cleanup happens here
    }
};
