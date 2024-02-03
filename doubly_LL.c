#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoubleLinkedList {
    struct Node* head;
    struct Node* tail;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize Double Linked List
void initializeDoubleList(struct DoubleLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to display the Double Linked List
void displayList(struct DoubleLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = list->head;
    printf("Double Linked List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display the Double Linked List in reverse
void displayListReverse(struct DoubleLinkedList* list) {
    if (list->tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = list->tail;
    printf("Double Linked List (reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to add/insert a node at the beginning of the Double Linked List
void insertAtBeginning(struct DoubleLinkedList* list, int value) {
    struct Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", value);
}

// Function to add/insert a node at the end of the Double Linked List
void insertAtEnd(struct DoubleLinkedList* list, int value) {
    struct Node* newNode = createNode(value);
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    printf("Node with data %d inserted at the end.\n", value);
}

// Function to add/insert a node at a particular position/location in the Double Linked List
void insertAtPosition(struct DoubleLinkedList* list, int position, int value) {
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

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    printf("Node with data %d inserted at position %d.\n", value, position);
}

// Function to delete a node from the beginning of the Double Linked List
void deleteFromBeginning(struct DoubleLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = list->head;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end of the Double Linked List
void deleteFromEnd(struct DoubleLinkedList* list) {
    if (list->tail == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = list->tail;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to delete a node from a particular position/location in the Double Linked List
void deleteFromPosition(struct DoubleLinkedList* list, int position) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position. Please enter a position greater than 0.\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(list);
        return;
    }

    struct Node* temp = list->head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp == list->tail) {
        deleteFromEnd(list);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("Node deleted from position %d.\n", position);
}

// Function to reverse the Double Linked List
void reverseList(struct DoubleLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot reverse an empty list.\n");
        return;
    }

    struct Node* temp = NULL;
    struct Node* current = list->head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        list->head = temp->prev;
    }

    printf("List reversed.\n");
}

int main() {
    struct DoubleLinkedList list;
    initializeDoubleList(&list);

    int choice, value, position;

    do {
        printf("\nOptions:\n");
        printf("1: Create a list containing 08 values/nodes\n");
        printf("2: Display the list (forward)\n");
        printf("3: Display the list (reverse)\n");
        printf("4: Add/Insert a node at the beginning\n");
        printf("5: Add/Insert a node at the end\n");
        printf("6: Add/Insert node at a particular position/location\n");
        printf("7: Delete a node from the beginning\n");
        printf("8: Delete a node from the end\n");
        printf("9: Delete a node from a particular position/location\n");
        printf("10: Reverse the list\n");
        printf("11: Exit\n");
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
                displayList(&list);
                break;
            case 3:
                displayListReverse(&list);
                break;
            case 4:
                printf("Enter value to add/insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&list, value);
                break;
            case 5:
                printf("Enter value to add/insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&list, value);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter value to add/insert at position %d: ", position);
                scanf("%d", &value);
                insertAtPosition(&list, position, value);
                break;
            case 7:
                deleteFromBeginning(&list);
                break;
            case 8:
                deleteFromEnd(&list);
                break;
            case 9:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&list, position);
                break;
            case 10:
                reverseList(&list);
                break;
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 11);

    return 0;
}
