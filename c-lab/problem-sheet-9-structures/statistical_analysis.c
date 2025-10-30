#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENTS 20
/**
 * Total Score Evaluation Scheme
 *
 * Quiz 25 marks * 2    = 50
 * Mid Term 50 marks    = 50
 * --------------------------
 * Internal Marks       = 50
 *
 * Final 100 marks      = 100
 *  **Note: Calculate final marks out of 50
 * --------------------------
 * External Marks       = 50
 *
 *  **Note: Sum Internal + External
 * ---------------------------
 * Total Score          = 100
 */

typedef struct
{
    char id;
    char name[20];
    bool sex;
    char quizScores[2];
    char midTermScore;
    char finalScore;
    char totalScore;
} Student;

void add(Student *);
void view(Student *);

int main()
{
    Student students[MAX_STUDENTS];

    int choice;

    printf("\n\t\t\t MENU\n\n \
            1.  Add student records\n \
            2.  Delete student records\n \
            3.  Update student records\n \
            4.  View all student record\n \
            5.  Calculate an average of a selected student's scores\n \
            6.  Show student who gets the max total score\n \
            7.  Show student who gets the min total score\n \
            8.  Find student by ID\n \
            9.  Sort records by total scores\n \
            10. Exit\n \
        ");

        scanf("%d", choice);
    switch (choice)
    {
    case 1:
        add(students);
        break;

    case 4:
        view(students);
        break;

    default:
        printf("\nInvalid Choice\n");
    }

    return 0;
}

void add(Student *p) {


    for (int i = 0; i < MAX_STUDENTS; i++) {
        // printf("Student: %d", i + 1);
        (p+i)->id = i + 1;
    }
}

void view(Student *p) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        // printf("Student: %d", i + 1);
        (p+i)->id = i + 1;
    }
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Student: %d", (p+i)->id);
    }
}