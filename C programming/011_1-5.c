#include <stdio.h>


void Exercise_1();
void Exercise_2();
void Exercise_3();
void Exercise_4();
void Exercise_5();
void replaceChar(char *str, char oldChar, char newChar);


int main(){
    int user_input;

    // Get user input for which exercise to demonstrate.
    printf("Make a selection:\n>>> ");
    scanf("%d",&user_input);

    // Use a switch statement to call the exercise requested.
    switch (user_input)
    {
    case 1:
        Exercise_1();
        break;
    case 2:
        Exercise_2();
        break;
    case 3:
        Exercise_3();
        break;
    case 4:
        Exercise_4();
        break;
    case 5:
        Exercise_5();
        break;
    default:
        printf("Invalid input entered.");
        break;
    }

    return 0;
}


void Exercise_1() {
    /*
    Write a C program that declares a string using a char array and prints it to the console.   
    */
    char greeting[] = "Hello, world!";
    printf("%s\n", greeting);
    /*
    Expected output: 
    >>> Hello, world!
    */
}


void Exercise_2() {
    /*
    Implement a function that iterates through a string and prints each character on a new line.
    */
    char greeting[] = "Hello";

    for (int i = 0; greeting[i] != '\0'; i++) {
        printf("%c\n", greeting[i]);
    }

    /*
    Expected output: 
    H
    e
    l
    l
    o
    */

}


void Exercise_3() {
    /*
    Modify a character within a string and print the modified string.
    */
    char greeting[] = "Hello";
    greeting[1] = 'a'; // Change 'e' to 'a'
    printf("%s\n", greeting);

    /*
    Expected output: 
    >>> Hallo
    */
}

void Exercise_4() {
    /*
    Create a string, omit the null terminator, and observe the program's behavior when printing it.
    */
    char greeting[5] = {'H', 'e', 'l', 'l', 'o'}; // No null terminator
    printf("String without null terminator: %s\n", greeting);
    /*
    Expected output: Undefined behavior; might print garbage until it hits a \0
    */
}

void Exercise_5() {
    /*
    Write a function that replaces all occurrences of a specified character in a string with another character. 
    */
    char greeting[] = "Hello, World!";
    replaceChar(greeting, 'o', 'a');
    printf("Modified string: %s\n", greeting);

    /*
    Expected output:
    >>> Modified string: Hella, Warld!
    */

}

void replaceChar(char *str, char oldChar, char newChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}