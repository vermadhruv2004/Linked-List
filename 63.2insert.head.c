// WAP to insert an element on head in a circular linked list using for loop.

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

void insertathead(int x){
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(head==NULL){
        head=t;
        last=t;
        t->next=head;
    }
    else{
        last->next=t;
        t->next=head;
        head=t;
    }
}

void display(struct Node *p){
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);
}

int main(){
    int n,value,x,insertions;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list before inssertion is : \n");
    display(head);
    printf("\n");

    printf("Enter the no of element to be inserted\n");
    scanf("%d", &insertions);

    for(int i=0;i<insertions;i++){
        printf("Enter %d elements to be inserted\n", i+1);
        scanf("%d", &x);

        insertathead(x);
    }

    printf("Linked list after insertion is :\n");
    display(head);

    return 0;
}