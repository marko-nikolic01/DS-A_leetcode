#include <iostream>
#include <vector>

using namespace std;

string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int l = s.length();
    vector<int> changes(l + 1, 0);

    for(int i = shifts.size() - 1; i > -1; --i) {
        if(shifts[i][2] > 0) {
            ++changes[shifts[i][0]];
            --changes[++shifts[i][1]];
        } else {
            --changes[shifts[i][0]];
            ++changes[++shifts[i][1]];
        }
    }

    s[0] = (s[0] - 'a' + changes[0]) % 26;

    if(s[0] < 0) {
        s[0] += '{';
    } else {
        s[0] += 'a';
    }

    for(int i = 1; i < l; ++i) {
        changes[i] += changes[i - 1];

        s[i] = (s[i] - 'a' + changes[i]) % 26;

        if(s[i] < 0) {
            s[i] += '{';
        } else {
            s[i] += 'a';
        }
    }

    return s;
}

void test(string s, vector<vector<int>> shifts, string expected) {
    cout << "String: \"" << s << "\"" << endl;

    cout << "Shifts: ";
    for (vector<int> shift : shifts) {
        cout << "[" << shift[0] << " " << shift[1] << " " << shift[2] << "] ";
    }
    cout << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << shiftingLetters(s, shifts) << "\"" << endl;

    cout << endl;
}

int main() {
    test("abc", {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}}, "ace");
    test("dztz", {{0, 0, 0}, {1, 1, 1}}, "catz");
    test("aaa", {{0, 2, 1}}, "bbb");
    test("abc", {{0, 2, 0}}, "zab");
    test("abcd", {{1, 3, 1}, {0, 0, 0}}, "zcde");
    test("yzx", {{0, 1, 1}, {1, 2, 0}}, "zzw");
    test("abcxyz", {{0, 3, 1}, {2, 5, 0}}, "bccxxy");
    test("aaaabbbb", {{0, 1, 0}, {3, 4, 1}}, "zzabcbbb");

    return 0;
}
