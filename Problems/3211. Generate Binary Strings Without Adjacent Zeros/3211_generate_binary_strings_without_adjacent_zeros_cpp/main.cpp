#include <iostream>
#include <vector>

using namespace std;

void validStrings(vector<string>& validStringsList, string& validString, int n) {
    if(n == 1) {
        if(validString.back() == '1') {
            validString.push_back('0');
            validStringsList.push_back(validString);
            validString.pop_back();
        }

        validString.push_back('1');
        validStringsList.push_back(validString);
        validString.pop_back();
    } else {
        n--;
        if(validString.back() == '1') {
            validString.push_back('0');
            validStrings(validStringsList, validString, n);
            validString.pop_back();
        }

        validString.push_back('1');
        validStrings(validStringsList, validString, n);
        validString.pop_back();
    }
}

vector<string> validStrings(int n) {
    if(n == 1) {
        return {"0", "1"};
    }

    vector<string> validStringsList;

    string validString = "1";
    validStrings(validStringsList, validString,  --n);

    validString = "0";
    validStrings(validStringsList, validString,  n);

    return validStringsList;
}

void test(int n, const vector<string>& expected) {
    cout << "n: " << n << endl;

    cout << "Expected: ";
    for (const string& s : expected) {
        cout << s << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (const string& s : validStrings(n)) {
        cout << s << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test(1, {"0", "1"});
    test(2, {"10", "11", "01"});
    test(3, {"101", "110", "111", "010", "011"});
    test(4, {"1010", "1011", "1101", "1110", "1111", "0101", "0110", "0111"});
    test(5, {"10101", "10110", "10111", "11010", "11011", "11101", "11110", "11111", "01010", "01011", "01101", "01110", "01111"});

    return 0;
}
