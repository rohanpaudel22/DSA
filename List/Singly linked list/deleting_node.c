// <<"deleting nodes">>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{

    int data;
    struct node *next;
};

struct node *start = NULL;
int create();
int display();
int delete1();
int delete2();
int delete3();
int delete4();
int main()
{

    int option;
    printf("Enter\n 1.create\n 2.display\n 3.delete_firstnode\n 4.delete_lastnode\n 5.delete_node_afternode\n 6.delete_given_node\n 7.Exit\n");
    do
    {

        printf("Enter your option:\n");
        scanf("%d", &option);
        switch (option)
        {

        case 1:
            create();
            printf("Linked list created\n");

        case 2:
            display();
            break;

        case 3:
            delete1();
            break;

        case 4:
            delete2();
            break;

        case 5:
            delete3();
            break;

        case 6:
            delete4();
            break;

        case 7:
            exit(0);

        default:
            printf("Enter the option in the range 1 to 7");
            break;
        }

    } while (option != 7);
}

int create()
{

    struct node *new_node, *ptr;
    int num;
    printf("Enter the data or -1 to end:");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {

            new_node->next = NULL;
            start = new_node;
        }

        else
        {

            ptr = start;
            while (ptr->next != NULL)

                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\nEnter the data:");
        scanf("%d", &num);
    }
}
// deleting first node

int delete1()
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("Underflow");
    }
    ptr = start;
    start = start->next;
    free(ptr);
}
// deleting last node

int delete2()
{
    struct node *ptr, *preptr;

    if (start == NULL)
    {
        printf("Underflow");
    }
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}
// deleting a node after the given node

int delete3()
{
    struct node *ptr, *preptr;
    int num;
    printf("Enter the data to delete after: ");
    scanf("%d", &num);
    if (start == NULL)
    {
        printf("Underflow");
    }
    ptr = start;
    preptr = ptr;
    while (preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}
// deleting a given node

int delete4()
{
    struct node *ptr, *preptr;
    int num;
    printf("Enter the data to delete: ");
    scanf("%d", &num);

    if (start == NULL)
    {
        printf("Underflow");
    }
    ptr = start;
    preptr = ptr;
    while (ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}
int display()
{
    struct node *ptr = start;
    while (ptr != NULL)
    {

        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}