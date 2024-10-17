#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} nd;

nd * insert(nd *);
void display(nd * head);

int main()
{
    char choice;
    char conchoice;
    nd * head = NULL;

    menu :

    printf("\nLinked List -->\n");
    printf("\n[I] To Insert Node");
    printf("\n[D] To Display Nodes");
    printf("\nEnter Choice --> ");
    scanf(" %c", &choice);

    switch(choice)
    {
        case 'I':
            head = insert(head);
            break;

        case 'V':
            display(head);
            break;

        default:
            printf("Invalid Choice !");
            break;
    }

    printf("Do You Want To Continue ? ");
    scanf(" %c",&conchoice);

    if(conchoice=='Y')
    {
        goto menu;
    }
    if(conchoice=='N')
    {
        exit(0);
    }

    return 0;
}

nd * insert(nd * head)
{
    int val;
    nd *temp = head;
    nd *new_node = (nd *)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated\n");
        return head;
    }

    printf("Enter Data --> ");
    scanf("%d", &val);

    if (head == NULL)
    {
        new_node->data = val;
        new_node->next = head;
        head = new_node;

        return head;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        new_node->data = val;
        temp->next = new_node;
        new_node->next = NULL;
    }

    return head;
}

void display(nd * head)
{
    if (head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return;
    }

    while (head != NULL)
    {
        printf("\nData --> %d", head->data);
        head = head->next;
    }

    printf("\n");
}