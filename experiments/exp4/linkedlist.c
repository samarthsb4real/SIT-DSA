#include <stdio.h>
#include <malloc.h>

struct student
{
    int roll;
    char name[30];
    struct student *link;
} *start;

 int main()
{
    int choice, n, i, data;
    start = NULL;
    printf("How many students' details you want to add:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the roll:");
        scanf("%d", &data);
        struct student *q, *tmp;
        tmp = (struct student *)malloc(sizeof(struct student));
        tmp->roll = data;
        tmp->link = NULL;
        if (start == NULL)
        {
            start = tmp;
        }
        else
        {
        }
        q = start;
        while (q->link != NULL)
            q = q->link;
        q->link = tmp;
    }
    struct student *d;
    if (start == NULL)
    {
        printf("No data");
    }
    else
    {
    }
    d = start;
    printf("List is:");
    while (d != NULL)
    {
        printf("\n%d", d->roll);
        d = d->link;
    }
}