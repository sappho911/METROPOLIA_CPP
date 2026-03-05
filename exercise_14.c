#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 81
#define MAX_LINES 100
#define FILENAME_SIZE 20
#define OUTPUT_FILE "output.txt"

int main () {

    FILE *my_file = NULL;
    FILE *out_file = NULL;

    char filename[FILENAME_SIZE];
    char lines [MAX_LINES][MAX_LINE_LENGTH];
    int lc = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    my_file = fopen (filename, "r");
    out_file = fopen (OUTPUT_FILE, "w");

    if (my_file == NULL) {
        fprintf (stderr, "Unable to open file %s\n", filename);
        exit (1);
    }

    if (out_file == NULL) {
        fprintf (stderr, "Unable to open file %s\n", OUTPUT_FILE);
        exit (1);
    }

    printf ("\nReading from  %s...\n", filename);

    while (lc < MAX_LINES && !feof(my_file)) {
        if (fgets(lines[lc], MAX_LINE_LENGTH, my_file) != NULL) {
            for (int j = 0; lines[lc][j] != '\0'; j++) {
                lines[lc][j] = toupper(lines[lc][j]);
            }
            fputs(lines[lc], out_file);
            lc++;
        }
    }

    printf("Read %d lines from %s\n", lc, filename);

    for (int i= 0; i < lc; i++) {
        printf("Line %d: %s", i+ 1, lines[i]);
    }

    fprintf(out_file, "\nRead %d lines from %s and wrote thet to %s", lc, filename, OUTPUT_FILE);
    fclose(my_file);
    fclose(out_file);

    return 0;
}