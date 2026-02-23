#include <stdio.h>

bool read_positive(int *value);

int main() {
    int value;
    int incorrect = 0;

    do {
        printf("Guess how much money I have! \n");

        if (!read_positive(&value)) {
            incorrect++;
        }

    } while (incorrect < 3);

    printf("I give up! See you later!\n");

    return 0;
}

bool read_positive(int *value) {
    int num;

    printf("Enter a positive number: ");

    if (scanf("%d", &num) != 1) {
        while (getchar() != '\n');
        printf("Incorrect input\n");
        return false;
    }

    if (num < 0) {
        return false;
    }

    *value = num;
    printf("You didn't get it right. I have %d euros. \n", num * 2 + 20);
    return true;
}
