//evalutation of expression:
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack definition
int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack[top] = val;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int val = stack[top];
    top--;
    return val;
}

int evaluatePostfix(char exp[]) {
    top = -1; // Reset stack pointer

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // Skip spaces or tabs
        if (ch == ' ' || ch == '\t') continue;

        // If operand (digit), push to stack
        if (isdigit(ch)) {
            push(ch - '0');
        }
        // If operator, pop two operands and compute
        else {
            int op2 = pop();
            int op1 = pop();

            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 % op2); break;
                case '^': push((int)pow(op1, op2)); break;
                default:
                    printf("Invalid operator encountered: %c\n", ch);
                    return -1;
            }
        }
    }
    return pop(); // Final result
}

int main() {
    char exp[MAX];

    printf("Enter single-digit postfix expression (e.g., 231*+9-): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result of Postfix Evaluation = %d\n", result);

    return 0;
}
