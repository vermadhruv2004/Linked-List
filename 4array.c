// creating a linked list using Array inserting a Node on the left hand side of a Linked List.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}
*first=NULL;

void create(int A[], int n){

    for(int i=0;i<n;i++){

        struct Node *t=(struct Node *)malloc(sizeof(struct Node));

        t->data=A[i];
        t->next=first;
        first=t;
    }
}

void display(struct Node *p){

    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int A[]={2,4,6,8,9};

    create(A,5);
    display(first);

    return 0;
}