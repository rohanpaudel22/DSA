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
int delete_node();
int display();
int main()
{

    int option;
    printf("Enter\n1.create\n2.display\n3.New_insert\n4.Delete_node\n5.Exit\n");
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
            delete_node();
            break;

        case 5:
                exit(0);    


        default:
            printf("Enter the option in the range 1 to 5");
            break;
        }

    } while (option != 5);
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
int delete_node()
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