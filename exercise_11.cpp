#include <stdio.h>
#include <string.h>

#define STR_SIZE 32

int main() {
    char* str = "Hello World!";
    char* str2 = "Hello World!";

    printf("%d",strcmp(str, str2));

    return 0;
}