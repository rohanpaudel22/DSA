#include <stdio.h>
#include <stdlib.h>
#define MAX 5
char stack[MAX];
char A[MAX];
int top = -1;
void push(char x);
void pop();
int main()
{
    int i;
    printf("Enter your expression: ");
    for (i = 0; i <= MAX - 1; i++)
    {
        scanf("%c", &A[i]);
        if (A[i] == 'e')
        {
            break;
        }
    }
    for (i = 0; i <= MAX - 1; i++)
    {
        if ((A[i] != '(') && (A[i] != ')') && (A[i] != 'e'))
        {
            continue;
        }
        else if (A[i] == 'e')
        {
            break;
        }
        else if (A[i] == '(')
        {
            push(A[i]);
        }

        else if ((A[i] == ')') && (stack[top] == '('))
        {

            pop();
        }
        else
        {

            break;
        }
    }

    printf("Your Expression: ");
    if (top == -1 && A[i] == 'e')
    {
        printf(" is valid ");
    }
    else
    {
        printf(" is not valid ");
    }
}

void push(char x)
{
    if (top == MAX - 1)
    {

        printf("Overflow!! \n");
    }
    else
    {

        top = top + 1;
        stack[top] = x;

        // printf(" Pushed: %c \n",stack[top]);
    }
}

void pop()
{
    if (top == -1)
    {
printf("Underflow!! \n");
    }
    else
    {
// printf(" popped: %c \n",stack[top]); 
        top=top-1;
        
    }
}


