# Arrays, Strings and Loops

## Arrays
- Arrays are SEQUENCES of identically typed variables.
- Array types include the contained type and the number of contained elements.
- You weave the information together in the declaration >>> int my_array[100]
- You can use a shortcut to initialize an array >>> int my_second_array[] = { 1, 2, 3 ,4 ,5 }
- You can omit the length of the array because C++ can infer the number of elements in the braces at compile time.

## For Loops
- A for loop lets you iterate the execution of a statement a specified number of times.
- You can stipulate a starting point and other conditions.
- The INIT STATEMENT executes before the first iteration executes, so you can initialize variables used in the for loop.
- The CONDITIONAL is an expression that is evaluated before each iteration. 
    - If it evaluates to true > the loop proceeds. If it evaluates to false > the loop terminates.
- The ITERATION STATEMENT executes after each iteration, which is useful when you must increment a value to cover a range of values.
    - It's commonly i++ in loops where i is the iterated variable.
- The for loop syntax is as follows:

``` cpp
for(init_statement, conditional, iteration_statement){
    -- do thing --
}
```

### Range-based For Loops
- You can eliminate the iterator variable i by using a range-based for loop.
- For certain objects like arrats, for understands how to iterate over the range of values within an object.
- The syntax for a range-based for loop is as follows:

```cpp
for(element-type elenent-name : array-name){
    -- do thing --
}
```
- This code is generally regarded as an improvement on the standard for-loop for readability and speed purposes.

## Number of Elements In An Array
- You can use the sizeof() operator to obtain the total size (in bytes) of an array.
- You can use a trick to determine the number of elements in an array:
    - You divide the SIZE OF THE ARRAY by the SIZE OF A SINGLE CONSITUENT ELEMENT.
    - For example:

```cpp
short array[] = {104, 105, 32, 98, 105, 108, 108, 0};
size_t n_elements = sizeof(array) / sizeof(short);
```
- This trick is in wide use in older C++ code.
- If you must use an array, you can also safely obtain the number of elements using the std::function available in the <iterator> header.

## Strings
- Strings are contiguous blocks of characters.
- A C-STYLE STRING or NULL-TERMINATED STRING has a 0-byte (a null) appended to the end of it to indicate the end of the string.
- Array elements are contigious, you can thus store strings in arrays of character types.
- The format specifier for narrow strings (char*) is %s.
- A C++ STRING LITERAL is a sequence of characters enclosed in double quotes that creates a null-terminated array of const char stored in static storage.
- Consecutive string literals get concatenated together, and any intervening whitespaces or newlines get ignored.
- You can place multiple lines in your souce, and the compiler will treat them as one.
- This is only useful for readability, when you have a long string literal that would span multiple lines in your source code.
- using_strings() and using_strings2() are FUNCTIONALLY IDENTICAL.