#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;

    char filename[] = "myfile.dat";

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Cannot open file to write!\n");

        exit(0);
    }

    fprintf(fp, "Hello World of filing!\n");
    fclose(fp);

    return 0;
}