#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

void create(int value) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    if (first == NULL) {
        first = t;
        last = t;
        last->next = first;  // Circular link
    } else {
        last->next = t;
        last = t;
        last->next = first;  // Maintain circular link
    }
}

void display(struct Node *p) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = first;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != first);  // Stop when we circle back to the first node
    printf("\n");
}

void delete(int index) {
    if (first == NULL) {
        printf("List is empty, can't delete the element\n");
        return;
    }

    struct Node *temp;
    if (index == 1) {
        temp = first;
        first=first->next;
        last->next = first;  // Maintain circular link
        free(temp);


        if (first == NULL) {  // Single-node case
            last = NULL;
        }

    } else {
        struct Node *p = first;
        for (int i = 0; i < index - 2 && p->next != first; i++) {
            p = p->next;
        }

        if (p->next == first) {
            printf("Invalid position\n");
            return;
        }

        temp = p->next;
        p->next = temp->next;

        if (temp == last) {
            last = p;  // Update last if we delete the last node
        }
        free(temp);
    }
}

int main() {
    int n, value, index;

    printf("Enter the number of elements in the circular linked list:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d:\n", i + 1);
        scanf("%d", &value);
        create(value);
    }

    printf("Circular Linked List before deletion:\n");
    display(first);

    printf("Enter the index you want to delete:\n");
    scanf("%d", &index);

    delete(index);

    printf("Circular Linked List after deletion:\n");
    display(first);

    return 0;
}
