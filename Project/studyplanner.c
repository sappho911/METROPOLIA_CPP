#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining of constans and file name
#define SCHEDULE_FILE "schedule.csv"
#define SCHEDULE_SIZE 100
#define SCHEDULE_TODAY_SIZE 100

//Defining of structure
typedef struct {
    char day[10];
    char time[10];
    char course[100];
    char room[10];
} Schedule;

//Functions
int read_schedule(Schedule schedule[]);
void sort_schedule(Schedule schedule[], int count);
void normalize_day(char str[]);
int find_classes(Schedule schedule[], int count, char day[], Schedule today[]);
void print_classes(Schedule today[], int classes_count, char day[]);


//Main file
int main () {
    //Defining our size of Struct with alias schedule.
    Schedule schedule[SCHEDULE_SIZE];

    // defining veriable
    int count = read_schedule(schedule);

    //sorting schedule
    sort_schedule(schedule, count);

    //defining str as buffer for sscanf and day where stored data.
    char str[20];
    char day[20];

    while (1) {

        //Defining structure size of today.
        Schedule today[SCHEDULE_TODAY_SIZE];
        //Asking user to enter the day
        printf("Enter the day:(Example: Monday)");
        //getting the string and size of string "bytes" from standard input(keyboard)
        fgets(str, sizeof(str), stdin);

        //removing new line character
        if (str[strlen(str)-1] == '\n') {
            str[strlen(str)-1] = '\0';
        }
        //comparing strings , if true then program stops.
        if (strcmp(str, "stop") == 0) {
            break;
        }
        //Formatting (Normalazie) our string
        normalize_day(str);
        //Taking string and add it to the variable day
        sscanf(str, "%s", day);
        //Finding classes
        int classes_count = find_classes(schedule, count, day, today);
        //Printing classes
        print_classes(today, classes_count, day);
    }
}

//Function open file in read mode and add data to the schedule structure.
int read_schedule(Schedule schedule[]) {
    //Defining poiter to NULL
    FILE *my_file = NULL;
    int count = 0;
    char line[256];

    //Opening file and checking if it succes. If not exiting from program.
    my_file = fopen(SCHEDULE_FILE, "r");
    if (my_file == NULL) {
        fprintf (stderr, "Unable to open file %s\n", SCHEDULE_FILE);
        exit (1);
    }
    //Skipping header.
    fgets(line, sizeof(line), my_file);

    //reading the string and checking bounds and after taking string and adding to Struct and adding count of lines.
    while (!feof(my_file) && count < SCHEDULE_SIZE) {
        if (fgets(line, sizeof(line), my_file) != NULL) {
            sscanf(line, "%[^,], %[^,], %[^,], %[^\n]",
                   schedule[count].day,
                   schedule[count].time,
                   schedule[count].course,
                   schedule[count].room);
            count++;
        }
    }
    //Closing file
    fclose(my_file);

    return count;
}


//Sorting schedule in ascending order.
void sort_schedule(Schedule schedule[], int count) {

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {

            int h1, m1;
            int h2, m2;
            //Reading time from Struct by index and adding to veriables i difined h1, m1 ,h2 ,m2 (h = hours , m= mins)
            sscanf(schedule[i].time, "%d:%d", &h1, &m1);
            sscanf(schedule[j].time, "%d:%d", &h2, &m2);
            //Simple comparsing between values.
            if (h1 > h2 || (h1 == h2 && m1 > m2)) {
                //Swapping
                Schedule temp = schedule[i];
                schedule[i] = schedule[j];
                schedule[j] = temp;
            }
        }
    }
}

//Converting string to lower case and after capitalizing first letter. Example if user input is mOnDAy function normalize string to Monday.
void normalize_day(char str[]) {

    //converting to lowercase all letters
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    //capitalizes first letter
    str[0] = toupper(str[0]);
}


//Finding classes
int find_classes(Schedule schedule[], int count, char day[], Schedule today[]) {
    //starting from count of classes 0;
    int classes_count = 0;

    //comparing days with our structure day and adding count++ and classes by index.
    for (int i = 0; i < count; i++) {
        if (strcmp(day, schedule[i].day) == 0) {
            today[classes_count++] = schedule[i];
        }
    }
    //returning count of classes.
    return classes_count;
}

//Printing classes
void print_classes(Schedule today[], int classes_count, char day[]) {

    //Checking of existing classes if not printing msg.
    if (classes_count == 0) {
        printf("No classes today\n");
    } else {
        //If classes existing printing day
        printf("On %s you have:\n", day);

        //using for loop printing our classes.
        for (int i = 0; i < classes_count; i++) {
            printf("%s %s, %s\n",
                   today[i].time,
                   today[i].course,
                   today[i].room);
        }
    }
}