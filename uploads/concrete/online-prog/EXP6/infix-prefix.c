#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
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
    int i = 0, k = 0;
    char tkn;
    char post[max];
	char c[max];
//IMP: reverse the string first!!
int l = strlen(d)-1;
int j =0;
for (int i =l;i>=0;i--)
{
c[j++] = d[i];

}


    while ((tkn = c[i++]) != '\0') {
        
        if (isalnum(tkn)) {
            post[k++] = tkn;
        
        } 
        
        else if (tkn == '(') {
         
            push(tkn);
        } 
        
        else if (tkn == ')') {
            
            while (!isemt() && stk[top] != '(') {
                post[k++] = pop();
           
            }
            if (!isemt() && stk[top] == '(') {
              
                pop(); // Remove the '(' from stack
            }
        }
         else {
           
            while (!isemt() && isp(stk[top]) > icp(tkn)) {
           
                post[k++] = pop();
            }
           
            push(tkn);
        }
    }

    while (!isemt()) {
        post[k++] = pop();
    }
    
    j=0;
    char op[max];
    printf("prefix: \n");

    for (int i = strlen(post);i>=0;i--)
    {
    printf("%c",post[i]);
    
    }
    
    
    /*
    
    post[k] = '\0'; // Null-terminate the string for safe printing
    printf("prefix: %s\n", post);
    */
}

int main() {
    char c[max];
    printf("Enter infix expression: \n");
    scanf("%s", c);
    in2pre(c);
    return 0;
}
