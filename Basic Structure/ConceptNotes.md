# BASIC STRUCTURE NOTES 
- You write C++ source code into source files.
- You then use a compiler to convert your C++ into executable machine code.
- Helloworld.cpp is our first C++ source file and introduces multiple concepts.

## Main()
- C++ programs have a single entry point called the main() function.
- In C++, functions are blocks of code that take inputs, execute instructions, and return results.
- Within main, you call functions and then program exit, returning the value indicated to the OS.

## Libraries
- Libraries are helpful code collections you can import into your programs to prevent having to reinvent basic functionality.
- C and C++ have #include <blahblah>
- helloworld.cpp has #include <cstdio>, a library that that performs input/output ops, such as printing to console.
- That means, I did not had have to write functionality TO print things to console, that already exists in the cstdio library.

## The Compiler Toolchain

### Preprocessor
- This stage:
    - Expands #include
    - Expands #define
    - Removes comments
    - Handles conditional compilation (#ifdef)
- The output of this stage is still C++, just one giant file with all includes pasted in.
- Preprocessor performs basic source code manipulation.
- Preprocessor produces a single TRANSLATION UNIT when it finishes processing a source file.
- A translation unit is a source file AFTER preprocessing.
- Each translation unit is then passed to the compiler for further processing.

### Compiler
- Reads a translation unit and generates an OBJECT FILE.
- Object files contain data and instructions in an intermediate format called object code, that humans wouldn't understand.
- Compilers work one TRANSLATION UNIT at a time, so each TU corresponds to a single object file.
- C++ source → assembly code
- Checks types, syntax, templates, etc.

### Assembly
- Assembly → object file (.o)
- Now it’s machine code, but not a full program.

### Linker 
- Generates programs from OBJECT FILES.
- Linkers are also responsible for finding the libraries you've included within your source code. This is why you need to point the compiler to where your Raylib installation is to compile a game with it in C++.
- The cstdio library comes as part of the standard C++ library implementation packaged with the clang++ compiler on MacOS.
- The cstdio HEADER is separate from the cstdio LIBRARY - the header contains information on how to use the library.
- Combines object files
- Resolves external symbols (like std::cout)
- Produces final executable
- If the linker can't find your code, you get an UNDEFINED SYMBOL error.

## The One Definition Rule (ODR)
- In C++, a non-inline function with external linkage must have exactly one definition in the entire program.
- Declarations can appear many times.
- Definitions (with external linkage) must appear exactly once.


## Function Declaration vs. Definition
- A declaration tells the compiler:
    - The function exists.
    - Its name.
    - Its parameter types.
    - Its return type.
- It does not provide the body.
- A definition provides the actual implementation:
- This generates actual machine instructions in the object file.

## Why Multiple Declarations Are OK
- Because declarations don’t generate machine code.
- They just tell the compiler how to type-check calls.
- So you can declare the same function in:
main.cpp
other.cpp
math.cpp
- No machine code is generated from declarations.

## Why Multiple Definitions Are Not OK
- Because definitions generate machine code.
- And the linker needs: Exactly one global symbol named a given thing.
- If there are two, it doesn’t know which one is “the real one.” - this is SYMBOL RESOLUTION.
