#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push() {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (!newNode) {
        printf("Heap Overflow! Memory allocation failed.\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = top;
    top = newNode; 
    printf("%d pushed to stack.\n", val);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    int poppedVal = temp->data;
    top = top->next;
    free(temp); 
    printf("Popped element: %d\n", poppedVal);
}
void peek(){
	struct Node* temp = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Peeked Element is %d\n",temp->data);
}

void display() {
    struct Node* temp = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while (1) {
    	printf("STACK OPERATIONS\n");
        printf("\n1. Push\n2. Pop\n3.Peek\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3:peek();break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
