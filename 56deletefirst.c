// WAP to delete first Node from a Linked List.

#include <stdio.h>
#include <stdlib.h>

struct Node {
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

void deleteathead(){
    if(first==NULL){
        printf("List is empty, nothing to delete\n");
        return;
    }

    if(first->next==NULL){
        free(first);
        first=NULL;
        return;
    }

    struct Node *p=first;
    first=first->next;                                 // Move the head pointer to the next node
    printf("Deleted node with value: %d\n", p->data);

    free(p);                                           // Free the memory of the deleted node

}

int main(){
    int n,value;
    printf("Enter the no of element in a Linked list\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list before deletion is :\n");
    display(first);
    printf("\n");

    deleteathead();

    printf("Linked list after deletion is :\n");
    display(first);

    return 0;
}