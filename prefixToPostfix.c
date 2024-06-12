#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int is_empty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, char data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

char pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }

    Node *temp = stack->top;
    char popped_data = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped_data;
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int is_operator(char character) {
    switch (character) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        default:
            return 0;
    }
}

char *convert_expression(char *infix_expression) {
    Stack *stack = create_stack();
    char *postfix_expression = (char *)malloc(sizeof(char) * strlen(infix_expression) + 1);
    int i = 0, j = 0;

    while (infix_expression[i] != '\0') {
        if (isalpha(infix_expression[i])) {
            postfix_expression[j++] = infix_expression[i++];
        } else if (is_operator(infix_expression[i])) {
            while (!is_empty(stack) && precedence(infix_expression[i]) <= precedence(stack->top->data)) {
                postfix_expression[j++] = pop(stack);
            }
            push(stack, infix_expression[i++]);
        } else if (infix_expression[i] == '(') {
            push(stack, infix_expression[i++]);
        } else if (infix_expression[i] == ')') {
            while (!is_empty(stack) && stack->top->data != '(') {
                postfix_expression[j++] = pop(stack);
            }
            if (!is_empty(stack)) {
                pop(stack);
            }
            i++;
        }
    }

    while (!is_empty(stack)) {
        postfix_expression[j++] = pop(stack);
    }

    postfix_expression[j] = '\0';
    return postfix_expression;
}

int main() {
    char infix_expression[] = "a+b*(c^d-e)^(f+g*h)-i";
    char *postfix_expression = convert_expression(infix_expression);
    printf("Postfix expression: %s\n", postfix_expression);
    free(postfix_expression);
    return 0;
}