// WAP to display the linked list Recursively by inserting Nodes at Left side.


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

void Rdisplay(struct Node *p){

   if(p!=NULL){
    printf("%d ", p->data);
    Rdisplay(p->next);
   }

}

int main(){
    int n, value;
    printf("Enter a no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);
    }

    Rdisplay(first);

    return 0;
}