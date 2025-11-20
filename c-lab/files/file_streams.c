#include <stdio.h>
#include <stdlib.h>

/**
 * Three special file stream FILE pointers
 * stdin, stdout, stderr
 */

int main()
{

    int i;
    fprintf(stdout, "Enter i: ");
    int on_read = fscanf(stdin, "%d", &i);

    if (on_read == 1)
    {
        fprintf(stdout, "Value of i=%d \n", i);
    }
    else
    {
        fprintf(stderr, "Error reading i value\n");
    }

    return 0;
}