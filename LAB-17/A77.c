#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* buildTree() {
    int value;
    printf("Enter data (-1 for NULL): ");
    scanf("%d", &value);

    if(value == -1) return NULL;

    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;

    printf("Enter left child of %d\n", value);
    n->left = buildTree();

    printf("Enter right child of %d\n", value);
    n->right = buildTree();

    return n;
}

bool sameTree(struct node *root,struct node *root2){
    if(root == NULL && root2 == NULL)   return true;
    if(root == NULL || root2 == NULL)    return false;
    
    if(root->data == root2->data){
        bool r = sameTree(root->left, root2->right);
        bool r2 = sameTree(root->right, root2->left);
        return (r && r2);
    }
    else    return false;
}

bool symmetricTree(struct node *root){
    if(root == NULL)   return true;
    bool ans = sameTree(root->left, root->right);
    return ans;
}

void main(){
    struct node* root = NULL;

    printf("Enter tree 1 data: \n");
    root = buildTree();

    if(symmetricTree(root)) printf("\nSymmetric Tree");
    else    printf("\nNot Symmetric Tree");
}