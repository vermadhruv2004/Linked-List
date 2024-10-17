#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;     // Self-referential structure
};

struct Node *Head = NULL, *last = NULL;    // Global pointers

void create(int value) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));   // Allocate memory for new node

    t->data = value;    // Assign value
    t->next = NULL;     // Initialize next to NULL

    if (Head == NULL) {  // Case for the first node
        Head = t;
        last = t;
        last->next = Head;   // Circular link for the first node
    } else {
        t->next = Head;      // Link the new node to the current Head
        Head = t;            // Move Head to the new node
        last->next = Head;   // Maintain circular link by pointing last's next to the new Head
    }
}

void display(struct Node *p) {
    if (Head == NULL) return;  // Check if the list is empty

    struct Node *temp = p;  // Temporary pointer to traverse the list
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != Head);  // Stop when we loop back to the Head node
}

int main() {
    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        create(value);  // Insert each element at the left side (beginning) of the circular linked list
    }

    printf("The circular linked list is: ");
    display(Head);  // Display the linked list

    return 0;
}
