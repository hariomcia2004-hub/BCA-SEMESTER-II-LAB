#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* last = NULL;


void create_list_initial(int n);
void insert_pos(int value, int pos);
void delete_pos(int pos);
void traverse();
int count_nodes();
struct node* create_node(int value);

int main() {
    int choice, pos, value, n;

   
    printf("Enter the number of nodes to create initially: ");
    scanf("%d", &n);
    create_list_initial(n);

    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert by position\n");
        printf("2. Delete by position\n");
        printf("3. Traverse list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &pos);
                insert_pos(value, pos);
                break;
            case 2:
                printf("Enter the position to delete from: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}


struct node* create_node(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL; 
    return newNode;
}


int count_nodes() {
    if (last == NULL) return 0;
    struct node* temp = last->next;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);
    return count;
}


void create_list_initial(int n) {
    int i, value;
    if (n <= 0) {
        printf("No nodes to create initially.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        struct node* newNode = create_node(value);

        if (last == NULL) {
            last = newNode;
            last->next = last; 
        } else {
            newNode->next = last->next; 
            last->next = newNode;      
            last = newNode;          
        }
    }
    printf("Initial list with %d nodes created.\n", n);
}


void insert_pos(int value, int pos) {
    int count = count_nodes();

    if (pos < 1 || pos > count + 1) {
        printf("Insertion not possible at this position\n");
        return;
    }

    struct node* newNode = create_node(value);

  
    if (pos == 1) {
        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }
    
    else if (pos == count + 1) {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    
    else {
    	int i;
        struct node* temp = last->next;
        for ( i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at position %d\n", value, pos);
}


void delete_pos(int pos) {
    int count = count_nodes();

    if (last == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    if (pos < 1 || pos > count) {
        printf("Deletion not possible for position %d\n", pos);
        return;
    }

    struct node* temp;

    
    if (count == 1) {
        temp = last;
        last = NULL;
        free(temp);
    }
    
    else if (pos == 1) {
        temp = last->next; 
        last->next = temp->next;
        free(temp);
    }
    
    else {int i;
        struct node* current = last->next;
        struct node* prev = NULL;
        for ( i = 1; i < pos; i++) {
            prev = current;
            current = current->next;
        }
       
        if (current == last) {
            last = prev;
        }
        prev->next = current->next;
        free(current);
    }
    printf("Node at position %d deleted.\n", pos);
}


void traverse() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp;
    temp = last->next; 

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next); 
    printf("(back to start)\n");
}

