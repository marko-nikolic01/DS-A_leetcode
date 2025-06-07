#include <iostream>
#include <vector>

using namespace std;

string clearStars(string s) {
    vector<vector<int>> letters(26);

    int i;
    int j;
    int n = s.length();
    for(i = 0; i < n; ++i) {
        if(s[i] > '*') {
            letters[s[i] - 'a'].push_back(i);
        } else {
            for(j = 0; j < 26; ++j) {
                if(!letters[j].empty()) {
                    s[letters[j].back()] = '*';
                    letters[j].pop_back();

                    break;
                }
            }
        }
    }

    j = 0;
    for(i = 0; i < n; ++i) {
        if(s[i] > '*') {
            s[j++] = s[i];
        }
    }

    s.resize(j);

    return s;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << clearStars(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("aaba*", "aab");
    test("abc", "abc");
    test("cb*a*", "c");
    test("dcba***", "d");
    test("zzz***", "");

    return 0;
}
