#include <iostream>
#include <vector>

using namespace std;

int minimumDeleteSum(string s1, string s2) {
    short n1 = s1.length();
    short n2 = s2.length();
    vector<vector<int>> sums(n1 + 1, vector<int>(n2 + 1, 0));

    short i;
    int j;
    for(i = 0; i < n1; ++i) {
        for(j = 0; j < n2; ++j) {
            if(s1[i] == s2[j]) {
                sums[i + 1][j + 1] = sums[i][j] + s1[i];
            } else {
                sums[i + 1][j + 1] = max(sums[i][j + 1], sums[i + 1][j]);
            }
        }
    }

    j = 0;

    for(i = n1 - 1; i > -1; --i) {
        j += s1[i];
    }

    for(i = n2 - 1; i > -1; --i) {
        j += s2[i];
    }

    return j - (sums[n1][n2] << 1);
}

void test(string s1, string s2, int expected) {
    cout << "String 1: " << "\"" << s1 << "\"" << endl;

    cout << "String 2: " << "\"" << s2 << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumDeleteSum(s1, s2) << endl;

    cout << endl;
}

int main() {
    test("sea", "eat", 231);
    test("delete", "leet", 403);
    test("abc", "abc", 0);
    test("abc", "", 294);
    test("a", "b", 195);

    return 0;
}
