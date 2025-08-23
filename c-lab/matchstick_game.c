#include <stdio.h>

int main()
{

    int matchsticks = 21, computer, user, flag = 0;

    while (matchsticks > 1)
    {
            printf("Pick 1, 2, 3, or 4 matchsticks: ");
            scanf("%d", &user);
            if (user < 1 || user > 4 || user>matchsticks) {
                printf("Invalid move."); continue;
            }
            matchsticks -= user; flag = 1;
            printf("You picked %d, %d matchsticks left.\n", user, matchsticks);

            computer = 5 - user;
            matchsticks -= computer; flag = 0;
            printf("Computer picked %d, %d matchsticks left.\n", computer, matchsticks);
    }

    if (!flag) {
        printf("You must pick last stick! Computer wins");
    } else {
        printf("You defeated computer! Congrats");
    }

    return 0;
}