#include <iostream>

using namespace std;

string processStr(string s) {
    string processedString = "";
    char temp;

    int j;
    int k;
    short n = s.length();
    for(short i = 0; i < n; ++i) {
        if(s[i] > '`') {
            processedString.push_back(s[i]);
        } else if(s[i] == '#') {
            k = processedString.length();
            for(j = 0; j < k; ++j) {
                processedString.push_back(processedString[j]);
            }
        } else if(s[i] == '%') {
            k = processedString.length() - 1;
            for(j = 0; j < k; ++j) {
                temp = processedString[j];
                processedString[j] = processedString[k];
                processedString[k--] = temp;
            }
        } else if(processedString.length() > 0) {
            processedString.pop_back();
        }
    }

    return processedString;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << processStr(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("a#b%*", "ba");
    test("z*#", "");
    test("abc%", "cba");
    test("ab##", "abababab");
    test("a*b#c%", "cbb");

    return 0;
}
