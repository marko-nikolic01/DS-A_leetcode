#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    string sum = "";

    int digit = 0;

    int n1 = num1.length() - 1;
    int n2 = num2.length() - 1;
    while(n1 > -1 || n2 > -1 || digit > 0) {

        if(n1 > -1) {
            digit += num1[n1--] - 48;
        }

        if(n2 > -1) {
            digit += num2[n2--] - 48;
        }

        sum = to_string(digit % 10) + sum;
        digit /= 10;
    }

    return sum;
}

int main() {
    string num1 = "123";
    string num2 = "456";

    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "Sum: " << addStrings(num1, num2) << endl;
    cout << endl;

    num1 = "999";
    num2 = "1";
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "Sum: " << addStrings(num1, num2) << endl;
    cout << endl;

    num1 = "0";
    num2 = "0";
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "Sum: " << addStrings(num1, num2) << endl;

    return 0;
}
