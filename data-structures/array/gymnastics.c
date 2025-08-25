#include <stdio.h>

int main() {
    float judges_scores[8], points = 0, points_avg;

    printf("Enter 8 scores: \n");

    for (int i = 0; i < 8; i++) {
        scanf("%f", &judges_scores[i]);
    }

    for (int i = 0; i< 7; i++) {
        for (int j = 0; j < 7 - i; j++) {
            if (judges_scores[j] > judges_scores[j+1]) {
                float temp = judges_scores[j];
                judges_scores[j] = judges_scores[j+1];
                judges_scores[j+1] = temp;
            }
        }
    }
    

    for (int i = 1; i<7; i++) {
        points += judges_scores[i];
    }

    points_avg = points/6;

    printf("Low %.2f\n", judges_scores[0]);
    printf("High %.2f\n", judges_scores[7]);
    printf("Points %.2f\n", points);
    printf("Points Average %.2f\n", points_avg);
    return 0;
}