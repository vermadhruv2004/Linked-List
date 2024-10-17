// Inserting an elements at a particular position in a existing Linked List.

#include <stdio.h>
#include <stdlib.h>

struct Node {
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

int count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}


void insert(struct Node *p, int index, int x){

    if(index<0 || index>count(p)){    // Invalid Index
        printf("Invalid Index\n");
        return;
    }

    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;

    if(index==0){
        temp->next=first;
        first=temp;
    }

    else{
        p=first;
        for(int i=0;i<index-1 && p!=NULL;i++){
            p=p->next;
        }

        if(p!=NULL){
            temp->next=p->next;
            p->next=temp;
            if(temp->next==NULL){   // If inserting at the end, update `last`
                last=temp;
            }
        }
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int n,value;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    insert(first,4,109);    // Example insertion at index 4
    Display(first);

    return 0;
}