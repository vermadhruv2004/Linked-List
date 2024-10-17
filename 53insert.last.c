// Inserting an elements only at Tail Node by inserting multiple elements.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}
*first=NULL, *last=NULL;

void create(int value){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;
    t->next=NULL;

    if(first==NULL){
        first=t;
        last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void insertattail(int x){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));\
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=t;
        last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}

int main(){
    int n,value,x,insertions;

    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked List before insertion is :\n");
    display(first);
    printf("\n");

    printf("Enter the no of elements you want to insert\n");
    scanf("%d", &insertions);

    for(int i=0;i<insertions;i++){
        printf("Enter %d elements\n",i+1);
        scanf("%d", &x);

        insertattail(x);
    }

    printf("Final linked list after insertion is :\n");
    display(first);

    return 0;
}