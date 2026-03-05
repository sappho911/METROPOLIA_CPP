#include <stdio.h>
#include <stdlib.h>


#define ARRAY_SIZE 40
#define LINE_SIZE 256

typedef struct menu_item_ {
    char name[256];
    double price;
} menu_item;

int main() {

    FILE *my_file = NULL;

    char filename[30];
    char line[LINE_SIZE];
    int count = 0;

    menu_item items[ARRAY_SIZE];

    printf("Enter the file name: ");
    scanf("%s", filename);

    my_file = fopen(filename, "r");

    if (my_file == NULL) {
        fprintf(stderr, "Unable to open the file %s\n", filename);
        exit(1);
    }

    while (!feof(my_file) && count < ARRAY_SIZE) {
        if (fgets(line, sizeof(line), my_file) != NULL) {
            sscanf(line, "%[^;]; %lf", items[count].name ,&items[count].price);
            count++;
        }
    }
    fclose(my_file);

    for (int i = 0; i < count; i++) {
        printf("%s; %.2f\n", items[i].name, items[i].price);
    }

    return 0;
}