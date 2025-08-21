#include <stdio.h>

int main() {
    float judges_scores[8], points;

    printf("Enter 8 scores: ");

    for (int i = 0; i < sizeof(judges_scores); i++) {
        printf("%d, Judges' score", i + 1);
        scanf("%d", &judges_scores[i]);
    }

    
}