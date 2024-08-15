#include <iostream>

using namespace std;

bool isSubsequence(string s, string t) {
    int j = 0;

    int n = t.size();
    for(int i = 0; i < n; ++i) {
        if(s[j] == t[i]) {
            j++;
        }
    }

    return j == s.size();
}

int main() {
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout << "Sequence: " << s1 << endl;
    cout << "String: " << t1 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isSubsequence(s1, t1) ? "true" : "false") << endl;
    cout << endl;

    string s2 = "axc";
    string t2 = "ahbgdc";
    cout << "Sequence: " << s2 << endl;
    cout << "String: " << t2 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (isSubsequence(s2, t2) ? "true" : "false") << endl;
    cout << endl;

    string s3 = "ace";
    string t3 = "abcde";
    cout << "Sequence: " << s3 << endl;
    cout << "String: " << t3 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isSubsequence(s3, t3) ? "true" : "false") << endl;
    cout << endl;

    string s4 = "aec";
    string t4 = "abcde";
    cout << "Sequence: " << s4 << endl;
    cout << "String: " << t4 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (isSubsequence(s4, t4) ? "true" : "false") << endl;
    cout << endl;

    string s5 = "";
    string t5 = "abcde";
    cout << "Sequence: " << s5 << endl;
    cout << "String: " << t5 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isSubsequence(s5, t5) ? "true" : "false") << endl;

    return 0;
}
