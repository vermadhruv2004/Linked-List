// WAP to print the reverse of a linked list by instering Nodes at Right hand side. (Method-2)


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

void reverse(struct Node *p){

    if(p==0){
        return;
    }

    reverse(p->next);
    printf("%d ", p->data);
}

int main(){
    int n,value;
    printf("Enter the no of elemets\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list in reverse order is:\n");
    reverse(first);

    return 0;
}