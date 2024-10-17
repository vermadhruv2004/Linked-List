// WAP to display the linked list by inserting Nodes at right hand side.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;     // pointer is of struct Node type because it points to another Node not int value.
}
*first=NULL, *last=NULL;    // first pointer create in stack to implement Linked list.

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

int main(){
    int n,value;

    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    display(first);

    return 0;
}