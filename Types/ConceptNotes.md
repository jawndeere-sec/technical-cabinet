# C++ Types
- C++ guarantees minimum sizes, not exact sizes. Actual size depends on platform (but on modern 64-bit systems there are common conventions).

## Integer Types
- Integer types store WHOLE numbers.
- Whole numbers are defined as those that you can write without a fractional component.

### short int (or just short)
- Minimum size: 16 bits
- Typical size (modern systems): 16 bits
- Range (signed): −32,768 to 32,767
- Range (unsigned): 0 to 65,535
- Use when:
    - You explicitly want a smaller integer
    - Memory size matters (embedded, packed structs)
### int
- Minimum size: 16 bits
- Typical size (modern systems): 32 bits
- Range (signed, 32-bit): −2,147,483,648 to 2,147,483,647
- Range (unsigned, 32-bit): 0 to 4,294,967,295
- Use when:
    - You want the "default integer"
    - Performance matters (this is usually the CPU’s natural size)
    - In real-world modern C++, int is usually 32-bit and is the standard general-purpose integer.
### long int (or long)
- Minimum size: 32 bits
- Typical size:
- Windows (64-bit): 32 bits
- Linux/macOS (64-bit): 64 bits
- This is where portability bites.
- Range depends on platform. Because long changes size depending on OS, it’s less predictable.
### long long int (or long long)
- Minimum size: 64 bits
- Typical size: 64 bits everywhere
- Range (signed): ~ ±9.22 quintillion
- Range (unsigned): 0 to ~18.44 quintillion
- Use when:
    - You explicitly need 64-bit integers
    - File sizes, large counters, hashing, etc.

## Signed vs Unsigned Ints
### Signed (default)
- e.g. int x = -5;
- Can represent negative and positive values
- Uses one bit for sign (two’s complement representation)
- Most arithmetic is designed assuming signed
### Unsigned
- e.g. unsigned int x = 5;
- Only non-negative values
- Entire bit width used for magnitude
- Range doubles on positive side
- Example (32-bit):
    - Signed max: 2.1 billion
    - Unsigned max: 4.2 billion

- Integer literals can contain any number of single quotes (') for readability - the compiler ignores them completely.
- 1000000 and 1'000'000 are both integer literals equal to 1 million.

## Floating-Point Types
- Floating-point types store approximations of real numbers.
- These are defined as any number that has a decimal point and a fractional part - e.g. 0.333 or 98.6
- You cannot store a true arbitrary real number in computer memory, but you can store an approximation.
- For example, imagne trying to store Pi in memory - you couldn't possibly store an infinitely long number in finite computer memory.
- Floating-point types take up a finite amount of memory, this is the type's PRECISION:
    - float - single precision
    - double - double precision
    - long double - extended precision
- On major desktop OSes, float level has 4 bytes of precision, double and long double have 8 bytes of precision, usually.
- If you're not doing scientific computing, you won't need to worry about the finer points here.
- Generally, just use a double and use %g to print them.

## Character Types
- Character types store human language data. There are six chatacter types:
    - char16_t - Used for 2-byte character sets (Example: UTF-16);
    - char32_t - Used for 4-byte character sets (Example: UTF-32);
    - signed char - same as char but guaranteed to be signed;
    - unsigned char - same as char but guaranteed to be unsigned;
    - wchar_t - Large enough to contain the largest chatacter of the implementation's locale (Example: Unicode)
- A character literal is a single, constant character, single quotation marks ('') surround all characters.
- If the character is any type but char, you need a prefix:
    - L is for wchar_t, 
    - U for char32_t,
    - u for char16_t.

## Escape Sequences
- These don't display on the screen, they force cursor movements amongst other things.
- These are reserved characters:
    - \n - newline
    - \t - tab (horizontal)
    - \v - tab (vertical)
    - \b - backspace
    - \r - carriage return
    - \f - form feed
    - \a - alert
    - \\ - backslash
    -  ? or \? - question mark
    - \' - single quote
    - \" - double quote
    - \0 - Null character


## Boolean Types
- Boolean types have two states: true and false.
- The sole boolean type is bool.
- Bool and int convert easily - True state converts to 1, false state converts to 0.
- There is no format specifier for bool, but you can use the int format specifier %d within printf.
- You would just get it to yield a 1 for True and 0 for False. See types.cpp for an example.

## Comparison Operators
- Operators are functions that perform computations on operands.
- Operands are just objects. 
- Comparison operators take two arguments and return a bool - that's how we use them to build conditional (if x, then y) logic.
- Your available comparison operators are:
    - == (equality)
    - != (inequality)
    - > (greater than)
    - < (less than)
    - >= (greater than or equal to)
    - <= (less than or equal to)
- Each comparison produces a Boolean result.
- Printf prints the Boolean as an int.

## Logical Operators
- Logical operators evaluate Boolean logic on bool types.
- You characterize operators by how many operands they take.
- UNARY operators take a single operand, BINARY operators take two, TERNARY operators take three, and so on.
- UNARY - Negation operator - (!) - Takes a single operand and returns the opposite.
    - !true yields false, !false yields true.
- BINARY - AND and OR - && and || - AND returns true only if BOTH operands are true. OR returns true if EITHER or BOTH operands are true.
- TERNARY/Conditional operator – ?: – Takes three operands.
    - Syntax: condition ? expression_if_true : expression_if_false
    - Evaluates the first operand, the condition first.
    - If true → evaluates and returns the second operand.
    - If false → evaluates and returns the third operand.
    - Only one of the two result expressions is evaluated.

## Size_t
- Available in the <cstddef> to encode the size of objects
- The size_t objects guarantee that their maximum values are sufficient to represent the maximum size in bytes of ALL objects.
- This means a size_t could be 2 BYTES or 200 BYTES depending on implementation!
- The size_t type is identical functionally between the C and C++ version.
- You may occasionally see std::size_t instead.
- The unary operator sizeof() takes a type operand and returns the size in bytes of that type.
- size_t printf format specifiers are %zd for decimal representation, %zx for hexidecimal.

## Void
- The void type has an empty set of values.
- Because a void object cannot hold a value, C++ disallows void objects.
- You use void in special situations, such as the return type for functions that don't return any value.


