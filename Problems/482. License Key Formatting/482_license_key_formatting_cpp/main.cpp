#include <iostream>
#include <stack>

using namespace std;

string licenseKeyFormatting(string s, int k) {
    stack<char> letters;

    int n = s.length();
    int letterCount = 0;
    for(int i = n - 1; i > -1; --i) {
        if(s[i] != '-') {
            if(letterCount == k) {
                letters.push('-');
                letterCount = 0;
            }

            if(s[i] >= 97 && s[i] <= 122) {
                letters.push(s[i] - 32);
            } else {
                letters.push(s[i]);
            }

            letterCount++;
        }
    }

    string formatted = "";
    while(!letters.empty()) {
        formatted += letters.top();
        letters.pop();
    }

    return formatted;
}

void printTestCase(const string& s, int k) {
    string formattedKey = licenseKeyFormatting(s, k);
    cout << "License Key: " << s << endl;
    cout << "k: " << k << endl;
    cout << "Formatted License Key: " << formattedKey << endl;
    cout << endl;
}

int main() {
    printTestCase("2-5g-3-J", 2);
    printTestCase("5F3Z-2e-9-w", 4);
    printTestCase("a-b-c-d-e-f-g-h", 3);
    printTestCase("A-B-C-D-E-F", 1);
    printTestCase("a-b-c-d-e-f", 5);

    return 0;
}
