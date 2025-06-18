#include <stdio.h>

int main() {
    int numbers[5] = {10,20,30,40,50};
    int *ptr = numbers;
    int i;
    int x = 10; // My pre-stored index value

    for (i = 0; i < x; i++) {
        printf("Element of %d: %d\n", i + 1, *(ptr + i));
        printf("Address of element %d: %p\n", i + 1, (ptr + i));
        printf("Value of element %d: %d\n", i+1, numbers[i]);
    }

    
    printf("Address of element %d: %p\n", x + 1, (ptr + x));
    printf("Value stored at element %d: %d\n", x + 1, *(ptr + x)); // This might error out...

    return 0;
}