#include <stdio.h>
#define N 20

int stack[N];
// infix to postfix

int top = -1;

char pop()
{
    if(top == -1)
    {
        printf("Stack is empty");
    }
    else
    return stack[top--];
}

char peek()
{
    if(top == N -1)
    {
        printf("stack is full");
    }
    else
    return stack[top];

}

void push(char ch)
{
    if(top == N -1)
    {
        printf("stack is full");
    }
    else
    stack[++top] = ch;
}

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
}
int main()
{

}