#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void preOrder(struct node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

struct node* buildTree() {
    int value;
    printf("Enter data: ");
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


void main(){
    struct node* root = NULL;
    root = buildTree();

    printf("Dynamicaly(recursivaly) Traversal: ");
    printf("PreOrder Traversal: ");
    preOrder(root);
    printf("\n");
    
    printf("inOrder Traversal: ");
    inOrder(root);
    printf("\n");
    
    printf("PostOrder Traversal: ");
    postOrder(root);
    printf("\n");
    
    // struct node* p = createNode(1);        
    // struct node* p1 = createNode(2);        
    // struct node* p2 = createNode(3);        
    // struct node* p3 = createNode(4);        
    // struct node* p4 = createNode(5);        

    // p->left = p1;
    // p->right = p2;
    // p1->left = p3;
    // p2->right = p4;

    // printf("By createNode Traversal: ");
    // printf("PreOrder Traversal: ");
    // preOrder(p);
    // printf("\n");

    // printf("inOrder Traversal: ");
    // inOrder(p);
    // printf("\n");

    // printf("PostOrder Traversal: ");
    // postOrder(p);
}