#include <stdio.h>
 #include<stdlib.h>
  #define MAX 5 
  int A[MAX];
int top = -1;
void push();
void pop();
void peek();
void display();
int main()
{
    int choice;
    while (1)
    {
        printf("\n Enter your option:\n 1.push \n 2.pop \n 3.Peek \n 4.display \n 5.exit: \n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter option in the range 1 to 5");
            break;
        }
    }
}
void push()
{

    int data;
    if (top == MAX - 1)
    {
printf("Overflow");
    }
    else
    {
        printf("\n Enter data:");
scanf("%d", &data);
top = top + 1;
A[top] = data;

    }
}



void pop()
{
    int data;
    if (top == -1)

    {
printf("Underflow");
    }
    else
    {
        data = A[top];
printf("Deleted data: %d", data);
top = top - 1;
    }
}


void peek()
{
    if (top == -1)
    {
printf("Underflow");
    }
    else
    {
printf("Top data element: %d", A[top]);
    }
}



void display()
{
    int i;
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {

        printf("Data: \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d \n", A[i]);
        }
    }
}