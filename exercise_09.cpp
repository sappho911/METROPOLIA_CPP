#include <cstdlib>
#include <ctime>
#include <stdio.h>

#define ARRAY_SIZE 20

int find_first(const unsigned int *array, unsigned int what);

int main () {
    unsigned int array[ARRAY_SIZE];

    srand (time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 20 + 1;
    }
    array[ARRAY_SIZE - 1 ] = 0;

    printf("Array");

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%u\n", array[i]);
    }

    unsigned int num;
    while (1) {
        printf("Enter number to find (0 to stopp): ");
        scanf("%u", &num);

        if (num == 0) {
            break;
        }

        int i = find_first(array, num);
        if (i >= 0) {
            printf("index where the number found is  %d\n", i - 1);
        } else {
            printf("not found\n");
        }
    }
    return 0;
}


int find_first(const unsigned int *array, unsigned int what) {
    int i = 0;
    while (array[i] != 0 ){
        if (array[i] == what) {
            return i;
        }
        i++;
    }
    return -1;
}