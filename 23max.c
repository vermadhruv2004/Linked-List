// WAP to print the max node in a linked list by inserting Node at right side.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int max(struct Node *p){
    int max=INT_MIN;

    while(p!=NULL){
        
        if(max<p->data)
        max=p->data;

        p=p->next;
    }

    return(max);
}

int main(){
    int n,value;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Max elemets is %d\n", max(first));

    return 0;
}