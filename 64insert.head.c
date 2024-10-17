// WAP to insert an element on head in a circular linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node{
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
        t->next=head;
    }
    else{
        last->next=t;
        t->next=head;
        head=t;
    }
}

void insert(int x){
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(head==NULL){
        head=t;
        last=t;
        t->next=head;
    }
    else{
        last->next=t;
        t->next=head;
        head=t;
    }
}

void Rdisplay(struct Node *p){

    static int flag=0;
    if(p!=head || flag==0){
        flag=1;
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
    flag=0;
}

int main(){
    int n,value,x;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);\
        scanf("%d", &value);
        create(value);
    }

    printf("Circular linked list before insertion is : \n");
    Rdisplay(head);
    printf("\n");

    printf("Enter the element you want to insert\n");
    scanf("%d", &x);

    insert(x);

    printf("Linked list after insertion is : \n");
    Rdisplay(head);

    return 0;
}