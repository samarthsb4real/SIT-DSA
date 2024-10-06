#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    int age;
    struct Student *next;
};

struct Student *createStudent(int rollNo, char *name, int age)
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = NULL;
    return newStudent;
}

void printStudents(struct Student *head)
{
    struct Student *temp = head;
    while (temp != NULL)
    {
        printf("Roll No: %d, Name: %s, Age: %d\n", temp->rollNo, temp->name, temp->age);
        temp = temp->next;
    }
}

void freeStudents(struct Student* head) {
    struct Student* temp;
    while (head != NULL) {
        temp = head;        
        head = head->next;  
        free(temp);         
    }
}

int main()
{

    struct Student *n1 = createStudent(1, "Alice", 20);
    struct Student *n2 = createStudent(2, "Bob", 21);
    struct Student *n3 = createStudent(3, "Charlie", 22);

    n1->next = n2;
    n2->next = n3;

    printf("Student List:\n");
    printStudents(n1);

    getch();

    freeStudents(n1);

    return 0;
}