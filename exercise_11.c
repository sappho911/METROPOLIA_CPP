#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl);

#define STR_SIZE 80
#define STR_REPL_SIZE 3
#define REPL_CHAR_NUM 2

int main() {

    char text[STR_SIZE];
    char repl[STR_REPL_SIZE];

    printf("Enter a text: ");
    fgets(text, STR_SIZE, stdin);
    printf("%s", text);
    printf("Enter a character you want to replace (e3) (e gonna be replaced to 3):");
    fgets(repl, STR_REPL_SIZE, stdin);

    if (repl[strlen(repl) - 1] == '\n') {
        repl[strlen(repl) - 1] = '\0';
    }

    int count = replace_char(text, repl);

    return 0;
}

int replace_char(char *str, const char *repl) {
    int i;
    int count = 0;
    int length = strlen(repl);

    if (length != REPL_CHAR_NUM) {
        printf("Enter two characters.\n");
        return 0;
    }

    for (i = 0; str[i] != '\0'; i++) {

        if (str[i] == repl[0]) {
            str[i] = repl[1];
            count++;
        }
    }

    if (count == 0) {
        printf("No characters were found! \n");
    }

    printf("Replaced %d charachters\n%s\n", count, str);
    return count;
}