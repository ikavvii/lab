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

int add(Student *, int *);
void view(Student *, int);

int main()
{
    Student *students = malloc(MAX_STUDENTS * sizeof(Student));
    int studentCount = 0;

    char userActive = 'y';
    int choice;

    while (userActive == 'y' || userActive == 'Y')
    {
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

        int status;

        switch (choice)
        {
        case 1:
            status = add(students, &studentCount);
            if (status == 1)
            {
                printf("\nInvalid input. Try again. \n");
            }
            break;
        case 4:
            view(students, studentCount);
            break;
        case 10:
            printf("\n\tThank you!\n");
            userActive = '\0';
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    }
    free(students);
    return 0;
}

int add(Student *p, int *count)
{

    if (*count == MAX_STUDENTS)
    {
        printf("Cannot add more students");
        return 2;
    }
    Student *s = p + *count;
    s->id = *count + 1;

    char buf[32];
    printf("\nName: ");
    scanf("%19s", s->name);
    getchar();
    int input;

    printf("Sex (1 for Male, 0 for Female): ");
    fgets(buf, sizeof(buf), stdin);
    if (sscanf(buf, "%d", &input) != 1 || (input != 0 && input != 1))
        return 1;
    s->sex = input;

    printf("Quiz 1 score (out of 25): ");
    fgets(buf, sizeof(buf), stdin);
    if (sscanf(buf, "%d", &input) != 1 || input < 0 || input > 25)
        return 1;
    s->quizScores[0] = input;

    printf("Quiz 2 score (out of 25): ");
    fgets(buf, sizeof(buf), stdin);
    if (sscanf(buf, "%d", &input) != 1 || input < 0 || input > 25)
        return 1;
    s->quizScores[1] = input;

    printf("Mid-term score (out of 50): ");
    fgets(buf, sizeof(buf), stdin);
    if (sscanf(buf, "%d", &input) != 1 || input < 0 || input > 50)
        return 1;
    s->midTermScore = input;

    printf("Final score (out of 100): ");
    fgets(buf, sizeof(buf), stdin);
    if (sscanf(buf, "%d", &input) != 1 || input < 0 || input > 100)
        return 1;
    s->finalScore = input;

    int internal = (s->quizScores[0] + s->quizScores[1] + s->midTermScore) / 2;
    int external = s->finalScore / 2;
    s->totalScore = internal + external;

    (*count)++;
    printf("\n\tStudent added successfully!\n");

    return 0;
}

void view(Student *p, int count)
{
    if (count == 0)
    {
        printf("No student records.\n");
        return;
    }

    printf("\n%-5s %-15s %-5s %-10s\n", "ID", "Name", "Sex", "Total");
    for (int i = 0; i < count; i++)
    {
        printf("%-5d %-15s %-5s %-10d\n",
               p[i].id, p[i].name,
               p[i].sex ? "M" : "F",
               p[i].totalScore);
    }

    return;
}