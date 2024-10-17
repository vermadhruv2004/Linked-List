//  Deletion

#include <stdio.h>
#include <stdlib.h>

struct Node {
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

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void delete(int index){

    if(first==NULL){
        printf("list is empty, can't deleted the element\n");
        return;
    }
    
    struct Node *temp;
    if(index==1){
        temp=first;
        first=first->next;
        free(temp);

        if(first==NULL){
            last=NULL;
        }
    }

    else{
        struct Node *p=first;
        for(int i=0;i<index-2 && p!=NULL; i++){
            p=p->next;
        }

        if(p==NULL || p->next==NULL){
            printf("Invalid position");
            return;
        }

        struct Node *temp=p->next;
        p->next=temp->next;

        if(temp==last){
            last=p;
        }
        free(temp);
    }
}

int main(){
    int n,value,index;
    printf("Enter the elememt of a LL\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d element\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    printf("Linked before deletion is :\n");
    display(first);
    printf("\n");

    printf("Enter the index you want to be deleted\n");
    scanf("%d", &index);

    delete(index);

    printf("Linked after deletion is :\n");
    display(first);
    printf("\n");

    return 0;
}