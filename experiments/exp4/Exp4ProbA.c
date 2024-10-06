#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
typedef struct student 
{
    int roll_no;
    char name[100];
    int age;
    struct student *next;
} node;

// Function to create a new node
node *create_node(int roll_no, char *name, int age) 
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->roll_no = roll_no;
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the end of the list
void insert_node(node **head, int roll_no, char *name, int age) 
{
    node *new_node = create_node(roll_no, name, age);
    if (*head == NULL) 
	{
        *head = new_node;
    }
	 else {
        node *temp = *head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to print the linked list
void print_list(node *head) 
{
    while (head != NULL) 
	{
        printf("Roll No: %d \nName: %s \nAge: %d\n", head->roll_no, head->name, head->age);
        head = head->next;
    }
}

int main() {
    node *head = NULL;

    // Create and insert nodes
    insert_node(&head, 1, "Samarth", 20);
    insert_node(&head, 2, "Deepesh", 21);
    insert_node(&head, 3, "Dheer", 22);

    // Print the linked list
    print_list(head);

    return 0;
}