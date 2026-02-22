#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "Hello world!";
    char s2[] = " world!";

    char *p;

    p = strstr(s1, s2);

    printf("%s", p);

}