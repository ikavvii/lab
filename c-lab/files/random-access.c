// using fseek

#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    FILE *fp;

    fp = fopen("file.txt", "r+");

    printf("%ld \n", ftell(fp));
    c = fgetc(fp); c = fgetc(fp);
    printf("%ld \n", ftell(fp));

    fseek(fp, 2, SEEK_CUR);

    printf("%ld \n", ftell(fp));

    fputs("fast purple", fp);
    printf("%ld \n", ftell(fp));

    fclose(fp);

    return 0;
}