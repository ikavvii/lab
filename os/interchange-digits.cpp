#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int number;
    bool isNegative = false;
    cout << "Enter a number: ";
    cin >> number;

    if (number < 0) {
        isNegative = true;
        number = -number;
    }
    string numStr = to_string(number);
    reverse(numStr.begin(),numStr.end());

    number = stoi(numStr);
    if (isNegative) {
        number = -number;
    }
    cout << "Interchanged number: " << number << endl;
    return 0; 
}