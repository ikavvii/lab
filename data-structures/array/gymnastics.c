#include <stdio.h>

#define JUDGES 8

int main()
{
    double judges_scores[JUDGES], points = 0, points_avg;

    printf("Enter %d scores: \n", JUDGES);

    for (int i = 0; i < JUDGES; i++)
    {
        scanf("%lf", &judges_scores[i]);
    }

    // bubble sort
    for (int i = 0; i < JUDGES - 1; i++)
    {
        for (int j = 0; j < JUDGES - i - 1; j++)
        {
            if (judges_scores[j] > judges_scores[j + 1])
            {
                double temp = judges_scores[j];
                judges_scores[j] = judges_scores[j + 1];
                judges_scores[j + 1] = temp;
            }
        }
    }

    for (int i = 1; i < JUDGES - 1; i++)
    {
        points += judges_scores[i];
    }

    points_avg = points / (JUDGES - 2);

    printf("Low %.2f\n", judges_scores[0]);
    printf("High %.2f\n", judges_scores[JUDGES - 1]);
    printf("Points %.2f\n", points);
    printf("Points Average %.2f\n", points_avg);
    return 0;
}