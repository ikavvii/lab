// grades arithmetic quizzes

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char again;
    do
    {
        int numQuestions, numberCorrectAnswers = 0;
        float percentCorrect;
        printf("Number of questions in the quiz: ");
        scanf("%d", &numQuestions);

        int *key = malloc(numQuestions * sizeof(int));
        printf("Enter the answer key: ");
        for (int i = 0; i < numQuestions; i++)
        {
            scanf("%d", &key[i]);
        }

        printf("Enter the answer: ");
        for (int i = 0; i < numQuestions; i++)
        {
            int answer;
            scanf("%d", &answer);
            if (answer == key[i])
            {
                numberCorrectAnswers++;
            }
        }

        percentCorrect = (float)numberCorrectAnswers / numQuestions * 100;

        printf("Number correct: %d out of %d\n", numberCorrectAnswers, numQuestions);
        printf("Percentage correct: %.2f%%\n", percentCorrect);

        printf("Grade another quiz? (y/n): ");
        scanf(" %c", &again); // space before %c to consume any leftover newline character
        free(key);

    } while (again == 'y' || again == 'Y');

    return 0;
}