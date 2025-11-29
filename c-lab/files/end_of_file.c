#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int n, x, sum;

    fp = (FILE *)fopen("input.dat", "a+"); // append, also allows read
    if (fp == NULL)
        exit(1);
    n = sum = 0;

    while (1)
    {
        // if (fscanf(fp, "%d", &x) == EOF)
        //     break;
        fscanf(fp, "%d", &x);
        if (feof(fp))
            break;

        ++n;
        sum += x;
        printf("%d-th integer:  %d\n", n, x);
    }

    // fprintf(fp, "%d\n", sum); // appends sum at the eof

    fclose(fp);

    printf("Sum of the integers read is %d\n", sum);

    exit(0);
}