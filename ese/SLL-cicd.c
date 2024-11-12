#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void concatenate(struct Node* head1, struct Node* head2) {
    struct Node* temp = head1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = head2;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert in List 1\n2. Insert in List 2\n3. Concatenate Lists\n4. Display List 1\n5. Display List 2\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data for List 1: ");
                scanf("%d", &data);
                insert(&head1, data);
                break;
            case 2:
                printf("Enter data for List 2: ");
                scanf("%d", &data);
                insert(&head2, data);
                break;
            case 3:
                concatenate(head1, head2);
                break;
            case 4:
                display(head1);
                break;
            case 5:
                display(head2);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}