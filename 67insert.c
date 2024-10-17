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
    if(head==NULL)
    return 0;
    int c=0;
    do{
        c++;
        p=p->next;
    }
    while(p!=head);
    return c;
}

void insert(struct Node *p, int index, int x){

    if(index<0 || index>count(head)){
        printf("Invalid Index\n");
        return;
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
            t->next=head;
            last->next=t;
            head=t;
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
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);
}

int main(){
    int n,value,index,x,insertions;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list before insertion is :\n");
    display(head);
    printf("\n");

    printf("Enter the no of elements to be inserted\n");
    scanf("%d", &insertions);

    for(int i=0;i<insertions;i++){
        printf("Enter the index to insert the element\n");
        scanf("%d", &index);

        printf("Enter %d element to be inserted\n", i+1);
        scanf("%d", &x);

        insert(head,index,x);

         printf("Linked list after insertion is:\n");
        display(head);
        printf("\n");
    }

    printf("Linked list after insertion is :\n");
    display(head);

    return 0;
}