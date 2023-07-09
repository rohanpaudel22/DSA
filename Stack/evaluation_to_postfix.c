#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 5
float stack[MAX];
int top = -1;
void push(float);
float pop();
int main()
{
    int i = 0;
    printf("Enter postfix expression: \n");
    while (1)
    {
        float r;
        int op = 0;
        char ch;
        printf("Are you entering operator? \n Enter 0 for no and 1 for yes:");
        scanf("%d", &op);
        fflush(stdin);
        if (op == 1)
        {
            fflush(stdin);
            printf("Enter Operator: ");
            scanf("%c", &ch);
            fflush(stdin);
            int y = pop();
            int x = pop();
            switch (ch)
            {

            case '+':

                r = x + y;
                break;

            case '-':
                r = x - y;
                break;

            case '*':
                r = x * y;
                break;

            case '/':
                r = x / y;
                break;

            case '%':
                r = (int)x + (int)y;
                break;
            }

            push(r);
        }
        else
        {
            fflush(stdin);
            printf("Enter Operand: ");
            scanf("%d", &i);
            fflush(stdin);

            if (i == 0)
            {
                break;
            }
            else if (i)
            {
                push(i);
            }
        }
    }
    float r = stack[top];
    printf("Evaluation result: %f", r);
}
void push(float c)
{
    if (top == MAX - 1)
    {

        printf("Overflow");
    }
    else
    {

        top++;
        stack[top] = c;
    }
}

float pop()
{

    float c;
    if (top == -1)
    {
        printf("Underflow");
    }
    {
        c = stack[top];
        top--;
        return c;
    }
}
