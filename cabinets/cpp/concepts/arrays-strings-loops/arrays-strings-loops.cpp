#include <cstdio>
#include <cstddef>

// The following declaration declares an array of 100 int objects.
int example_array1[100];

// Using curly brace syntax, this declaration declares an array of 4 objects at GLOBAL SCOPE..
int example_array2[] = { 1, 2, 3, 4};

// The purpose of this function is to demonstrate accessing array elements.
void accessing_arrays() {
    printf("The third element of the example_array2 array is %d.\n", example_array2[2]); // This is accessing the third element of the GLOBALLY scoped example_array2, at index 2.
    int example_array3[] = { 2, 3 , 4, 5}; // This array is LOCALLY scoped WITHIN the accessing_arrays function.
    printf("The third element of the example_array3 array is %d.\n", example_array3[2]); // This is accessing the third element of the LOCALLY scoped example_array3, at index 2.
    example_array3[2] = 100; // This is reassigning the value of whatever is at index 2 (currently the number 4) in example_array3 to 100.
    printf("The third element of the example_array3 array is %d.\n\n", example_array3[2]); // This should now print 100 instead of 4.

    return;
}

// The purpose of this function is to demonstrate using a for loop to find the maximum of an array.
void using_a_for_loop(){
    unsigned long maximum = 0; // Establishes a variable maximum to hold the value we're looking for.
    unsigned long values[] = { 10, 50, 20, 40, 0}; // This is the array we're looking through to find the maximum.
    /* Note in the below loop, you need to indicate the type still and use semi colons as separators - this WILL screw you up at compile time if you ignore it.
    size_t i=0 is the init atatement, i < 5 is the conditional, i++ is the iteration statement*/
    // We use size_t here because it can index any value within it, it's the technically correct option.
    for(size_t i=0; i < 5; i++){
        if(values[i] > maximum) maximum = values[i]; // Until i < 6, this loop will execute the following code, and the conditional evaluates to false.
    }
    printf("The maximum value of the values array is %lu.\n\n", maximum);

    return;
}

// The purpose of this function is to demonstate using a different, improved form of for loop, for reference purposes.
void using_the_rangebased_for_loop(){
    unsigned long maximum2 = 0;
    unsigned long values2[] = { 10, 50, 100, 60, 40};
    for(unsigned long value : values2){
        if (value > maximum2) maximum2 = value;
    }
    printf("The maximum value of the values2 array is %lu.\n\n", maximum2);

    return;
}

// Using as an example from C++ Crash Course, the following declarations are for string literals  in english and Chinese, as string literals support Unicode.
char english[] = "A book holds a house of gold.";
char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

void using_strings(){
    char house[] = "a house of gold.";
    printf("A book holds %s\n\n", house);
}

void using_strings2(){
    char house2[] = "a " "second " "house " "of " "silver.";
    printf("A second book holds %s\n\n", house2);
}




int main(){
    accessing_arrays();
    using_a_for_loop();
    using_the_rangebased_for_loop();
    using_strings();
    using_strings2();

    return 0;
}

