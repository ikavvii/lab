#include <stdio.h>
char* finalString(char* s) {
    int len  = strlen(s);

    char *s1 = (char *)malloc(len+1);
    if (!s1) return NULL;
    int front=0, rear=len-1;

    // direction flag
    int direction = 1; // initally set to forward

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'i') {
            direction = !direction; continue;
        }
        if (direction) { 
            s1[front++] = s[i];
        } else {
            s1[rear--] = s[i];
        }
    }
    
    if (direction) {
        strcat(s1, '\0');
        return s1;
    } else {
        // reverse a string
        while (front < rear) {
            char temp = s1[front];
            s1[front] = s1[rear];
            s1[rear] = temp;
            front++;rear--;
        }
        strcat(s1, '\0');

        return s1;
    }
}

int main() {

    char *s;
    scanf("%s", s);

    s = finalString(s);

    printf("%s", s);


    return 0;
}

