#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Initialize queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

// Insert element into the queue (enqueue)
void insert(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot insert element.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // If queue is empty, set front to 0
    }
    queue->rear++;
    queue->items[queue->rear] = value;
    printf("Element %d is inserted into the queue.\n", value);
}

// Delete element from the queue (dequeue)
int delete(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot delete element.\n");
        return -1;
    }
    int deleted = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1; // Reset front and rear if queue becomes empty
    }
    printf("Element %d is deleted from the queue.\n", deleted);
    return deleted;
}

// Peek - Get the front element of the queue without removing it
int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Display the queue
void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No elements to display.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
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
