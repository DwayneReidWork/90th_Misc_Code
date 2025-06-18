/*
Create a program that reads the length and width of a farmer’s field from the user in feet. Display the area of the field in acres. 

Hint: There are 43,560 square feet in an acre.
*/
#include <stdio.h>

int AreaOfField(int array[]) {
    return array[0] * array[1];
}

float ConvertToAcre(int *area) {
    float conversionFactor = 43560;
    return *area / conversionFactor;
}

int main() {
    // declare my variables!
    int length; 
    int width;
    int area;

    // Get my user input!
    printf("Please enter the length and width of your field (in feet): ");
    scanf("%d %d", &length, &width);

    int myArray[] = {length, width};

    // Calculate my area
    area = AreaOfField(myArray);
    float acres = ConvertToAcre(&area);

    // print my area
    printf("The area is %f acres!\n", acres);

    return 0;
}
/*
int AreaOfField(int *a, int b*) {
    int area;

    return area;
}
*/