#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL, *last = NULL;

// Function to insert a node at the right side (end) of the circular linked list
void insertAtRight(int value) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    
    if (head == NULL) { // If list is empty
        head = t;
        last = t;
        last->next = head; // Make it circular
    } else {
        last->next = t;    // Last node's next points to new node
        last = t;          // Update last to new node
        last->next = head; // Maintain circular nature by pointing last node to head
    }
}

// Function to count the number of nodes in the circular linked list
int count(struct Node *p) {
    int c = 0;
    if (head == NULL) return 0; // If the list is empty, return 0

    do {
        c++;
        p = p->next;
    } while (p != head);  // Stop counting when back at head
    return c;
}

// Function to display the elements of the circular linked list
void display(struct Node *p) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

int main() {
    int n, value;

    printf("Enter the number of elements\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d\n", i + 1);
        scanf("%d", &value);
        insertAtRight(value);  // Insert each element at the right side (end)
    }

    printf("Circular linked list after inserting at the right side is:\n");
    display(head);

    return 0;
}
