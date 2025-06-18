# include <stdio.h>
# include <string.h>

// copy one string to another using strcpy()

int main()
{
    char str1[] = "Hello!";
    char str2[10];

    strcpy(str2,str1);

    printf("%s\n",str2);

    return 0;
}