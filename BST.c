#include <stdio.h>
#include <stdlib.h>

// Structure for a node in BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert an element into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform Preorder traversal of BST
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform Inorder traversal of BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform Postorder traversal of BST
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the smallest element in BST
int findSmallest(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty.\n");
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

// Function to find the largest element in BST
int findLargest(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty.\n");
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

// Function to find the node with the minimum value in a given BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to count the total number of nodes in BST
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to deallocate memory of BST nodes
void deallocateTree(struct Node* root) {
    if (root != NULL) {
        deallocateTree(root->left);
        deallocateTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nOptions:\n");
        printf("1: Insert an element\n");
        printf("2: Preorder traversal\n");
        printf("3: Inorder traversal\n");
        printf("4: Postorder traversal\n");
        printf("5: Find smallest element\n");
        printf("6: Find largest element\n");
        printf("7: Delete an element\n");
        printf("8: Count the total number of nodes\n");
        printf("9: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                value = findSmallest(root);
                if (value != -1) {
                    printf("Smallest element: %d\n", value);
                }
                break;
            case 6:
                value = findLargest(root);
                if (value != -1) {
                    printf("Largest element: %d\n", value);
                }
                break;
            case 7:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 8:
                printf("Total number of nodes: %d\n", countNodes(root));
                break;
            case 9:
                deallocateTree(root);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}
