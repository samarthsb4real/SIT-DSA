#include <stdio.h>
#include <string.h>

int binarySearchWords(char *words[], int size, char *target);

int main()
{
    char *words[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int size = sizeof(words) / sizeof(words[0]);
    char *target1 = "grape"; // Expected output: 2
    char *target2 = "orange"; // Expected output: -1

    printf("The index of '%s' is: %d\n", target1, binarySearchWords(words, size, target1));
    printf("The index of '%s' is: %d\n", target2, binarySearchWords(words, size, target2));

    return 0;
}

int binarySearchWords(char *words[], int size, char *target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(words[mid], target);

        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
