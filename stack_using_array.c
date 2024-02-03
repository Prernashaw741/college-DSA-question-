#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Push element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
    printf("Element %d is pushed onto the stack.\n", value);
}

// Pop element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1;
    }
    int popped = stack->items[stack->top];
    stack->top--;
    printf("Element %d is popped from the stack.\n", popped);
    return popped;
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    int choice, element;

    do {
        printf("\nOptions:\n");
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                element = pop(&stack);
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
