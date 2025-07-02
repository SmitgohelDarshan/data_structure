/*
Write a program to remove the duplicates nodes from given sorted Linked List. 
• Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
• Output: 1 → 6 → 13 → 27
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};


void display(struct node* first)
{
    struct node* save=first;

    while(save!=NULL)
    {
        printf("%d ",save->data);
        save=save->link;
    }
}



struct node* insertAtLast(struct node* first)
{
    struct node* save=first;
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    int x;
    scanf("%d",&x);
    newNode->data=x;
    newNode->link=NULL;
    if(first==NULL)
    {
        return newNode;
    }

    while (save->link!=NULL)
    {
        save=save->link;
    }

    save->link=newNode;
    return first;
    
}

struct node* deleteDuplicates(struct node* first)
{
    if (first == NULL) return NULL;

    struct node* curr = first;

    while (curr->link != NULL) {
        if (curr->data == curr->link->data) {
            //duplicate found: unlink and free it 
            struct node* dup = curr->link;
            curr->link = dup->link;
            free(dup);
        } else {
            curr = curr->link;
        }
    }
    return first;
}


void main()
{
    int n;
    printf("Enter the no. of values you want to add: ");
    scanf("%d",&n);

    struct node * first=(struct node*)malloc(sizeof(struct node));
    first=NULL;
    for(int i=0;i<n;i++)
    {
        first=insertAtLast(first);
    }

    first=deleteDuplicates(first);

    display(first);
}