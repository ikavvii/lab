#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *reverseWords(char *s)
{
    size_t len =  strlen(s);
    char *token, *saveptr;
    token = strtok_r(s, " ", &saveptr);
    while (token != NULL) {
        
    }

}


int main(void)
{
    char *s = NULL;
    size_t len = 0;

    printf("Enter the string:\n");

    // getline allocates memory for s if necessary
    ssize_t nread = getline(&s, &len, stdin);

    if (nread == -1)
    {
        fprintf(stderr, "Error reading input\n");
        free(s);
        return 1;
    }

    

    free(s);
    return 0;
}

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t size = 128;
    size_t len = 0;
    char *buf = malloc(size);
    if (!buf)
        return -1;

    int c;
    while ((c = fgetc(stream)) != EOF && c != '\n')
    {
        if (len + 1 >= size)
        {
            size *= 2;
            char *newbuf = realloc(buf, size);
            if (!newbuf)
            {
                free(buf);
                return -1;
            }
            buf = newbuf;
        }
        buf[len++] = (char)c;
    }
    if (c == '\n')
        buf[len++] = '\0';
    else if (len > 0)
        buf[len] = '\0';

    *lineptr = buf;
    *n = size;
    return (ssize_t)len;
}


/**
 * Working of strtok
 * // tokenize
    char s[] = "-abc-=-def";
    char *x;
    x = strtok(s, "-"); // x = "abc"
    printf("%s", x);
    x = strtok(NULL, "-="); // x = "def"
    printf("%s", x);

    x = strtok(NULL, "="); // x = NULL
    printf("%s", x);

    // s = "abc\0=-def\0"
 */