/*
Write a program to construct a binary tree from given Postorder and Preorder 
traversal sequence. 
*/
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

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct node* constructTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;

    // Create root node with current preIndex
    struct node* root = createNode(pre[*preIndex]);
    (*preIndex)++;

    // If single node
    if (l == h || *preIndex >= size)
        return root;

    // Search next preorder element in postorder
    int i = search(post, l, h, pre[*preIndex]);

    if (i <= h) {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
    }
    return root;
}

struct node* constructTree(int pre[], int post[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, post, &preIndex, 0, size - 1, size);
}

void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int pre[n], post[n];
    printf("Enter preorder sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);

    printf("Enter postorder sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    struct node* root = constructTree(pre, post, n);

    printf("Inorder Traversal of constructed tree: ");
    inorder(root);
}