#ifndef STACK_FUNCTIONS_H
#define STACK_FUNCTIONS_H

typedef struct StackNode StackNode;
typedef struct Stack Stack;

Stack* createStack();
int isStackEmpty(Stack* stack);
void push(Stack* stack, void* data);
void* pop(Stack* stack);
void popMultiple(Stack* stack, int n);
void clearStack(Stack* stack);
void printStackDetails(Stack* stack);
void destroyStack(Stack** stackRef);

#endif