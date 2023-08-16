#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void create();
void insert();
void delete();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n*********Queue operations using linked list*********\n\n");
        printf("1.Create_list\n2.insert an element\n3.Delete an element\n4.Display the queue\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nEnter valid choice??\n");
        }
    }
    return 0;
}

void create()
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
        if (front == NULL)
        {
            front = new_node;
            rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
        printf("Enter the data or -1 to end:");
        scanf("%d", &num);
    }
}

void insert()
{
    struct node *ptr;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &val);
        ptr->data = val;
        ptr->next = NULL;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}

void delete()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nPrinting values:\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
