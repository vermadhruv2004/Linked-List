// Creating linked list using Array. Creating first and remaining Nodes separately.


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}

*first=NULL,*last=NULL;

void create(int A[], int n){

    struct Node *t;

    first=(struct Node *)malloc(sizeof(struct Node));

    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){

        t=(struct Node *)malloc(sizeof(struct Node));

        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
        
    }
}

void display(struct Node *p){

    if(p!=NULL){ 

        printf("%d ", p->data);
        display(p=p->next);

    }
}

int main(){
    int A[]={1,2,3,4,5};

    create(A,5);
    display(first);

    return 0;
}