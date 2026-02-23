#include <stdio.h>
#include <string.h>

#define STR_SIZE 80
#define WORD_SIZE 80

int count_words(const char* str, const char* word);

int main() {
    char str[STR_SIZE];
    char word[WORD_SIZE];
    int res;

    while (1) {
        printf("Enter a string:");
        fgets(str, STR_SIZE, stdin);

        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }

        printf("Enter a word:");
        fgets(word, WORD_SIZE, stdin);

        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }

        if (strcmp(word, "stop") == 0) {
            break;
        }
        res = count_words(str, word);
        printf("Counted matched words are: %d \n", res);
    }
    return 0;
}

int count_words(const char* str, const char* word) {

    int count = 0;
    const char* ptr = str;
    int length = strlen(word);

    while ((ptr = strstr(ptr, word)) != 0) {
        count++;
        ptr += length;
    }
    return count;
}