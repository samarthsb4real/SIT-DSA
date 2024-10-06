#include<stdio.h>

struct student {
    int roll;
    int age;
    char name[30];
    struct node *next;
};

main(){
    struct student n1, n2, n3;
    struct student *p;
    scanf("%d %d %s", &n1.roll, &n1.age, n1.name);
    scanf("%d %d %s", &n2.roll, &n2.age, n2.name);
    scanf("%d %d %s", &n3.roll, &n3.age, n3.name);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    p = &n1;
    while (p != NULL){
        printf("\n %d %s %d", p->age, p->name, p->roll);
        p=p->next;
    }
        
    getch();
}
