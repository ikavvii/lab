#include <stdio.h>
#include <string.h>


int main() {
    char s[50];

    printf("Enter a string: ");
    scanf("%s", s);
    
    int write = 0;  // index for writing
    for (int read = 0; s[read] != '\0'; read++) {
        if (s[read] == 'b') {
            continue;  // skip 'b'
        }
        if (s[read] == 'c' && write > 0 && s[write - 1] == 'a') {
            write--;   // remove previous 'a'
            continue;  // skip current 'c'
        }
        s[write++] = s[read];  // keep character
    }
    s[write] = '\0'; 

    printf("Result: \"%s\"\n", s);

    return 0;
}
