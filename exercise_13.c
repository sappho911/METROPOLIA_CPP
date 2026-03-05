#include <stdio.h>
#include <stdlib.h>

#define FILESIZE 50

int main() {

    char file[FILESIZE];
    int num_count = 0;
    int value = 0;
    int min = 0;
    int max = 0;

    char line[10];

    printf("Enter the file name: ");
    scanf("%s", file);

    FILE *my_file;
    my_file = fopen(file, "r");

    if (my_file == NULL) {
        fprintf(stderr, "Unable to open file %s...\n", file);
        exit(1);
    }

    printf("Start reading integers from the file %s \n",file );

    while (!feof(my_file)) {
        if (fgets(file, sizeof(file), my_file) != NULL) {
            if (sscanf(file, "%d", &value) == 1) {

                if (num_count == 0) {
                    min = value;
                    max = value;
                }

                if (value < min)
                    min = value;

                if (value > max)
                    max = value;

                num_count++;
            }
        }
    }

    if (feof(my_file)) {
        printf("\nEnd of file reached");
    }

    fclose(my_file);

    printf("\nCount of numbers %d", num_count);
    printf("\nMin number %d", min);
    printf("\nMax number %d", max);

    return 0;
}