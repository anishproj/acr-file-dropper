#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define max 100

int top = -1;
char stk[max];

void push(char c) {
    if (top < max - 1) {
        stk[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stk[top--];
    }
    return '\0';
}

bool isemt() {
    return (top == -1);
}

bool isfull() {
    return (top == max - 1);
}

int icp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 4;
    if (ch == '(') return 5;
    return 0;
}

int isp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

void in2pos(char c[]) {
    int i = 0, k = 0;
    char tkn;
    char post[max];

    while ((tkn = c[i++]) != '\0') {
        if (isalnum(tkn)) {
            post[k++] = tkn;
        } else if (tkn == '(') {
            push(tkn);
        } else if (tkn == ')') {
            while (!isemt() && stk[top] != '(') {
                post[k++] = pop();
            }
            if (!isemt() && stk[top] == '(') {
                pop(); // Remove the '(' from stack
            }
        } else {
            while (!isemt() && isp(stk[top]) >= icp(tkn)) {
                post[k++] = pop();
            }
            push(tkn);
        }
    }

    while (!isemt()) {
        post[k++] = pop();
    }
    
    post[k] = '\0'; // Null-terminate the string for safe printing
    printf("postfix: %s\n", post);
}

int main() {
    char c[max];
    printf("Enter infix expression: \n");
    scanf("%s", c);
    in2pos(c);
    return 0;
}
