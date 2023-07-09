// <"inserting new node at the end">>

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
int new_insert();
int display();
int main()
{

    int option;
    printf("Enter\n1.create\n2.display\n3.New_insert\n4.Exit\n");
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
            new_insert();
            break;

        case 4:
            exit(0);


        default:
            printf("Enter the option in the range 1 to 4");
            break;
        }

    } while (option != 4);
    return 0;
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
        new_node->next = NULL;
        if (start == NULL)
        {

          start = new_node;
            ptr = new_node;
        }

        else
        {

           ptr->next = new_node;
            ptr = new_node;
        }
        printf("\nEnter the data:");
        scanf("%d", &num);
    }
}
int new_insert()
{

    struct node *new_node , *ptr = start;
    int val;
    printf("Enter the data:");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
     new_node->next = NULL;
    ptr = start;

    while(ptr->next!=NULL){
        ptr = ptr -> next;
    }
    ptr ->next = new_node;
}
int display()
{
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return 0;
    }
    struct node *ptr = start;
    printf("Linked list: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}