#include <stdio.h>

int CountOccurrences(const char *str, char character);

int main() {
    char the_string[50];
    char search_charizard;

    printf("Please enter a string to search over: ");
    scanf("%[^\n]s",the_string); // LET'S IGNORE THAT DAMN WHITESPACE
    printf("Please enter a character to search for: ");
    scanf("%s",&search_charizard);

    printf("Input passed.\n");
    int num_occurence = CountOccurrences(the_string, search_charizard);

    printf("The letter \'%c\' occurred %d times.\n", search_charizard, num_occurence);

    return 0;
}

int CountOccurrences(const char *str, char character)
{
    int count = 0;
    while (*str != '\0')
    {
        if (*str == character)
        {
            count++;
        }
        str++;
    }
    return count;
}