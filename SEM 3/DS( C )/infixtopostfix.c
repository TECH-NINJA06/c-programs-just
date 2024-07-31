#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

char postfix[MAX], infix[MAX];
char stack[MAX];
int top = -1;

int isfull();
int isempty();
void push(char);
char pop();
void in_to_post();
int instack_pri(char);
int symbol_pri(char);
int space(char);
long int evaluate();

int main() {
    printf("\nEnter infix expression: ");
    gets(infix);
    in_to_post();
    printf("\nInfix to Postfix Expression: %s\n", postfix);

    long int result = evaluate();
    printf("Result of Postfix Expression: %ld\n", result);
    return 0;
}

int isfull() {
    if(top==MAX-1)
        return 1;
    return 0;
}

int space(char s) {
    if(s == ' ' || s == '\t')
        return 1;
    return 0;
}

int isempty() {
    if(top==-1)
        return 1;
    return 0;
}

void push(char s) {
    if (isfull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = s;
}

char pop() {
    if (isempty()) {
        printf("Stack Underflow\n");
        return 0;
    }
    char item = stack[top--];
    return item;
}

int instack_pri(char s) {
    switch (s) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
        default:
            return 0;
    }
}

int symbol_pri(char s) {
    switch (s) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 4;
        default:
            return 0;
    }
}

void in_to_post() {
    char s, a;
    int pos = 0;

    printf("\n%-8s%-15s%-15s\n", "SYMBOL", "STACK", "POSTFIX");
    for (int i = 0; i < strlen(infix); i++) {
        s = infix[i];
        if (!space(s)) {
            switch (s) {
                case '(':
                    push(s);
                    break;

                case ')':
                    while ((a = pop()) != '(')
                        postfix[pos++] = a;
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!isempty() && instack_pri(stack[top]) >= symbol_pri(s))
                        postfix[pos++] = pop();
                    push(s);
                    break;

                default:
                    postfix[pos++] = s;
            }
            printf("%-8c", infix[i]);
            for (int j = 0; j <= top; j++) {
                printf("%c", stack[j]);
            }
            printf("%-15s", "");
            printf("%-15s\n", postfix);
        }
    }
    while (!isempty()) {
        postfix[pos++] = pop();
        printf("%-8s", "");
        for (int j = 0; j <= top; j++) {
            printf("%c ", stack[j]);
        }
        printf("%-15s", "");
        printf("%-15s\n", postfix);
    }
    postfix[pos] = '\0';
}

long int evaluate() {
    int i = 0;
    long int op1, op2, result;
    char symbol;

    printf("\n%-8s%-15s%-15s\n", "SYMBOL", "STACK", "POSTFIX");
    while ((symbol = postfix[i++]) != '\0') {
        if (isdigit(symbol)) {
            push(symbol - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (symbol) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '%':
                    result = op1 % op2;
                    break;
                case '^':
                    result = 1;
                    for (int j = 0; j < op2; j++) {
                        result *= op1;
                    }
                    break;
            }
            push(result);
        }

        printf("%-8c", symbol);
        for (int j = 0; j <= top; j++) {
            printf("%ld ", stack[j]);
        }
        printf("%-15s", "");
        printf("%-15s\n", postfix);
    }
    return pop();
}
