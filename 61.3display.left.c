// WAP to display circular Linked List by inserting Node at left side.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}
*head=NULL, *last=NULL;


void create(int value){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;
    t->next=NULL;

    if(head==NULL){       // If list is empty
        head=t;
        last=t;
        last->next=head;         // Make it circular
    }
    else{
        last->next=t;         // Last node now points to the new head
        t->next=head;         // New node points to the current head
        head=t;               // Update head to new node
    }
}

void Rdisplay(struct Node *p){

    static int flag=0;
    if(p!=head || flag==0){
        flag=1;
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
    flag=0;
}

int main(){
    int n,value;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);\
        scanf("%d", &value);
        create(value);
    }

    printf("Circular linked list is : \n");
    Rdisplay(head);

    return 0;
}