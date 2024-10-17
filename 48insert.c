// Inserting an elements at a particular position in a existing Linked List userdefined code.

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

int count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void insert(struct Node *p, int index, int x){

    if(index<0 || index>count(p)){
        printf("Invalid Index\n");
        
    }

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0){
        t->next=first;
        first=t;
    }

    else{
        p=first;
        for(int i=0;i<index-1 && p!=NULL; i++){
            p=p->next;
        }

       
            t->next=p->next;
            p->next=t;
            if(p==last){      //  if(t->next==NULL)
               last=t;
            }
        
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int n,value,index,x;

    printf("Enter the no of elements\n");
    scanf("%d", &n);
    printf("\n");

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }
    printf("Linked list before insertion is :\n");
    display(first);
    printf("\n");
   
   
    printf("Enter the index in which you want to insert the elements\n");
    scanf("%d", &index);

    printf("Enter the elements you want to insert\n");
    scanf("%d", &x);

    insert(first,index,x);

    printf("Linked list after insertion is :\n");
    display(first);

    return 0;

}