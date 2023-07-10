// inserting new node at the beginning of doubly linked list

// creating doubly linked list>>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{

    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
int create();
int display();
int new_insert();
int main()
{

    int option;
    printf("Enter\n 1.create\n 2.display\n 3.New_insert\n 4.Exit\n");
    do
    {

        printf("Enter your option:\n");
        scanf("%d", &option);
        switch (option)
        {

        case 1:
            create();
            printf(" Doubly Linked list created\n");

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
            new_node->prev = NULL;
            start = new_node;
        }

        else
        {

            ptr = start;
            while (ptr->next != NULL){

                ptr = ptr->next;
            }
            
                ptr->next = new_node;
                new_node->prev = ptr;
                new_node->next = NULL;   
            
        }
        printf("\nEnter the data:");
        scanf("%d", &num);
    }
}
int new_insert(){
    struct node *new_node;
    int val;
    printf("Enter the data:");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
 
}
int display() {
    struct node* ptr = start;
    
    if (start == NULL) {
        printf("Doubly linked list is empty\n");
        return 0;
    }
    
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    
    printf("\n");
    
    return 0;
}