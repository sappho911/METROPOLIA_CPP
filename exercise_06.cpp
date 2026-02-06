#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <bits/locale_classes.h>

void main_menu();
void roll_d6();
void roll_d10();

int main (void) {
    int selection;

    srand(time(NULL));

    do {
        main_menu();
        printf("Enter selection:");
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
        }

        switch (selection) {
            case 1:
                roll_d6();
                break;
            case 2:
                roll_d10();
                break;
            case 3:
                printf("You choose a Quit, so quitting: \n");
                break;
            default:
                printf("Invalid input. Try again.\n");
        }
    } while (selection != 3);

    return 0;
}

void main_menu() {
    printf("Choose one of the following choices: \n");
    printf("1) Roll D6 \n");
    printf("2) Roll D10 \n");
    printf("3) Quit \n");
}

void roll_d6() {
    int random_variable = rand() % 6 + 1;
    printf("Random variable [1,6] is : %d\n", random_variable);
}

void roll_d10() {
    int random_variable = rand() % 10 + 1;
    printf("Random variable [1,10] is : %d\n", random_variable);
}