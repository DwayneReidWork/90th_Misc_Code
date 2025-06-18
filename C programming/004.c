#include <stdio.h>

int main() {
    int var = 10;
    int *ptr;

    ptr = &var;

    printf("Value of var: %d\n", var);
    printf("Address of var: %p\n", (void*)&var);
    printf("Address of var without void: %p\n\n", &var);

    printf("Value stored in ptr: %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);
    printf("Value stored in ptr without void: %p\n", ptr);

    return 0;
}