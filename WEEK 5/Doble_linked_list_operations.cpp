#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtMiddle(struct Node** head, int data, int position);
void deleteAtBeginning(struct Node** head);
void deleteAtEnd(struct Node** head);
void deleteAtMiddle(struct Node** head, int position);
void display(struct Node* head);
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert Beginning\n2. Insert Middle\n3. Insert End\n");
        printf("4. Delete Beginning\n5. Delete Middle\n6. Delete End\n");
        printf("7. Traversal (Display)\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: "); scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data and position: "); scanf("%d %d", &data, &pos);
                insertAtMiddle(&head, data, pos);
                break;
            case 3:
                printf("Enter data: "); scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4: deleteAtBeginning(&head); break;
            case 5:
                printf("Enter position to delete: "); scanf("%d", &pos);
                deleteAtMiddle(&head, pos);
                break;
            case 6: deleteAtEnd(&head); break;
            case 7: display(head); break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAtMiddle(struct Node** head, int data, int position) {
    if (position <= 1) { insertAtBeginning(head, data); return; }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) temp = temp->next;
    
    if (temp == NULL || temp->next == NULL) { insertAtEnd(head, data); }
    else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) (*head)->prev = NULL;
    free(temp);
}
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    if (temp->next == NULL) { *head = NULL; free(temp); return; }
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}
void deleteAtMiddle(struct Node** head, int position) {
    if (*head == NULL) return;
    if (position == 1) { deleteAtBeginning(head); return; }
    struct Node* temp = *head;
    for (int i = 1; i < position && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) return;
    if (temp->next == NULL) { deleteAtEnd(head); return; }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
void display(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

