#include <iostream>

using namespace std;

int countSegments(string s) {
    int count = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
            count++;
        }
    }

    return count;
}

int main() {
    string s1 = "Hello, my name is John";
    cout << "String: \"" << s1 << "\"\nSegments: " << countSegments(s1) << endl;
    cout << endl;

    string s2 = "   Leading and trailing spaces   ";
    cout << "String: \"" << s2 << "\"\nSegments: " << countSegments(s2) << endl;
    cout << endl;

    string s3 = "SingleWord";
    cout << "String: \"" << s3 << "\"\nSegments: " << countSegments(s3) << endl;
    cout << endl;

    string s4 = "   ";
    cout << "String: \"" << s4 << "\"\nSegments: " << countSegments(s4) << endl;
    cout << endl;

    string s5 = "Multiple   spaces    between   words";
    cout << "String: \"" << s5 << "\"\nSegments: " << countSegments(s5) << endl;

    return 0;
}
