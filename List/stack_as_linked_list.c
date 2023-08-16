#include <stdio.h>
#include <stdlib.h>
int create();
int push();
int pop();
int display();
struct node
{
    int val;
    struct node *next;
};
struct node *top;

int main()
{
    int choice = 0;
    printf("\n*********Stack operations using linked list*********\n");
    printf("\n----------------------------------------------\n");
    while (choice != 5)
    {
        printf("\n\nChose one from the below options...\n");
        printf("\n1.Create_list\n2.Push\n3.Pop\n4.Display\n5.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:

            create();
            break;

        case 2:

            push();
            break;

        case 3:

            pop();
            break;

        case 4:

            display();
            break;

        case 5:

            exit(0);
            break;

        default:

            printf("Please Enter from range 1 to 5!! ");
        }
    }
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
        new_node->val = num;
        if (top == NULL)
        {

            new_node->next = NULL;
            top = new_node;
        }

        else
        {

            ptr = top;
            while (ptr->next != NULL)

                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\nEnter the data:");
        scanf("%d", &num);
    }
}
int push()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("not able to push the element");
    }
    else
    {
        printf("Enter the value:");
        scanf("%d", &val);
        if (top == NULL)
        {
            ptr->val = val;
            ptr->next = NULL;
            top = ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = top;
            top = ptr;
        }
        printf("Item pushed.");
    }
}

int pop()
{
    int item;
    struct node *ptr;
    if (top == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = top->val;
        ptr = top;
        top = top->next;
        free(ptr);
        printf("Item popped.");
    }
}
int display()
{
    int i;
    struct node *ptr;
    ptr = top;
    if (ptr == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->val);
            ptr = ptr->next;
        }
    }
}