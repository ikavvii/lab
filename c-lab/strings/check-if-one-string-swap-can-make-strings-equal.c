#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool areAlmostEqual(char* s1, char* s2) {
    size_t n = strlen(s1);

    int c = 0;

    int freq[26] = {0};

    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            c++;
            freq[s1[i] - 'a']++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (freq[s2[i] - 'a'] > 0) {
                freq[s2[i] - 'a']--;
            }
        }
    }

    if (c == 0 || c == 2) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        return true;
    }

    return false;
}

int main() {
    char *s1 = "acac";
    char *s2 = "acbb";

    printf("%d", areAlmostEqual(s1, s2));
}