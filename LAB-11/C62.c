/* ---------------------------------------------------------
   Remove duplicates from an UNSORTED singly linked list.
   Uses no extra data structures; works in‑place.
   Time  : O(n²)
   Space : O(1)
   ---------------------------------------------------------*/
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

struct node* deleteDuplicates(struct node* head)
{
    struct node* outer = head;

    while (outer != NULL) {
        struct node* prev = outer;
        struct node* inner = outer->link;

        while (inner != NULL) {
            if (inner->data == outer->data) {
                // Duplicate found → remove it
                prev->link = inner->link;
                free(inner);
                inner = prev->link;
            } else {
                prev = inner;
                inner = inner->link;
            }
        }
        outer = outer->link;
    }

    return head;
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