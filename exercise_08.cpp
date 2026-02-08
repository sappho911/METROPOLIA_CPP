#include <cstdlib>
#include <ctime>
#include <stdio.h>

#define ARRAY_SIZE 15

void print_numbers(const int *array, int count);

int main () {
    int array[ARRAY_SIZE];

    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100 + 1;
    }
    print_numbers(array, ARRAY_SIZE);
    return 0;
}

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d\n", array[i]);
    }
}