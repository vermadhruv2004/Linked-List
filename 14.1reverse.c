// WAP to print the reverse of a linked list by instering Nodes at Left hand side. (Method-1)


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}
*first=NULL;

void create(int value){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;
    t->next=first;
    first=t;
}

void display(struct Node *p){

    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void reverse(struct Node *p){

    if(p!=NULL){
        reverse(p->next);
        printf("%d ", p->data);
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

    printf("Original linked list is:\n");
    display(first);
    printf("\n");

    printf("Reverese of a linked list is:\n");
    reverse(first);

    return 0;
}

