#include <iostream>

using namespace std;

int titleToNumber(string columnTitle) {
    int number = 0;

    for(int i = 0; i < columnTitle.length(); ++i) {
        number *= 26;
        number += columnTitle[i] - 64;
    }

    return number;
}

int main()
{
    cout << "Test Case 1: " << endl;
    string columnTitle1 = "A";
    cout << "Input: " << columnTitle1 << endl;
    cout << "Expected: 1" << endl;
    cout << "Result: " << titleToNumber(columnTitle1) << '\n' << endl;

    cout << "Test Case 2: " << endl;
    string columnTitle2 = "AB";
    cout << "Input: " << columnTitle2 << endl;
    cout << "Expected: 28" << endl;
    cout << "Result: " << titleToNumber(columnTitle2) << '\n' << endl;

    cout << "Test Case 3: " << endl;
    string columnTitle3 = "ZY";
    cout << "Input: " << columnTitle3 << endl;
    cout << "Expected: 701" << endl;
    cout << "Result: " << titleToNumber(columnTitle3) << '\n' << endl;

    return 0;
}
