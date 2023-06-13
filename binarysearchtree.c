#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
}

struct Node* findMinValue(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
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
        struct Node* temp = findMinValue(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNodesWithBothChildren(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if (root->left && root->right) {
        count = 1;
    }
    count += countNodesWithBothChildren(root->left) + countNodesWithBothChildren(root->right);
    return count;
}

int countNodesFromLeft(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left) {
        return 1 + countNodesFromLeft(root->left);
    }
    return 0;
}

void printMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert a node\n");
    printf("2. Search for a key\n");
    printf("3. Delete a node\n");
    printf("4. Count total number of leaf nodes\n");
    printf("5. Count nodes having both children\n");
    printf("6. Count total number of nodes from left side of the root\n");
    printf("7. Exit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, key;
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                printf("Node inserted successfully.\n");
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                struct Node* result = searchNode(root, key);
                if (result != NULL) {
                    printf("Key %d found in the tree.\n", key);
                } else {
                    printf("Key %d not found in the tree.\n", key);
                }
                break;
            case 3:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Node deleted successfully.\n");
                break;
            case 4:
                printf("Total number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 5:
                printf("Total number of nodes having both children: %d\n", countNodesWithBothChildren(root));
                break;
            case 6:
                printf("Total number of nodes from left side of the root: %d\n", countNodesFromLeft(root));
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
