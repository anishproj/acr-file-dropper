#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h> // Required for strlen()

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
    if (ch == '^') return 3;
    if (ch == '(') return 5;
    return 0;
}

int isp(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 4;
    return 0;
}

void in2pre(char d[]) {
    int i = 0, k = 0, l = 0;
    char tkn;
    char rev[max], post[max], final_pre[max];

    // Step 1: Reverse string and swap parentheses
    l = strlen(d);
    for (i = 0; i < l; i++) {
        if (d[l - 1 - i] == '(') {
            rev[i] = ')';
        } else if (d[l - 1 - i] == ')') {
            rev[i] = '(';
        } else {
            rev[i] = d[l - 1 - i];
        }
    }
    rev[l] = '\0';

    // Step 2: Get postfix of the reversed string
    i = 0;
    while ((tkn = rev[i++]) != '\0') {
        if (isalnum(tkn)) {
            post[k++] = tkn;
        } else if (tkn == '(') {
            push(tkn);
        } else if (tkn == ')') {
            while (!isemt() && stk[top] != '(') {
                post[k++] = pop();
            }
            if (!isemt() && stk[top] == '(') {
                pop(); // Remove '('
            }
        } else {
            while (!isemt() && isp(stk[top]) > icp(tkn)) {
                post[k++] = pop();
            }
            push(tkn);
        }
    }

    while (!isemt()) {
        post[k++] = pop();
    }
    post[k] = '\0';

    // Step 3: Reverse the postfix result to get the final prefix
    int post_len = strlen(post);
    for (i = 0; i < post_len; i++) {
        final_pre[i] = post[post_len - 1 - i];
    }
    final_pre[post_len] = '\0';

    printf("prefix: %s\n", final_pre);
}

int main() {
    char c[max];
    printf("Enter infix expression: \n");
    scanf("%s", c);
    in2pre(c);
    return 0;
}
