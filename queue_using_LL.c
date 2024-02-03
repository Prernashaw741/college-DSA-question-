#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to insert an element into the queue (enqueue)
void insert(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    printf("Element %d is inserted into the queue.\n", value);
}

// Function to delete an element from the queue (dequeue)
int delete(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot delete element.\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int deleted = temp->data;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL; // Reset rear if queue becomes empty
    }
    printf("Element %d is deleted from the queue.\n", deleted);
    return deleted;
}

// Function to peek - Get the front element of the queue without removing it
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    }
    return queue->front->data;
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No elements to display.\n");
        return;
    }
    printf("Queue: ");
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, element;

    do {
        printf("\nOptions:\n");
        printf("1: Insert an element (Enqueue)\n");
        printf("2: Delete an element (Dequeue)\n");
        printf("3: Peek\n");
        printf("4: Display the queue\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(&queue, element);
                break;
            case 2:
                delete(&queue);
                break;
            case 3:
                element = peek(&queue);
                if (element != -1) {
                    printf("Front element of the queue: %d\n", element);
                }
                break;
            case 4:
                displayQueue(&queue);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
