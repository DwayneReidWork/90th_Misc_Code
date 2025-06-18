#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Testing program to get user input and then use pointer referencing to store addresses in an array
*/

char* GetUserInput();
void FreeMemory();

int main() 
{
    // char *input_string = GetUserInput();

    // printf("After the function, you entered:\n>>> %s\n", input_string);
    // printf("This ended with a size of %lu bytes.\n", (strlen(input_string) + 1) * sizeof(char));

    // free(input_string);
#if 0
    // run test with getting the size of various pointers
    printf("Size of integer pointer: %lu\n", sizeof(int*));
    printf("Size of char pointer: %lu\n", sizeof(char*));
    printf("Size of float pointer: %lu\n", sizeof(float*));
#endif
    int *random_pointer;
    printf("Address of the test pointer: %p\n",&random_pointer);

    int address_increment = 0;
    int block_increment = 0;
    int *pointer_block = (int*)malloc(10 * sizeof(int*));

    for (int i = 0; i < 1000; i++)
    {
        if (*(pointer_block + block_increment) == '\0')
        {
            printf("Iteration %003d | %p : is null\n", i, pointer_block + block_increment, *(pointer_block + block_increment));
        }
        else
        {
            printf("Iteration %003d | %p : is not null:%c\n", i, pointer_block + block_increment, *(pointer_block + block_increment));
        }
        block_increment += sizeof(int*);
    }

    for (int i = 0, block_increment = 0, address_increment = 0; i < 10; i++)
    {
        printf(
            "Iteration %02d | %p : %p | %p\n", 
            i, 
            &pointer_block, 
            pointer_block + address_increment,
            pointer_block + block_increment
        );

        address_increment++;
        block_increment += sizeof(int*);
    }

    free(pointer_block);

    return 0; 
}

char* GetUserInput()
/*
Get a user input string, allocate space for it, and then return the pointer.

User input is static, but then assigned dynamically, and this dynamic allocation is returned.
Initial input gets scrapped after the function finishes.
*/
{
    char user_input[256]; // allocate a big space because it's just going to get dropped afterwards.
    printf("Enter a string: ");
    scanf("%255s", user_input);

    printf("You entered:\n>>> %s\n",user_input);
    printf("This has a pre-set size of %lu bytes.\n", sizeof(user_input));

    // Create a dynamically allocated space to copy the user input into.
    char *user_string = (char*)malloc((strlen(user_input) + 1) * sizeof(char));
    if (user_string == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }

    strcpy(user_string, user_input);

    return user_string;
}

void FreeMemory()
/*
Simple function that just frees all variables that will be used for memory allocation
*/
{
    // idk might put stuff here, not sure yet.
}