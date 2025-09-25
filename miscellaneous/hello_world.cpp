#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    // char s1[6] = "Hello";
    // char s2[6] = "World";
    // char s3[12] =  s1 + " " + s2;
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + " " + s2;
    cout << s3;

    return 0;
}