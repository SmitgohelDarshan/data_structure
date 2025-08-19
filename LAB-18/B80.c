//smallest and largest elements in BST.
// Smallest and Largest elements in BST using Recursion
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
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

int smallestFind(struct node* root) {
    if (root->left == NULL) return root->data;  
    return smallestFind(root->left);
    /*
    while(root->left != NULL) {
        root = root->left;
    }
    return root->data;
    */
}

int largestFind(struct node* root) {
    if (root->right == NULL) return root->data;  
    return largestFind(root->right);

    /*
    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
    */
}

void main() {
    struct node* root = NULL;
    int choice, val;

    while(1){
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n2. Smallest Find\n3. Largest Find\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2: {
                if (root == NULL) {
                    printf("Tree is empty!");
                } else {
                    int smallest = smallestFind(root);
                    printf("Smallest Element: %d", smallest);
                }
                break;
            }

            case 3: {
                if (root == NULL) {
                    printf("Tree is empty!");
                } else {
                    int largest = largestFind(root);
                    printf("Largest Element: %d", largest);
                }
                break;
            }

            case 4:
                printf("Exiting...\n");
                return;

            default:
                printf("Invalid choice!\n");
        }
    }
}