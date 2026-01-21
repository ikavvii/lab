#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    cout << "Enter a 16-bit binary number: ";
    string binaryInput;
    cin >> binaryInput;
    unsigned long value = bitset<16>(binaryInput).to_ulong();
    unsigned long mask = 0b1111000000000000;
    cout << "You entered: " << value << endl;
    cout << "Mask applied: " << (value & mask) << endl;
    return 0;
}