#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *first = NULL, *last = NULL;

void create(int A[], int n){
    for(int i = 0; i < n; i++){
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;

        if(first == NULL){
            first = t;
            last = t;
        }
        else{
            last->next = t;
            last = t;
        }
    }
}

void display(struct Node *p){
    if (first == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void menu() {
    int choice;
    int n;
    int A[100];  // Maximum size for the array
    while(1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &A[i]);
                }
                create(A, n);
                printf("Linked list created successfully.\n");
                break;
            case 2:
                display(first);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main(){
    menu();
    return 0;
}
