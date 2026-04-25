#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nEnqueued: %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue Underflow!");
        return;
    }
    struct Node* temp = front;
    printf("\nDequeued: %d\n", front->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display() {
    struct Node* temp = front;
    if (front == NULL) printf("\nQueue is Empty!");
    else {
        printf("\nLinked List Queue: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }
}

int main() {
	int choice,item;
    while (1) {
    	printf("\nQUEUE OPERATIONS\n");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice); 
        switch (choice) {
            case 1: printf("Enter Value to be Enqueue:");
                    scanf("%d",&item);
			        enqueue(item); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;

}
