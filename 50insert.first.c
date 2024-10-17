// Inserting an elements only at head Node.

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

void insertathead(int x){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    t->next=first;
    first=t;
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int n,value,x;

    printf("Enter the no of elemenst\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elemenst\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list before insertion is :\n");
    display(first);
    printf("\n");


    printf("Enter the elements to insert before first Node\n");
    scanf("%d", &x);

    insertathead(x);

    printf("Linked list after insertion is: \n");
    display(first);

    return 0;
}