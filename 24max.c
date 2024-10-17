// WAP to find the max Node in a linked list by inserting Node at left side.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int max(struct Node *p){

    int max=INT_MIN;
    while(p!=NULL){

        if(max<p->data){
            max=p->data;
        }
        p=p->next;
    }
    return max;
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

    printf("Max elements is %d\n", max(first));

    return 0;
}
