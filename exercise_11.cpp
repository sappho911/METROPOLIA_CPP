#include <stdio.h>

int replace_char(char *str, const char *repl);

int main() {

    char text[80] = "I am so tired of Python. C is much better languagee";
    int count = replace_char(text, "e3");

    return 0;
}

int replace_char(char *str, const char *repl) {
    int i;
    int count = 0;

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