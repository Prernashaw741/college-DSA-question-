#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
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
int peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to push an element onto the stack
void push(struct Stack* stack, int operand) {
    stack->array[++stack->top] = operand;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0';
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to perform arithmetic operations
int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            printf("Invalid operator\n");
            exit(EXIT_FAILURE);
    }
}

// Function to evaluate prefix expression
int evaluatePrefix(char* prefix) {
    struct Stack* stack = createStack(MAX_SIZE);
    if (!stack) {
        return -1; // Error in stack creation
    }

    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0');
        } else if (isOperator(prefix[i])) {
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            int result = performOperation(operand1, operand2, prefix[i]);
            push(stack, result);
        }
    }

    int finalResult = pop(stack);
    free(stack->array);
    free(stack);
    return finalResult;
}

int main() {
    char prefix[MAX_SIZE];

    printf("Enter prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);

    // Removing '\n' character from the input string
    prefix[strcspn(prefix, "\n")] = '\0';

    int result = evaluatePrefix(prefix);

    printf("Result of evaluation: %d\n", result);

    return 0;
}
