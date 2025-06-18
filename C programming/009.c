#include <stdio.h>

int main() {
    int a = 10;

    printf("The value of a: %d\n", a);
    printf("The address of a: %p\n", &a);
    //printf("The memory of a shifted left 1: %p", (&a << 1));
    printf("The value of a shifted left 1: %d\n", (a << 1));

    return 0;
}
/*
128 - 64 - 32 - 16 | 8 - 4 - 2 - 1
10 = 00001010
20 = 00010100
*/