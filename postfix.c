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

// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(MAX_SIZE);
    if (!stack) {
        return -1; // Error in stack creation
    }

    int length = strlen(postfix);
    int operand1, operand2;

    for (int i = 0; i < length; i++) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1; // Division by zero error
                    }
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1; // Invalid operator error
            }
        }
    }

    int result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    // Removing '\n' character from the input string
    postfix[strcspn(postfix, "\n")] = '\0';

    int result = evaluatePostfix(postfix);

    if (result != -1) {
        printf("Result of evaluation: %d\n", result);
    }

    return 0;
}
