#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void countWordOccurrences(char text[]);

int main() {
    char text[] = "Hello, world! This is a test. Hello again, world.";
    countWordOccurrences(text);
    return 0;
}

void countWordOccurrences(char text[]) {
    WordCount words[MAX_WORDS];
    int wordCount = 0;

    char *token = strtok(text, " ,.!?;:\n");
    while (token != NULL) {
        // Convert token to lowercase
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        // Check if the word already exists in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the array
        if (!found) {
            strcpy(words[wordCount].word, token);
            words[wordCount].count = 1;
            wordCount++;
        }

        // Get the next token
        token = strtok(NULL, " ,.!?;:\n");
    }

    // Display the results
    printf("Word occurrences:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}
