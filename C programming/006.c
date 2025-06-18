#include <stdio.h>

int *largerNumber(int *a, int *b) {
    printf("a: %p, b: %p\n", a, b);
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {
    int num1 = 100;
    int num2 = 20;

    int *larger = largerNumber(&num1, &num2);

    printf("The larger number is: %d\n", *larger);

    return 0;
}