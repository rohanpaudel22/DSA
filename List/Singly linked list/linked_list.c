// creating singly linked list>>

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
int main()
{

    int option;
    printf("Enter\n 1.create\n 2.display\n 3.Exit\n");
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
            exit(0);

        default:
            printf("Enter the option in the range 1 to 3");
            break;
        }

    } while (option != 3);
}

int create()
{

    struct node *new_node, *ptr;
    int num;
    printf("Enter the data or -1 to end:");
    scanf("%d", &num);
    while (num!= -1)
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
int display()
{
    struct node *ptr = start;
    while (ptr!= NULL)
    {

        printf("\t%d", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}