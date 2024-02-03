#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add/insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to add/insert a node at the end
void insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add/insert a node at a particular position/location
void insertAtPosition(struct Node* head, int position, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end
void deleteFromEnd(struct Node* head) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
}

// Function to delete a node from a particular position/location
void deleteFromPosition(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to reverse the list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    // Create a list containing 8 values/nodes
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);

    do {
        printf("\nOptions:\n");
        printf("1: Display the list\n");
        printf("2: Add/Insert a node at the beginning\n");
        printf("3: Add/Insert a node at the end\n");
        printf("4: Add/Insert a node at a particular position/location\n");
        printf("5: Delete a node from the beginning\n");
        printf("6: Delete a node from the end\n");
        printf("7: Delete a node from a particular position/location\n");
        printf("8: Reverse the list\n");
        printf("9: Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter value to be inserted at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 3:
                printf("Enter value to be inserted at the end: ");
                scanf("%d", &value);
                insertAtEnd(head, value);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter value to be inserted at position %d: ", position);
                scanf("%d", &value);
                insertAtPosition(head, position, value);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                deleteFromEnd(head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(head, position);
                break;
            case 8:
                head = reverseList(head);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}
