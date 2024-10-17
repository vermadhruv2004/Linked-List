// WAP to display circular Linked List by inserting Node at left side using recursion.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}
*head=NULL;

void create(int value){
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));

    t->data=value;

    if(head==NULL){
        head=t;
        head->next=t;
    }

    else{
        struct Node *p=head;

        while(p->next!=head){
            p=p->next;
        }

        t->next=head;
        p->next=t;
        head=t;
    }
}

void Rdisplay(struct Node *p){
    static int flag=0;

    if(p!=head || flag==0){
        flag=1;
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
    flag=0;
}

int main(){
    int n,value;
    printf("Enter no of elemnts\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }


    printf("Circular Linked list is :\n");
    Rdisplay(head);

    return 0;
}