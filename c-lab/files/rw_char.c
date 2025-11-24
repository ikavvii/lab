#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    // c = getchar();

    // printf("Entered: ");
    // putchar(c);


    FILE *fp = stdin;

    c = getc(fp);

    fprintf(stdout, "Entered: ");
    putc(c, stdout);

}