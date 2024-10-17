// WAP to insert an element on tail in a circular linked list.

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

void insertattail(int x){
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

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


void display(struct Node *p){
     if(head==NULL){
        printf("List is empty\n");
    }
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);
}

int main(){
    int n,value,x;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list before insertion is : \n");
    display(head);
    printf("\n");

    printf("Enter the element you want to insert\n");
    scanf("%d", &x);

    insertattail(x);

    printf("Circular linked list after insertion is :\n");
    display(head);

    return 0;
    
}