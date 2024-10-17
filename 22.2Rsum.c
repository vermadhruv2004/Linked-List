// WAP to print the sum of no of Nodes Recursively in a Linked List by inserting Nodes at left side.
// (Method-2)

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

    if(p==0){
        return 0;
    }

    return sum(p->next)+p->data;
}

int main(){
    int n,value;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d value\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Sum of elements is %d\n", sum(first));

    return 0;
}


