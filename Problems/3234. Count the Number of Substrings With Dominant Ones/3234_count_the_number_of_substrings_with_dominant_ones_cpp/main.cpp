#include <iostream>
#include <vector>

using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    vector<int> pre(n + 1);

    pre[0] = -1;

    int i;
    for(i = 0; i < n; ++i) {
        if(i == 0 || (i > 0 && s[i - 1] == '0')) {
            pre[i + 1] = i;
        } else {
            pre[i + 1] = pre[i];
        }
    }

    int substrings = 0;
    int zeros;
    int ones;

    int j;
    for(i = 1; i <= n; ++i) {
        zeros = s[i - 1] == '0' ? 1 : 0;

        j = i;
        while(j > 0 && zeros * zeros <= n) {
            ones = (i - pre[j]) - zeros;

            if(zeros * zeros <= ones) {
                substrings += min(j - pre[j], ones - zeros * zeros + 1);
            }

            j = pre[j];
            ++zeros;
        }
    }

    return substrings;
}

void test(string s, int expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfSubstrings(s) << endl;

    cout << endl;
}

int main() {
    test("00011", 5);
    test("101101", 16);
    test("0", 0);
    test("1", 1);
    test("1100101", 11);

    return 0;
}
