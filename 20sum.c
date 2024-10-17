// WAP to print the sum of no of Nodes in a Linked List by inserting Nodes at left Side.

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

int sum(struct Node *p){

    int sum=0;

    while(p!=NULL){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int main(){
    int n,value;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d eleemts\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Sum of elements is %d\n", sum(first));

    return 0;
}
