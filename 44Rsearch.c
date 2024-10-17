// WAP to implement linear search using recursive function by inserting Nodes at left side.

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

struct Node *(search(struct Node *p, int key)){

    if(p==0){
        return 0;
    }

    if(key==p->data){
        return p;
    }

    return search(p->next,key);
}

int main(){
    int n,value;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    struct Node *temp=search(first,4);

    if(temp){
        printf("Key is found %d\n", temp->data);
    }

    else{
        printf("Key is ot found\n");
    }

    return 0;
}
