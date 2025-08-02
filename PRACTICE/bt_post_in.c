#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == value) return i;
    return -1;
}

struct Node* buildFromPostIn(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(rootVal);

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, rootVal);

    root->right = buildFromPostIn(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildFromPostIn(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

struct Node* buildFromPreIn(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = createNode(rootVal);

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, rootVal);

    root->left = buildFromPreIn(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildFromPreIn(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void printInorder(struct Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

int main() {
    int choice;
    struct Node* root = NULL;

    int inorder[]    = {4, 2, 5, 1, 6, 3};
    int postorder[]  = {4, 5, 2, 6, 3, 1};
    int preorder[]   = {1, 2, 4, 5, 3, 6};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    while (1) {
        printf("\n--- Binary Tree Construction Menu ---\n");
        printf("1. Build Tree from Postorder & Inorder\n");
        printf("2. Build Tree from Preorder & Inorder\n");
        printf("3. Inorder Traversal of Tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int postIndex = n - 1;
            root = buildFromPostIn(inorder, postorder, 0, n - 1, &postIndex);
            printf("Tree built from Postorder & Inorder.\n");
        }
        else if (choice == 2) {
            int preIndex = 0;
            root = buildFromPreIn(preorder, inorder, 0, n - 1, &preIndex);
            printf("Tree built from Preorder & Inorder.\n");
        }
        else if (choice == 3) {
            if (root == NULL) {
                printf("Build a tree first.\n");
            } else {
                printf("Inorder Traversal: ");
                printInorder(root);
                printf("\n");
            }
        }
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>

// // Tree Node structure
// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };

// // Create new tree node
// struct Node* createNode(int data) {
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->data = data;
//     node->left = node->right = NULL;
//     return node;
// }

// // Find index of value in inorder[]
// int search(int inorder[], int start, int end, int value) {
//     for (int i = start; i <= end; i++) {
//         if (inorder[i] == value)
//             return i;
//     }
//     return -1;
// }

// // Recursive function to build tree
// struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
//     if (inStart > inEnd)
//         return NULL;

//     // Get root from postorder
//     int rootVal = postorder[*postIndex];
//     (*postIndex)--;

//     struct Node* root = createNode(rootVal);

//     // If it's a leaf node
//     if (inStart == inEnd)
//         return root;

//     // Find root in inorder[]
//     int inIndex = search(inorder, inStart, inEnd, rootVal);

//     // Recur for right and left subtrees
//     root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
//     root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

//     return root;
// }

// // Inorder traversal for verification
// void printInorder(struct Node* root) {
//     if (root) {
//         printInorder(root->left);
//         printf("%d ", root->data);
//         printInorder(root->right);
//     }
// }

// void main() {
//     int inorder[]    = {4, 2, 5, 1, 6, 3};
//     int postorder[]  = {4, 5, 2, 6, 3, 1};
//     int n = sizeof(inorder);

//     int postIndex = n - 1; // Start from last index of postorder
//     struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

//     printf("Inorder traversal of constructed tree: ");
//     printInorder(root);
//     printf("\n");
// }