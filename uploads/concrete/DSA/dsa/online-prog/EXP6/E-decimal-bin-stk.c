#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n, rem;

    printf("Enter decimal number: ");
    scanf("%d", &n);

    if(n == 0)
    {
        printf("Binary: 0\n");
        return 0;
    }

    while(n > 0)
    {
        rem = n % 2;
        push(rem);
        n = n / 2;
    }

    printf("Binary: ");

    while(top != -1)
        printf("%d", pop());

    printf("\n");

    return 0;
}
