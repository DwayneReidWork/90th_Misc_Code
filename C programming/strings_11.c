#include <stdio.h>
#include <string.h>

// Find a substring: find the first occurrence of a substring and print the position where it was found

int main()
{
    const char MY_STRING[] = "This is my string. Hello!";

    char search_word[50];

    printf("Enter word to find in the string: ");
    scanf("%s", search_word);

    // find the address of the search word
    char *location = strstr(MY_STRING, search_word);

    if (strstr(MY_STRING,search_word) != NULL)
    {
        int position = location - MY_STRING;
        printf("The word \'%s\' is found in the string at position %d\n", search_word, position+1);
    }
    else
    {
        printf("Your word was not found in the string.\n");
    }

    printf("Value of position: %s\n", location);
    printf("Value of position: %d\n", location);
    printf("Value of position: %p\n", location);
    printf("Value of position: %c\n", location);
    return 0;
}