// WAP to display the linked list by inserting Nodes at Left hand side.


#include <stdio.h>
#include <stdlib.h>

struct Node{      // structure of a Node
    int data;
    struct Node *next;
}
*first=NULL;

void create(int value){
    
    // create a space to the Node
    // Function to insert a node at the left-hand side (beginning) of the linked list
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));  

    t->data=value;   // Assign the value to the Node
    t->next=first;   // point the new Node to the next of First Node
    first=t;         // Update the first Node to new Node
}

// Display function to display the Linked list
void display(struct Node *p){

    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int n, value;

    printf("Enter the no of elements\n");
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        printf("Enter %d elements\n", i+1);
        scanf("%d", &value);
        create(value);     // Insert each new node at the beginning
    }

    printf("The linked list is:\n");
    display(first);

    return 0;
}



