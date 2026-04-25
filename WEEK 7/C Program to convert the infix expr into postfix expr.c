#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item, x;

    push('(');        
    strcat(infix, ")"); 

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];

        if (item == '(') {
            push(item);
        } 
        else if (isalnum(item)) { 
            postfix[j++] = item;
        } 
        else if (item == ')') { 
            x = pop();
            while (x != '(') {
                postfix[j++] = x;
                x = pop();
            }
        } 
        else { 
            x = pop();
            while (precedence(x) >= precedence(item)) {
                postfix[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        }
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
