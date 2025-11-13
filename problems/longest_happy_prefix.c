#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Compute prefix function (KMP failure function).
 * pi[i] = length of longest proper prefix of s[0..i] that's also a suffix of s[0..i].
 * Returns a malloc'd array of length n, or NULL on allocation failure.
 * If n <= 0 returns NULL.
 */
static int *compute_pi(const char *s, int n)
{
    if (n <= 0)
        return NULL;
    int *pi = (int *)malloc(sizeof(int) * n);
    if (!pi)
        return NULL;
    pi[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

/* Return a malloc'ed empty string ("") or NULL on allocation failure. */
static char *empty_string_alloc(void)
{
    char *r = (char *)malloc(1);
    if (r)
        r[0] = '\0';
    return r;
}

/* longestPrefix:
 * - Input: s (may be const), does NOT take ownership (caller retains ownership).
 * - Output: newly malloc'd NUL-terminated string containing the longest happy prefix.
 *   Caller MUST free() the returned pointer. Returns NULL on allocation failure.
 */
char *longestPrefix(const char *s)
{
    if (!s)
        return NULL;

    int n = (int)strlen(s);
    if (n == 0)
        return empty_string_alloc();

    int *pi = compute_pi(s, n);
    if (!pi)
        return NULL; // allocation failure in compute_pi

    int L = pi[n - 1];
    free(pi);

    if (L == 0)
        return empty_string_alloc();

    char *result = (char *)malloc((size_t)L + 1);
    if (!result)
        return NULL;
    memcpy(result, s, (size_t)L);
    result[L] = '\0';
    return result;
}

int main(void)
{
    const char *s = "ababab";
    char *pref = longestPrefix(s);
    if (pref)
    {
        printf("longest happy prefix: \"%s\"\n", pref);
        free(pref);
    }
    else
    {
        fprintf(stderr, "allocation failed\n");
    }
    return 0;
}
