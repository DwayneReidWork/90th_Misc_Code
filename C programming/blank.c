#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5  // Define a maximum stack size

typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
    int size;
} Stack;

// Function to create a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Function to check if the stack is full
int isStackFull(Stack* stack) {
    return stack->size >= MAX_STACK_SIZE;
}

// Function to push an item onto the stack with overrun prevention
void pushWithLimit(Stack* stack, void* data) {
    if (isStackFull(stack)) {
        printf("Stack overrun prevented! Cannot push item. Current size: %d\n", stack->size);
        return;
    }

    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    printf("Pushed item onto stack. Current size: %d\n", stack->size);
}

// Function to print stack elements
void printStack(Stack* stack) {
    StackNode* temp = stack->top;
    printf("Stack contents (top to bottom): ");
    while (temp) {
        printf("%d -> ", *((int*)temp->data)); // Assuming int data
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Stack* stack = createStack();

    // Push some integers onto the stack
    int data1 = 10, data2 = 20, data3 = 30, data4 = 40, data5 = 50, data6 = 60;
    pushWithLimit(stack, &data1);
    pushWithLimit(stack, &data2);
    pushWithLimit(stack, &data3);
    pushWithLimit(stack, &data4);
    pushWithLimit(stack, &data5);
    pushWithLimit(stack, &data6);  // This should trigger overrun prevention

    printf("\nFinal Stack:\n");
    printStack(stack);

    return 0;
}
