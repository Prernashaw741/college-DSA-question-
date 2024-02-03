#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct CircularLinkedList {
    struct Node *head;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize Circular Linked List
void initializeCircularList(struct CircularLinkedList* list) {
    list->head = NULL;
}

// Function to display the Circular Linked List
void displayList(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = list->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

// Function to add/insert a node at the beginning of the Circular Linked List
void insertAtBeginning(struct CircularLinkedList* list, int value) {
    struct Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        newNode->next = list->head;
        list->head = newNode;
        temp->next = list->head;
    }
    printf("Node with data %d inserted at the beginning.\n", value);
}

// Function to add/insert a node at the end of the Circular Linked List
void insertAtEnd(struct CircularLinkedList* list, int value) {
    struct Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = list->head;
    }
    printf("Node with data %d inserted at the end.\n", value);
}

// Function to add/insert a node at a particular position/location in the Circular Linked List
void insertAtPosition(struct CircularLinkedList* list, int position, int value) {
    if (position <= 0) {
        printf("Invalid position. Please enter a position greater than 0.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(list, value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = list->head;
    int count = 1;

    while (temp->next != list->head && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == list->head && count < position - 1) {
        printf("Position out of bounds.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node with data %d inserted at position %d.\n", value, position);
}

// Function to delete a node from the beginning of the Circular Linked List
void deleteFromBeginning(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = list->head;
    if (temp->next == list->head) {
        list->head = NULL;
        free(temp);
    } else {
        struct Node* lastNode = list->head;
        while (lastNode->next != list->head) {
            lastNode = lastNode->next;
        }
        list->head = temp->next;
        lastNode->next = list->head;
        free(temp);
    }
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end of the Circular Linked List
void deleteFromEnd(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = list->head;
    struct Node* prev = NULL;
    while (temp->next != list->head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == list->head) {
        list->head = NULL;
    } else {
        prev->next = list->head;
    }
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to delete a node from a particular position/location in the Circular Linked List
void deleteFromPosition(struct CircularLinkedList* list, int position) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = list->head;
    struct Node* prev = NULL;
    int count = 1;

    if (position == 1) {
        deleteFromBeginning(list);
        return;
    }

    while (temp->next != list->head && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp->next == list->head && count < position) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", position);
}

// Function to reverse the Circular Linked List
void reverseList(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot reverse an empty list.\n");
        return;
    }

    struct Node *prevNode, *currentNode, *nextNode;
    prevNode = NULL;
    currentNode = list->head;
    nextNode = list->head->next;

    do {
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
    } while (currentNode != list->head);

    list->head->next = prevNode;
    list->head = prevNode;

    printf("List reversed.\n");
}

int main() {
    struct CircularLinkedList list;
    initializeCircularList(&list);

    int choice, value, position;

    do {
        printf("\nOptions:\n");
        printf("1: Create a list containing 08 values/nodes\n");
        printf("2: Display the list\n");
        printf("3: Add/Insert a node at the beginning\n");
        printf("4: Add/Insert a node at the end\n");
        printf("5: Add/Insert node at a particular position/location\n");
        printf("6: Delete a node from the beginning\n");
        printf("7: Delete a node from the end\n");
        printf("8: Delete a node from a particular position/location\n");
        printf("9: Reverse the list\n");
        printf("10: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create a list containing 8 values/nodes
                for (int i = 1; i <= 8; i++) {
                    insertAtEnd(&list, i);
                }
                break;
            case 2:
                printf("Displaying the list: ");
                displayList(&list);
                break;
            case 3:
                printf("Enter value to add/insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&list, value);
                break;
            case 4:
                printf("Enter value to add/insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&list, value);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter value to add/insert at position %d: ", position);
                scanf("%d", &value);
                insertAtPosition(&list, position, value);
                break;
            case 6:
                deleteFromBeginning(&list);
                break;
            case 7:
                deleteFromEnd(&list);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&list, position);
                break;
            case 9:
                reverseList(&list);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 10);

    return 0;
}
