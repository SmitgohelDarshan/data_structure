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
        bool r = sameTree(root->left, root2->left);
        bool r2 = sameTree(root->right, root2->right);
        return (r == true && r2 == true) ? (true) : (false);
    }
    else    return false;
}

void main(){
    struct node* root = NULL;
    struct node* root2 = NULL;

    printf("Enter tree 1 data: \n");
    root = buildTree();

    printf("Enter tree 2 data: \n");
    root2 = buildTree();

    if(sameTree(root, root2))
        printf("\nSame Tree");
    else
        printf("\nNot Same Tree");
}