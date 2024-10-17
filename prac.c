#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

// Function to create and add a node at the end of the list
void create(int value) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    if (first == NULL) {
        first = t;
        last = t;
    } else {
        last->next = t;
        last = t;
    }
}

// Function to count the number of nodes in the linked list
int count(struct Node *p) {
    int c = 0;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

// Function to find and print the middle node
void printMiddle(struct Node *p) {
    struct Node *slow = p;
    struct Node *fast = p;

    // Move 'fast' two steps and 'slow' one step until 'fast' reaches the end
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("The middle node is: %d\n", slow->data);
}

int main() {
    int n, value;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    // Create the linked list by inserting elements at the end
    for (int i = 0; i < n; i++) {
        printf("Enter element %d:\n", i + 1);
        scanf("%d", &value);
        create(value);
    }

    printf("Length of the linked list is: %d\n", count(first));
    
    // Print the middle node
    printMiddle(first);

    return 0;
}
