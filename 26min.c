// WAP to find the min Node in a linked list by inserting Node at left side.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
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

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int min(struct Node *p){
    int min=INT_MAX;
    while(p!=NULL){

        if(min>p->data){
            min=p->data;
        }
        p=p->next;
    }
    return min;
}

int main(){
    int n,value;
    printf("Enter the no of element in a LL\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list is :\n");
    display(first);
    printf("\n");

    printf("Min element in a LL is %d\n", min(first));

    return 0;
}