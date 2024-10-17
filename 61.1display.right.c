// WAP to display circular Linked List by inserting Node at right side.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}
*head=NULL, *last=NULL;

void create(int value){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;
    t->next=NULL;

    if(head==NULL){
        head=t;
        last=t;
        last->next=head;
    }

    else{
        last->next=t;
        last=t;
        last->next=head;
    }
}

void display(struct Node *p){
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);
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

    printf("Circular Linked ist is :\n");
    display(head);

    return 0;
}