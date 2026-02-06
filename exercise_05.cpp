#include <stdio.h>


int read_range(int low, int high);

int main () {
    int user, ai;

    printf("Let's play! \n");

    for (int i = 0; i < 3; i++) {
        printf("Roll a die and enter your result. \n");
        user = read_range(1,6);

        if (user == 6) {
            printf("i got 6. It is a tie! \n");
        } else {
            ai = user + 1;
            printf("I got %d. I win! \n", ai);
        }
    }
    printf("You looser.! \n");

    return 0;
}

int read_range(int low, int high) {
    int num;

    do {
        printf("Enter a number between %d and %d :", low, high);

        if (scanf("%d", &num) != 1) {
            while (getchar() != '\n');
            printf("Invalid input \n");
        }
        if (num < low || num > high) {
            printf("Number out of range \n");
        } else {
            printf("A number was succesfully read.\n");
            printf("The number is in the specified range.\n");
        }

    } while (num < low || num > high);

    return num;
}