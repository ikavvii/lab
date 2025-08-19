#include <stdio.h>
#include <math.h>

int is_palindrome(int number);

int main() {
    int x;
    printf("Enter x: " );
    scanf("%d", &x);

    int temp = x;
    temp++;
    while(!is_palindrome(temp)){
        temp++;
    }
    printf("Next smallest palindrome of %d is %d", x, temp);

}

int is_palindrome(int number) {
    //reverse the number
    int temp = number, sum = 0;
    while (temp > 0) {
        int remainder = temp % 10;
        sum = sum * 10 + remainder;
        temp /= 10;
    }

    return sum == number;
}