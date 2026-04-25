#include <stdio.h>
#define SIZE 5

int items[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("\nQueue is Full!");
    else {
        if (front == -1) front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted - %d\n", value);
    }
}

void dequeue() {
    if (front == -1)
        printf("\nQueue is Empty!");
    else {
        printf("\nDeleted - %d\n", items[front]);
        front++;
        if (front > rear) front = rear = -1;
    }
}

void display() {
	int i;
    if (rear == -1)
        printf("\nQueue is Empty!");
    else {
        printf("\nQueue elements: ");
        for ( i = front; i <= rear; i++)
            printf("%d ", items[i]);
    }
    printf("\n");
}

int main() {
	int choice,item;
    while (1) {
    	printf("QUEUE OPERATIONS\n");
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
