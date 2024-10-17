// WAP to display the linked list Recursively by inserting Nodes at Right side.


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

    if(p!=NULL){
        printf("%d ", p->data);
        display(p->next);
    }
}

int main(){
    int n,value;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elemnts\n",i+1);
        scanf("%d", &value);
        create(value);
    }

    display(first);

    return 0;
}