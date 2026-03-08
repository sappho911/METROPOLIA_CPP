#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCHEDULE_FILE "schedule.csv"
#define SCHEDULE_SIZE 100

typedef struct {
    char day[10];
    char time[10];
    char course[100];
    char room[10];
}Schedule;

int main () {
    FILE *my_file = NULL;
    int count = 0;
    char line[256];

    Schedule schedule[SCHEDULE_SIZE];

    my_file = fopen(SCHEDULE_FILE, "r");
    if (my_file == NULL) {
        fprintf (stderr, "Unable to open file %s\n", SCHEDULE_FILE);
        exit (1);
    }

    fgets(line, sizeof(line), my_file);

    while (!feof(my_file) && count < SCHEDULE_SIZE) {
        if (fgets(line, sizeof(line), my_file) != NULL) {
            sscanf(line, "%[^,], %[^,], %[^,], %[^\n]",schedule[count].day , schedule[count].time, schedule[count].course, schedule[count].room);
            count++;
        }
    }

    fclose(my_file);

    // for (int i = 0; i < count; i++) {
    //     printf(" %s %s %s %s\n",
    //            schedule[i].day,
    //            schedule[i].time,
    //            schedule[i].course,
    //            schedule[i].room);
    // }

    char day[10];

    do {
        printf("Enter day:");
        scanf("%s", day);
        printf("You entered %s\n", day);
    } while (strcmp(day, "stop") != 0);


}