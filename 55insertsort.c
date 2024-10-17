// Inserting elements in a sorted list at a sorted position by inserting multiple elements.

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

void insertsorted(struct Node *p,int x){

    struct Node *q=NULL;
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=t;
    }
    else{
        while(p!=NULL && p->data<x){
            q=p;
            p=p->next;
        }

        if(p==first){
            t->next=first;
            first=t;
        }

        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int main(){
    int n,value,x, insertions;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list before insertion is: \n");
    display(first);
    printf("\n");

    printf("Enter the no of element you want to insert\n");
    scanf("%d", &insertions);

    for(int i=0;i<insertions;i++){

        printf("Enter elements to insert\n");
        scanf("%d", &x);

        insertsorted(first,x);
    }

    printf("Linked list after insertion is : \n");
    display(first);


    return 0;
}