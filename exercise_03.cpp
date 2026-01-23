#include <stdio.h>

int main() {

    int students = 0;

    printf("How many students: ");
    scanf("%d", &students);

    if (students <= 0) {
        printf("Invalid number of students!\n");
        return 0;
    }

    int grades[students];

    for (int i = 0; i < students; i++) {
        grades[i] = -1;
    }

    while (1) {
        int student_number = 0;

        printf("\nEnter student number (1 - %d) or 0 to stop: ", students);
        scanf("%d", &student_number);

        if (student_number == 0) {
            break;
        }

        if (student_number < 1 || student_number > students) {
            printf("Invalid student number!\n");
            continue;
        }

        int grade = 0;

        while (1) {
            printf("Enter grade (0 - 5) for student %d or -1 to cancel: ",
                   student_number);
            scanf("%d", &grade);

            if (grade == -1) {
                break;
            }

            if (grade < 0 || grade > 5) {
                printf("Invalid grade!\n");
                continue;
            }

            grades[student_number - 1] = grade;
            break;
        }
    }

    printf("\nStudent   Grade\n");

    for (int i = 0; i < students; i++) {
        printf("%-9d", i + 1);

        if (grades[i] == -1) {
            printf("N/A\n");
        } else {
            printf("%d\n", grades[i]);
        }
    }


    return 0;
}
