#include <cstdio> // This program, an amalgam of the examples from C++ Crash Course, only uses printf, which comes from this library.

/* The goal of this function is to assign several integer variables of different integer literal types, 
and prints them with the appropriate format specifier, to serve as a reference. */
void integer_types(){
    unsigned short a = 0b10101010; // 0b prefix - Binary integer literal representation of the number 170 - C++ has this hardcoded into it.
    printf("%hu\n", a); // %hu is the printf format specifier for this type of unsigned int in binary.
    int b = 0123; // 0 prefix - Octal integer literal presentation of the number 83 - C++ has this hardcoded into it too.
    printf("%d\n", b); // %d is the printf format specifier for an integer like this.
    unsigned long long c = 0xFFFFFFFFFFFFFFFF; // 0x prefix - Hexadecimal integer literal presentation of the number 18446744073709551615 - C++ has this hardcoded into it, too.
    printf("%llu\n\n", c); // %llu is the printf format specifier for unsigned long long ints.

    return;
}

/*The goal of this function is to assign several floating point variables and
then print them with the appropriate format specifier, to server as a reference.*/
void floatingpoint_types(){
    double an = 6.0332409e23; // You can use scientific notation in literals. as long as you dont use any spaces between the base and exponential portions.
    printf("Avogadro's number: %le,  %lf, %lg \n", an, an , an); // Use %le for scientific notation, %lf for decimal representation, %lg auto-selects based on precision.
    float hp = 9.75; // Floats, when passed to printf get promoted to doubles.
    printf("Hogwarts' Platform: %e, %f, %g \n\n", hp, hp, hp); // As a general rule, use %g to print floating-point types.

    return;
}

/* The goal of this function is to assign seeral character-typed variables and print them. */
void char_types(){
    char x = 'M'; // Standard char literal type, you'll use this 99% of the time.
    wchar_t y = L'Z'; // utilizes L prefix due to wchar_t type.
    printf("Windows binaries start with %c%lc. \n\n", x, y);

    return;
}

/* The goal of this function is to assign bool variables and use the int format specifiers to print true and false values.*/
void bool_type(){
    bool b1 = true; // b1 is true
    bool b2 = false; // b2 is false
    printf("B1 is true if the number is 1: %d, B2 is false if the number is 0: %d\n\n", b1, b2);

    return;
}


/* The goal of this function is to utilize comparison operators to produce Booleans and show how they can be used to print True or False ints.*/
void comparison_ops(){
    printf("If you see a 1 at the end of a comaprison statement, it means the operator returned a Bool true.\n");
    printf("If you see a 0 at the end of a comaprison statement, it means the operator returned a Bool false.\n");
    printf("7 == 7: %d\n", 7 == 7);
    printf("7 != 7: %d\n", 7 != 7);
    printf("10 > 20: %d\n", 10 > 20);
    printf("10 >= 20: %d\n", 10 >= 20);
    printf("10 < 20: %d\n", 10 < 20);
    printf("20 <= 20: %d\n\n", 20 <= 20);

    return;
}

/*The goal of this function is to just demonstrate usage of the logical operators in context, 
and print them using the appropriate format specifiers.*/
void logical_ops() {
    printf("Logical operators return 1 for true and 0 for false.\n\n");

    // Unary: !
    printf("!true: %d\n", !true);
    printf("!false: %d\n\n", !false);

    // Binary: &&
    printf("true && true: %d\n", true && true);
    printf("true && false: %d\n", true && false);
    printf("false && false: %d\n\n", false && false);

    // Binary: ||
    printf("true || false: %d\n", true || false);
    printf("false || false: %d\n\n", false || false);

    // Using comparisons with logical operators
    printf("(7 == 7) && (10 < 20): %d\n", (7 == 7) && (10 < 20));
    printf("(7 != 7) || (10 > 20): %d\n\n", (7 != 7) || (10 > 20));

    // Ternary operator
    printf("Think of these as following this logic - if (5>3) is true, then print 100, if it's false print 200.\n");
    printf("(5 > 3) ? 100 : 200: %d\n", (5 > 3) ? 100 : 200);
    printf("(2 > 3) ? 100 : 200: %d\n", (2 > 3) ? 100 : 200);

    return;
}




int main(){
    integer_types();
    floatingpoint_types();
    char_types();
    bool_type();
    comparison_ops();
    logical_ops();
}

