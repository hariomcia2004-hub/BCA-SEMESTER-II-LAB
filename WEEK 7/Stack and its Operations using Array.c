#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX], top = -1;

void push() {
    int val;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot add more elements.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &val); 
        stack[++top] = val;
        printf("%d pushed to stack.\n", val);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is already empty.\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}
void peek(){
	if(top==-1){
		printf("Stack Underflow!,peek not possible\n");
		return ;
	}
	else
	printf("Peeked Element is %d\n", stack[top]);
}

void display() {
	int i;
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--) printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice,item;
    while (1) {
    	printf("STACK OPERATIONS\n");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5.Exit\nEnter choice: ");
        scanf("%d", &choice); 
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); 
					break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
