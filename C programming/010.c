/*
In many jurisdictions a small deposit is added to drink containers to encourage people to recycle them. In one particular jurisdiction, drink containers holding one liter or less have a $0.10 deposit, and drink containers holding more than one liter have a $0.25 deposit.

Write a program that reads the number of containers of each size from the user. Your program should continue by computing and displaying the refund that will be received for returning those containers. Format the output so that it includes a dollar sign and always displays exactly two decimal places.
*/
#include <stdio.h>

int main() {
    // build my initial values
    float liter_minus_equals = .10; // Holds the cent deposit for one liter or less
    float liter_plus = .25; // Holds the cent deposit for more than one liter
    int bottle_minus_equals; // Holds the number of bottles less than or equal to one liter
    int bottle_plus; // Holds the number of bottles greater than one liter
    float refund; // Holds the total refund we will get!

    // get how many containers we have equal or less than one liter
    printf("Enter the number of containers equal to or less than one liter: \n>>> ");
    scanf("%d", &bottle_minus_equals);

    // Get how many containers we have more than liter
    printf("Enter the number of containers greater than one liter: \n>>> ");
    scanf("%d", &bottle_plus);

    // printf("You entered %d for 1 liter or less and %d for more than 1 liter.\n", bottle_minus_equals, bottle_plus);

    refund = (bottle_minus_equals * liter_minus_equals) + (bottle_plus * liter_plus);

    printf("Your refund is: $%.2f\n", refund);

    return 0;
}