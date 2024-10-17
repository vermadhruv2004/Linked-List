// WAP to implement linear search by inserting Nodes at Right side.

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

// Linear search function to search for a key
struct Node *(search(struct Node *p, int key)){

    while(p!=NULL){

        if(key==p->data){
            return p;         // return address of a Node.
        }
        p=p->next;
    }
    return NULL;           // return NULL if key is not found.
}

int main(){
    int n,value,key;
    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Enter the key  to search\n");
    scanf("%d", &key);

    struct Node *temp= search(first,key);

    if(temp){
        printf("Key is found %d\n", temp->data);
    }
    else{
        printf("Key is not found\n");
    }

    return 0;
}