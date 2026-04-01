#include <iostream>
#include <vector>

using namespace std;

string generateString(string str1, string str2) {
    short n = str1.size();
    short m = str2.size();
    string s(n + m - 1, 'a');
    vector<short> fixed(n + m - 1, 0);
    bool flag;
    short idx;

    short i;
    short j;
    for(i = 0; i < n; ++i) {
        if(str1[i] == 'T') {
            for(j = i; j < i + m; ++j) {
                if(fixed[j] && s[j] != str2[j - i]) {
                    return "";
                }

                s[j] = str2[j - i];
                fixed[j] = 1;
            }
        }
    }

    for(i = 0; i < n; ++i) {
        if(str1[i] == 'F') {
            flag = false;
            idx = -1;

            for(j = i + m - 1; j >= i; --j) {
                if(str2[j - i] != s[j]) {
                    flag = true;
                }

                if(idx == -1 && !fixed[j]) {
                    idx = j;
                }
            }

            if(!flag) {
                if(idx == -1) {
                    return "";
                }

                s[idx] = 'b';
            }
        }
    }

    return s;
}

void test(string str1, string str2, string expected) {
    cout << "String 1: " << "\"" << str1 << "\"" << endl;

    cout << "String 2: " << "\"" << str2 << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << generateString(str1, str2) << "\"" << endl;

    cout << endl;
}

int main() {
    test("TFTF", "ab", "ababa");
    test("TFTF", "abc", "");
    test("F", "d", "a");
    test("TT", "ab", "");
    test("T", "xyz", "xyz");

    return 0;
}
