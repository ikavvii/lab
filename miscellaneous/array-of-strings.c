// Array of pointers with known count (allocate each string individually)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, i;
    char buf[1024];

    printf("How many strings? ");
    if (scanf("%d%*c", &n) != 1) {
        fprintf(stderr, "Invalid count\n");
        return 1;
    }
    if (n <= 0) {
        printf("Nothing to read.\n");
        return 0;
    }

    char **arr = malloc((size_t)n * sizeof *arr);
    if (!arr) {
        perror("malloc");
        return 1;
    }

    /* initialize so free-loop is safe even if some entries remain NULL */
    for (i = 0; i < n; ++i) arr[i] = NULL;

    int actual = 0;
    for (i = 0; i < n; ++i) {
        printf("String %d: ", i+1);
        if (!fgets(buf, sizeof buf, stdin)) {
            /* EOF or error while reading — stop early */
            if (ferror(stdin)) perror("fgets");
            break;
        }
        buf[strcspn(buf, "\n")] = '\0'; /* strip newline */

        size_t len = strlen(buf);
        arr[i] = malloc(len + 1);
        if (!arr[i]) {
            perror("malloc");
            break; /* will trigger cleanup below */
        }
        memcpy(arr[i], buf, len + 1);
        ++actual;
    }

    /* If we broke early due to allocation/read error, ensure we free resources. */
    if (i < n && actual != n) {
        /* cleanup allocated strings so far */
        for (int j = 0; j < n; ++j) {
            free(arr[j]);  /* safe to free NULL */
            arr[j] = NULL;
        }
        free(arr);
        return 1;
    }

    puts("\nYou entered:");
    for (i = 0; i < actual; ++i) {
        puts(arr[i]);
    }

    /* normal cleanup */
    for (i = 0; i < actual; ++i) free(arr[i]);
    free(arr);
    return 0;
}