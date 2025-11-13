/**
 * Author   : Kavin Manoharan
 * Date     : 13-11-2025
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

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

typedef struct Student
{
    uint8_t id;
    char name[20];
    bool sex;
    uint8_t quizScores[2];
    uint8_t midTermScore;
    uint8_t finalScore;
    uint8_t totalScore;
} Student;

void add(Student *, int *);

int main()
{
    Student *students = malloc(MAX_STUDENTS * sizeof(Student));
    int studentCount = 0;

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

    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add(students);
        break;

    default:
        printf("\nInvalid Choice\n");
    }

    return 0;
}

void add(Student *p, int *count)
{

    if (*count == MAX_STUDENTS)
    {
        printf("Cannot add more students");
        return;
    }
    Student *s = p + *count;
    s->id = *count + 1;


    printf("\nName: ");
    scanf("%s", s->name);

    printf("Sex (1 for Male, 0 for Female): ");
    scanf("%s", &s->sex);

    printf("Quiz 1 score: ");
    scanf("%s", &s->quizScores[0]);

    printf("Quiz 2 score: ");
    scanf("%s", &s->quizScores[1]);

    printf("Mid-term score: ");
    scanf("%d", &s->midTermScore);

    printf("Final score (out of 100)");
    scanf("%d", &s->finalScore);

    int internal = ((s->quizScores[0] + s->quizScores[1]) + s->midTermScore) / 2;
    int external = s->finalScore / 2;
    s->totalScore = internal + external;

    (*count)++;
    printf("Student added successfully!\n");

    return;
}

void view(Student *p, int count) {
    if (count == 0) {
        printf("No student records.\n");
        return;
    }

    printf("\n%-5s %-15s %-5s %-10s\n", "ID", "Name", "Sex", "Total");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-15s %-5s %-10d\n",
               p[i].id, p[i].name,
               p[i].sex ? "M" : "F",
               p[i].totalScore);
    }
}