// WAP to implement linear search by inserting Nodes at Left side.

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

// Linear search function to search for a key
struct Node *(search(struct Node *p, int key)){

    while(p!=NULL){

        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int main(){
    int n,value;
    printf("Enter a no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d value\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    struct Node *temp=search(first,5);

    if(temp){
        printf("Key is found %d\n",temp->data);
    }

    else{
        printf("Key is not found\n");
    }

    return 0;
}