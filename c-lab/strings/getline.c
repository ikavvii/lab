#include "getline.h"

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
