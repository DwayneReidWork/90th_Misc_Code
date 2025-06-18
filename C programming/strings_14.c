#include <stdio.h>
#include <string.h>

char *CatString(char *string1, char *string2, int size)
{
    char *result;

    printf("Length of string 1: %d\n", strlen(string1));
    printf("Length of string 2: %d\n", strlen(string2));
    printf("Size of string 1: %d\n", sizeof(string1));
    if ((strlen(string1) + strlen(string2)) < size)
    {
        printf("If statement evaluated to be true.\n");
        result = strncat(string1,string2, (sizeof(string2) - strlen(string1)) - 1);
        return result;
    }
    else
    {
        printf("If statement evaluated to be false.\n");
        return "Not enough space to concatenate.\n";
    }
}

int main()
{
    char str1[48] = "my string literal";
    char str2[] = "another ****ing string literal";
    
    printf("Length of string 1: %d\n", strlen(str1));
    printf("Length of string 2: %d\n", strlen(str2));
    printf("Size of string 1: %d\n", sizeof(str1));

    char *result = CatString(str1, str2, sizeof(str1));
    printf("Size of string 1 (address): %d\n",sizeof(&str1));

    printf("%s\n", result);
    for (int i; i < 60; i++)
    {
        printf("Iteration %d: %c\n", i, result[i]);
        if (result[i] == '\0')
        {
            printf("\tIs null character.\n");
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c => %c\n", 'a'+i, ('a'+i)-32);
    }
    // printf("%c\n", 'a'-32);
    return 0;
}