#include <cstdio>

// Type exploration

// This function doesn't necessarily need to return an int - sizeof() returns a specific number of format size_t
void printsizeoftype(){
    printf("Size of int: %zu\n", sizeof(int));  // %zu is the specific format for interpolating size_t values into strings that printf needs
    printf("Size of long: %zu\n", sizeof(long));
    printf("Size of long long: %zu\n", sizeof(long long));
    printf("Size of float: %zu\n", sizeof(float));
    printf("Size of double: %zu\n", sizeof(double));
    printf("Size of char: %zu\n", sizeof(char));
    printf("Size of bool: %zu\n", sizeof(bool));
    printf("Size of size_t: %zu\n", sizeof(size_t));
    printf("Size of void*: %zu\n", sizeof(void*));


    return; //void functions don't need the exit code.
}

// Declaring variables


// C uses the traditional way of initializing a variable, often with parentheses ()
int num1 = 42;
char ch1 = 'A';

// C++ Uniform Initialization utilizes a more modern version using curly braces {}
// Value of the variable determined by enclosed expressions.
// Generally recommended for new code because it stops it being confused with assignment operations.
// It also stops narrowing conversions happening which helps in engine-level code. Forces you to be explicit!
int num2 {42};
char ch2 {'A'};

//uninitialized variable - intialization establishes an object's state, with their detault value.
int num3;
char ch3;

//zero-initialized variable - kinda self-explanatory - variable initialized with a value of 0.
int num4 {0};
double price1 = 0.0;



int main(){
    printsizeoftype(); // Calling declared function above. No argument needed.

    return 0;
}