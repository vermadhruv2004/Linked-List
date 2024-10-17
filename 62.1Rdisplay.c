// WAP to display circular Linked List by inserting Node at right side using recursion.

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

    if(head==NULL){
        head=t;
        last=t;
        last->next=head;
    }

    else{
        last->next=t;
        last=t;
        last->next=head;
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
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list is :\n");
    Rdisplay(head);


    return 0;
}
