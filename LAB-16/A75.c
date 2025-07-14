/*
Write a menu driven program to implement Binary Search Tree (BST) & perform 
following operations:  
• Insert a node 
• Delete a node 
• Search a node 
• Preorder Traversal 
• Postorder Traversal 
• Inorder Traversal 
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
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

struct node* search(struct node* root, int value){
    if(root == NULL) return NULL;

    if(root->data == value) return root;
    else if(root->data > value) return search(root->left, value);
    else return search(root->right, value);
}

struct node* deleteNode(struct node* root, int value){
    if (root == NULL) return NULL;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
        return root;
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
        return root;
    }

    // Found the node
    if (root->right == NULL) return root->left;
    if (root->left == NULL)  return root->right;

    // Node with two children
    struct node* temp = root->left;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    temp->right = root->right;

    struct node* newRoot = root->left;
    free(root);
    return newRoot;
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void main() {
    struct node* root = NULL;
    int choice, val, n;

    printf("Enter number of nodes to insert initially: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    while (1){
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. InOrder\n5. PreOrder\n6. PostOrder\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3: {
                printf("Enter value to search: ");
                scanf("%d", &val);
                struct node* res = search(root, val);
                if (res) printf("Found %d\n", res->data);
                else     printf("Not Found\n");
                break;
            }
            case 4:
                printf("InOrder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("PreOrder Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                printf("PostOrder Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}
