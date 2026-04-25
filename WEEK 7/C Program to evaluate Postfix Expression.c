#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char* exp) {
	int i;
    for ( i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); 
        } 
        else {
            int val1 = pop();
            int val2 = pop();
            
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    
    printf("Enter postfix expression (e.g., 231*+9-): ");
    scanf("%s", exp);
    
    printf("Result: %d\n", evaluatePostfix(exp));
    
    return 0;
}
