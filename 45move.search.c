// WAP to implement search by performing move to front operation in a Node by inserting Node at right side.

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

struct Node *(search(struct Node *p, int key)){

    struct Node *q=NULL;

    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;         // move q on p
        p=p->next;   // move p to next Node
    }
    return NULL;
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int n,value;
    printf("Enter the no of elememts\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n",i+1);
        scanf("%d", &value);
        create(value);
    }

    struct Node *temp=search(first,5);

    if(temp){
        printf("Key is found %d\n", temp->data);
    }
    else{
        printf("Key is not found\n");
    }

    printf("Linked List is:\n");
    display(first);

    return 0;
}