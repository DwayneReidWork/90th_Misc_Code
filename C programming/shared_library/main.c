#include <stdio.h>

int add(int, int);
int subtract(int, int);

int main() {
    int a = 5, b = 3;
    printf("Add: %d\n", add(a, b));
    printf("Subtract: %d\n", subtract(a, b));
    return 0;
}
