#include <stdio.h>

#define MAX_SIZE 25


int a[MAX_SIZE];
int current_size = 0;

void insert_element(int element, int position);
void delete_element(int position);
void display_elements();
void create_initial_array();

int main() {
    int choice, element, position;

    create_initial_array();
    printf("Initial array created.\n");
    display_elements();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element at a specific location\n");
        printf("2. Delete an element (beginning, middle, end)\n");
        printf("3. Display all elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (1 to %d) to insert: ", current_size + 1);
                scanf("%d", &position);
                insert_element(element, position - 1); 
                break;
            case 2:
                printf("Enter the position (1 to %d) to delete: ", current_size);
                scanf("%d", &position);
                delete_element(position - 1); 
                break;
            case 3:
                display_elements();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void create_initial_array() {
    int num_elements, i;
    printf("Enter the number of initial elements (up to %d): ", MAX_SIZE);
    scanf("%d", &num_elements);

    if (num_elements > MAX_SIZE || num_elements < 0) {
        printf("Invalid number of elements. Defaulting to 0.\n");
        return;
    }

    current_size = num_elements;
    printf("Enter %d elements:\n", current_size);
    for (i = 0; i < current_size; i++) {
        scanf("%d", &a[i]);
    }
}

void insert_element(int element, int position) {
	int i;
    if (current_size >= MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (position < 0 || position > current_size) {
        printf("Invalid position for insertion.\n");
        return;
    }


    for ( i = current_size; i > position; i--) {
        a[i] = a[i - 1];
    }


    a[position] = element;
    current_size++;
    printf("Element %d inserted at position %d.\n", element, position + 1);
}


void delete_element(int position) {
	int i;
    if (current_size <= 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    if (position < 0 || position >= current_size) {
        printf("Invalid position for deletion.\n");
        return;
    }

   
    for ( i = position; i < current_size - 1; i++) {
        a[i] = a[i + 1];
    }

    
    current_size--;
    printf("Element at position %d deleted.\n", position + 1);
}


void display_elements() {
	int i;
    if (current_size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for ( i = 0; i < current_size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

