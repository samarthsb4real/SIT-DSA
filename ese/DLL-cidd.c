#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
}

void delete(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp == head) head = temp->next;
    free(temp);
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}