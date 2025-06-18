#include <stdio.h>
#include <string.h>

// compare two strings using strcmp()

int main() 
{
    char str1[20];
    char str2[20];

    printf("Enter your first string: ");
    scanf("%s",str1);
    printf("Enter your second string: ");
    scanf("%s",str2);

    // printf("First string: %s\nSecond string: %s\n",str1,str2);

    int result = strcmp(str1,str2);
    printf("Result value: %d\n", result);
    if (result > 0) 
    {
        printf("String 1 is greater.\n");
    }
    else if (result < 0)
    {
        printf("String 2 is greater.\n");
    }
    else
    {
        printf("Both strings are the same.\n");
    }
    
    return 0;
}