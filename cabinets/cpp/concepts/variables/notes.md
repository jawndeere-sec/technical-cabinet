# The C++ Type System

- C++ is an object-oriented language.
- Objects have state and behavior - Think of a light switch for example.
- You can describe the STATE as the condition the switch is in - on or off.
- You can also describe the BEHAVIOR of the switch - does it move from one state (on) to another (off) or is it a dimmer with many different states between the two?
- C++ is STRONGLY TYPED - which means each object has a predetermined data type.

## Variables
- If you name an object, it's called a variable.
- You declare variables by providing their type, their name and then a semicolon;
- You initialize variables by declaring them.
- Object intialization establishes an object's state.
- In C++, you want to use Uniform initialization like int num1 {42};
- You can assign variables equal to the result of math expressions like int lucky_number = num1 / 6

## Conditional Statements
- Conditional statements allow you to make decisions.
- They rest on Boolean expressions - they evaluate to True or False.
- You can build Boolean expressions with comparison operators (== , !=, >, <, >=, <=)
- You write interesting programs with this logic using condition statements like if or while.
- In if statements, if the Boolean evaluates to true, then the nested statement executes, otherwise it doesn't.
- You can nest multiple statements together to execute, you call this a COMPOUND STATEMENT.

## Printf format specifiers (a list)
- Here’s the short list you actually need in 95% of cases - NOT EXHAUSTIVE:
- Integers
%d → signed int
%u → unsigned int
%ld → signed long
%lu → unsigned long
%lld → signed long long
%llu → unsigned long long
- Floating Point
%f → float or double
%lf → technically for double, but in printf %f already expects a double
Important nuance:
When you pass a float to printf, it is automatically promoted to double.
- Characters & Strings
%c → char
%s → const char*
- Pointers
%p → pointer (e.g., void*)
- Size_t
%zu → size_t