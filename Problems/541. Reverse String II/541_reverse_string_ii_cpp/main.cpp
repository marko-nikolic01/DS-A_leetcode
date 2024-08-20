#include <iostream>

using namespace std;

string reverseStr(string s, int k) {
    int n = s.length();

    for(int i = 0; i < n; i += 2 * k) {
        int start = i;

        int end;
        if(i + k < n) {
            end = i + k - 1;
        } else {
            end = n - 1;
        }

        while(start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }

    return s;
}

void test() {
    string s1 = "abcdefg";
    int k1 = 2;
    string expected1 = "bacdfeg";
    string result1 = reverseStr(s1, k1);
    cout << "Input: " << s1 << ", k = " << k1 << endl;
    cout << "Expected: " << expected1 << endl;
    cout << "Result: " << result1 << endl;
    cout << endl;

    string s2 = "abcdefgh";
    int k2 = 3;
    string expected2 = "cbadefhg";
    string result2 = reverseStr(s2, k2);
    cout << "Input: " << s2 << ", k = " << k2 << endl;
    cout << "Expected: " << expected2 << endl;
    cout << "Result: " << result2 << endl;
    cout << endl;

    string s3 = "abcdef";
    int k3 = 2;
    string expected3 = "bacdfe";
    string result3 = reverseStr(s3, k3);
    cout << "Input: " << s3 << ", k = " << k3 << endl;
    cout << "Expected: " << expected3 << endl;
    cout << "Result: " << result3 << endl;
    cout << endl;

    string s4 = "abcdefghi";
    int k4 = 4;
    string expected4 = "dcbaefghi";
    string result4 = reverseStr(s4, k4);
    cout << "Input: " << s4 << ", k = " << k4 << endl;
    cout << "Expected: " << expected4 << endl;
    cout << "Result: " << result4 << endl;
    cout << endl;

    string s5 = "a";
    int k5 = 2;
    string expected5 = "a";
    string result5 = reverseStr(s5, k5);
    cout << "Input: " << s5 << ", k = " << k5 << endl;
    cout << "Expected: " << expected5 << endl;
    cout << "Result: " << result5 << endl;
    cout << endl;

    string s6 = "abcd";
    int k6 = 4;
    string expected6 = "dcba";
    string result6 = reverseStr(s6, k6);
    cout << "Input: " << s6 << ", k = " << k6 << endl;
    cout << "Expected: " << expected6 << endl;
    cout << "Result: " << result6 << endl;
    cout << endl;
}

int main() {
    test();
    return 0;
}
