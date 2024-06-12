#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}

int applyOperation(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evaluatePrefix(char* prefix) {
    Stack* stack = createStack(strlen(prefix));
    int i = strlen(prefix) - 1;
    while (i >= 0) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0');
        } else {
            int b = pop(stack);
            int a = pop(stack);
            push(stack, applyOperation(prefix[i], a, b));
        }
        i--;
    }
    return pop(stack);
}

int main() {
    char prefix[] = "*-A/BC-/AKL";
    int result = evaluatePrefix(prefix);
    printf("Result of %s: %d\n", prefix, result);
    return 0;
}