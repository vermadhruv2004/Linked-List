// WAP to insert element at any position in a circular linked list.

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
        last->next=head;
    }
    else{
        last->next=t;
        last=t;
        last->next=head;
    }
}

int count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
}

void insert(struct Node *p,int index, int x){

    if(index<0 && index>count(p)){
        printf("Invalid Index");
    }

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0){
        if(head==NULL){
            head=t;
            last=t;
            t->next=head;
        }

        else{
            last->next=t;
            t->next=head;
            t=head;
        }
    }

    else{
        p=head;
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;

        if(p==last){
            last=t;
        }
    }

    
    
}

void display(struct Node *p){

     if(head==NULL){
        printf("List is empty\n");
    }
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);
}

int main(){
    int n,value,index,x;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list before insertion is : \n");
    display(head);
    printf("\n");

    printf("Enter the index at which you want to insert the element\n");
    scanf("%d", &index);

    printf("Enter the no of elements\n");
    scanf("%d", &x);

    insert(head,index,x);

    printf("Linked list after insertion is : \n");
    display(head);

    return 0;
}