#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cout << "Enter a four digit integer: ";
    string input;
    cin >> input;

    if (input.length() != 4 || !all_of(input.begin(), input.end(), ::isdigit))
    {
        cout << "Invalid input. Please enter a four digit integer." << endl;
        return 1;
    }

    int count = count_if(input.begin(), input.end(), [](char c)
                         { return c == '1'; });
    cout << "The number of ones in " << input << " is " << count << "." << endl;
}