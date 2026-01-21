#include <stdio.h>
#include <stdlib.h>

struct Data {
    char text[100];
};

int main() {
    FILE *file;
    struct Data d;

    // Write to file
    file = fopen("myfile.txt", "w");
    if (file == NULL) {
        printf("Error while opening file for writing.\n");
        return 1;
    }

    printf("Enter text in file: ");
    fgets(d.text, sizeof(d.text), stdin);

    fprintf(file, "%s", d.text);
    fclose(file);
    printf("Text written successfully!\n\n");

    // Read from file
    file = fopen("myfile.txt", "r");
    if (file == NULL) {
        printf("Error while reading file.\n");
        return 1;
    }

    printf("Reading from the file:\n");
    while (fgets(d.text, sizeof(d.text), file) != NULL) {
        printf("%s", d.text);
    }
    fclose(file);

    return 0;
}