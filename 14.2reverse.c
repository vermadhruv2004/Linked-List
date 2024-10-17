// WAP to print the reverse of a linked list by instering Nodes at Left hand side. (Method-2)

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

void display(struct Node *p){

    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
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
    printf("Enter no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked list in origianl order is:\n");
    display(first);
    printf("\n");

    printf("Linked list in reverse order is: \n");
    reverse(first);

    return 0;
}