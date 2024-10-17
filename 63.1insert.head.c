// WAP to insert an element on head in a circular linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}
*head=NULL;

void create(int value){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;

    if(head==NULL){
        head=t;
        head->next=t;
    }
    else{
        struct Node *p=head;

        while(p->next!=head){
            p=p->next;
        }

        t->next=head;
        p->next=t;
        head=t;
    }
}

void insertathead(int x){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(head==NULL){
        head=t;
        head->next=t;
    }
    else{
        struct Node *p=head;

        while(p->next!=head){
            p=p->next;
        }

        t->next=head;
        p->next=t;
        head=t;
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
    int n,value,x;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Circular linked list before insertion :\n");
    display(head);
    printf("\n");

    printf("Enter the elements you want to insert\n");
    scanf("%d", &x);

    insertathead(x);

    printf("Circular linked list after insertion is :\n");
    display(head);

    return 0;
}