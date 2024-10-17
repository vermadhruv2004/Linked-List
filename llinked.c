#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}
*first = NULL;

void insertAtEnd(int value) {
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    if (first == NULL) {
        first = t;
        last = first;
    } else {
        last = first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = t;
    }
}

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("The linked list is: ");
    Display(first);

    return 0;
}
