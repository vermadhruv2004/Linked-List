// WAP to count the no of Nodes in a linked list by inserting Node at left hand side.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}
*first=NULL;

void create(int value){

    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;
    t->next=first;
    first=t;
}

int count(struct Node *p){

    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

int main(){
    int n,value;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n",i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Lenght of a list is %d\n", count(first));

    return 0;
}