#include <stdio.h>
#include <math.h>

int is_palindrome(unsigned long long int number);

int main() {
    unsigned long long int x;
    printf("Enter x: " );
    scanf("%llu", &x);

    unsigned long long int temp = x;
    temp++;
    while(!is_palindrome(temp)){
        temp++;
    }
    printf("Next smallest palindrome of %llu is %llu", x, temp);

}

int is_palindrome(unsigned long long int number) {
    //reverse the number
    unsigned long long int temp = number, sum = 0;
    while (temp > 0) {
        int remainder = temp % 10;
        sum = sum * 10 + remainder;
        temp /= 10;
    }

    return sum == number;
}