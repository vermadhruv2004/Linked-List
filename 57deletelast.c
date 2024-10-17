// WAP to delete last Node from a Linked List.

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

void deleteattail(){
    if(first==NULL){
        printf("List is empty, nothing to delete\n");
        return;
    }

    if(first->next==NULL){           // If there is only one Node.
        free(first);
        first=NULL;
        return;
    }

    struct Node *p=first;

    while(p->next->next!=NULL){
        p=p->next;
    }

    free(p->next);

    p->next=NULL;

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

    deleteattail();

    printf("Linked list after deletion is :\n");
    display(first);

    return 0;
}