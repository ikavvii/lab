#ifndef GETLINE_H
#define GETLINE_H

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
typedef long long ssize_t;
#else
#include <sys/types.h>
#endif

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif
