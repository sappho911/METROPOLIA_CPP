#include <stdio.h>
#include <string.h>

#define STR_SIZE 20

int main() {
    char str[STR_SIZE];

    while (1) {
        printf("Enter a string: ");
        fgets(str, STR_SIZE, stdin);

        if (str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }

        if (strcmp (str, "stop") == 0 ) {
            printf("Stopped \n");
            break;
        }

        printf("The string length is: %d \n", strlen(str));
    }

    return 0;
}


