#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(char);
char pop();
void in2post(char[], char[]);
int priority(char);
int main()
{
    char in[100], post[100];
    printf("Enter infix expression: \n");
    gets(in);
    in2post(in, post);
    printf("Equivalent postfix expression:");
    puts(post);
}
void in2post(char in[], char post[])
{
    int i = 0, j = 0;
    while (in[i] != '\0')
    {
        if (in[i] == '(')
        {
            push(in[i]);
            i++;
        }
        else if (in[i] == ')')
        {
            while ((top != -1) && (stack[top] != '('))
            {
                post[j] = pop();
                j++;
            }
            if (top == -1)
            {
                printf("\n Incorrect Expression");
                exit(1);
            }
            pop(); // to pop and ignore the ( present in stack i++;
        }
        else if (isdigit(in[i]) || isalpha(in[i]))
        {
            post[j] = in[i];
            i++;
            j++;
        }
        else if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '%')
        {
            while (((top != -1) || (stack[top] != '(')) && (priority(stack[top]) > priority(in[i])))
            {
                post[j] = pop();
                j++;
            }
        push(in[i]);
        i++;
        }
        else
        {
            printf("Incorrect Expression");
            exit(1);
        }
    }

    while (top != -1 && stack[top] != '(')
    {
        post[j] = pop();
        j++;
    }
    post[j] = '\0';
}
int priority(char op)
{
    if (op == '*' || op == '/' || op == '%')
        return 1;
    else
        return 0;
}
void push(char c)
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

char pop()
{
    char c;
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
