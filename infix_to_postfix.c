#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    if (!stack->array) {
        return NULL;
    }
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to return the top element of the stack
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to push an element onto the stack
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0';
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get precedence of the operator
int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return -1;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix) {
    struct Stack* stack = createStack(MAX_SIZE);
    if (!stack) {
        return;
    }

    int length = strlen(infix);
    char postfix[MAX_SIZE];
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression.\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    free(stack->array);
    free(stack);
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Removing '\n' character from the input string
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix);

    return 0;
}
