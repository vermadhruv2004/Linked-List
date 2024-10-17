/* Creating Linked list using Array by inserting Nodes at right side.
   No need of creating a first and rest Node separatelty.
*/


#include <stdio.h>
#include <stdlib.h>

struct Node{         // Creating structure of a Node.
    int data;
    struct Node *next;
}

// Creating first and last pointer, pointed to NULL for implementing a Linked List.
*first=NULL, *last=NULL;  

void create(int A[], int n)   // Create function
{

    struct Node *t;  // temporary pointer which is used to creating a new Node.


    for(int i=0;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));   // creating rest Nodes using for loop.

        t->data=A[i];
        t->next=NULL;

        if(first==NULL){     // If the list is empty, make 't' the first node
            first=t;
            last=t;
        }
        else{
            last->next=t;    // Otherwise, add 't' to the end and update 'last'
            last=t;
        }
        
    }
}

void Display(struct Node *p)     // Display function.
{
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()                       // main() function
{
    int A[]={3,5,7,9,8};
    create(A,5);

    Display(first);

    return 0;
}