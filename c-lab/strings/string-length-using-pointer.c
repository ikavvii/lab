#include <stdio.h>
#include "getline.h"

int main() {
    char *s;
    size_t len = 0;
    printf("Enter string: ");
    ssize_t nread = getline(&s, &len, stdin);

    if (nread == -1)
    {
        fprintf(stderr, "Error reading input\n");
        free(s);
        return 1;
    }
    char *ptr = s;
    int length = 0;
    while (*ptr != '\0') {
        length++;
        *(ptr++);
    }
    printf("%s\n", s);
    printf("%d", length);
}