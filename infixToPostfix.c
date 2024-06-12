#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack data structure
typedef struct {
    int top;
    int size;
    char* array;
} Stack;

// Function to initialize the stack
Stack* create_stack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (char*) malloc(stack->size * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int is_empty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int is_full(Stack* stack) {
    return stack->top == stack->size - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, char item) {
    if (is_full(stack)) {
        printf("Stack is full.\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to check the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
void infix_to_postfix(char str[]) {
    int i, j;
    Stack* stack = create_stack(strlen(str));
    char* postfix = (char*) malloc(strlen(str) * sizeof(char));
    j = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == '(') {
            push(stack, str[i]);
        } else if (str[i] == ')') {
            while (!is_empty(stack) && stack->array[stack->top] != '(') {
                postfix[j++] = pop(stack);
            }
            if (!is_empty(stack) && stack->array[stack->top] != '(') {
                return;
            }
            pop(stack);
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            while (!is_empty(stack) && precedence(stack->array[stack->top]) >= precedence(str[i])) {
                postfix[j++] = pop(stack);
            }
            push(stack, str[i]);
        } else {
            postfix[j++] = str[i];
        }
    }

    while (!is_empty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    printf("The postfix expression is: %s\n", postfix);
}

int main() {
    char str[100];
    printf("Enter the infix expression: ");
    fgets(str, sizeof(str), stdin); // reading the string entered by the user
    str[strcspn(str, "\n")] = '\0'; // removing the new line character from the string

    infix_to_postfix(str);

    return 0;
}