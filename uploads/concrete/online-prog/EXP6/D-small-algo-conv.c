#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char str[])
{
    strcpy(stack[++top], str);
}

void pop(char str[])
{
    strcpy(str, stack[top--]);
}

/* Postfix -> Infix */
void postfixToInfix(char exp[])
{
    char x, op1[MAX], op2[MAX], temp[MAX];
    int i;

    top = -1;

    for(i = 0; exp[i] != '\0'; i++)
    {
        x = exp[i];

        if(isalnum(x))
        {
            char s[2] = {x, '\0'};
            push(s);
        }
        else
        {
            pop(op2);
            pop(op1);

            sprintf(temp, "(%s%c%s)", op1, x, op2);
            push(temp);
        }
    }

    pop(temp);
    printf("Infix: %s\n", temp);
}

/* Postfix -> Prefix */
void postfixToPrefix(char exp[])
{
    char x, op1[MAX], op2[MAX], temp[MAX];
    int i;

    top = -1;

    for(i = 0; exp[i] != '\0'; i++)
    {
        x = exp[i];

        if(isalnum(x))
        {
            char s[2] = {x, '\0'};
            push(s);
        }
        else
        {
            pop(op2);
            pop(op1);

            sprintf(temp, "%c%s%s", x, op1, op2);
            push(temp);
        }
    }

    pop(temp);
    printf("Prefix: %s\n", temp);
}

/* Prefix -> Infix */
void prefixToInfix(char exp[])
{
    char x, op1[MAX], op2[MAX], temp[MAX];
    int i;

    top = -1;

    for(i = strlen(exp) - 1; i >= 0; i--)
    {
        x = exp[i];

        if(isalnum(x))
        {
            char s[2] = {x, '\0'};
            push(s);
        }
        else
        {
            pop(op1);
            pop(op2);

            sprintf(temp, "(%s%c%s)", op1, x, op2);
            push(temp);
        }
    }

    pop(temp);
    printf("Infix: %s\n", temp);
}

/* Prefix -> Postfix */
void prefixToPostfix(char exp[])
{
    char x, op1[MAX], op2[MAX], temp[MAX];
    int i;

    top = -1;

    for(i = strlen(exp) - 1; i >= 0; i--)
    {
        x = exp[i];

        if(isalnum(x))
        {
            char s[2] = {x, '\0'};
            push(s);
        }
        else
        {
            pop(op1);
            pop(op2);

            sprintf(temp, "%s%s%c", op1, op2, x);
            push(temp);
        }
    }

    pop(temp);
    printf("Postfix: %s\n", temp);
}

int main()
{
    int choice;
    char exp[MAX];

    do
    {
        printf("\n--- EXPRESSION CONVERSION ---\n");
        printf("1. Postfix to Infix\n");
        printf("2. Postfix to Prefix\n");
        printf("3. Prefix to Infix\n");
        printf("4. Prefix to Postfix\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 4)
        {
            printf("Enter expression: ");
            scanf("%s", exp);
        }

        switch(choice)
        {
            case 1:
                postfixToInfix(exp);
                break;

            case 2:
                postfixToPrefix(exp);
                break;

            case 3:
                prefixToInfix(exp);
                break;

            case 4:
                prefixToPostfix(exp);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}
