#include <iostream>

using namespace std;

string convertToTitle(int columnNumber) {
    string title = "";
    while(columnNumber > 0) {
        columnNumber--;
        title = (char)(columnNumber % 26 + 65) + title;
        columnNumber /= 26;
    }

    return title;
}

int main()
{
    cout << "Test Case 1: " << endl;
    cout << "Input: 1" << endl;
    cout << "Expected: A" << endl;
    cout << "Result: " << convertToTitle(1) << '\n' << endl;

    cout << "Test Case 2: " << endl;
    cout << "Input: 28" << endl;
    cout << "Expected: AB" << endl;
    cout << "Result: " << convertToTitle(28) << '\n' << endl;

    cout << "Test Case 3: " << endl;
    cout << "Input: 701" << endl;
    cout << "Expected: ZY" << endl;
    cout << "Result: " << convertToTitle(701) << '\n' << endl;

    return 0;
}
