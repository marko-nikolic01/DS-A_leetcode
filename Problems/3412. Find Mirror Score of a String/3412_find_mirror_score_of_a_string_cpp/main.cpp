#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long calculateScore(string s) {
    long score = 0;

    vector<stack<int>> letters(26);

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(letters['z' - s[i]].size() > 0) {
            score += i - letters['z' - s[i]].top();
            letters['z' - s[i]].pop();
        } else {
            letters[s[i] - 'a'].push(i);
        }
    }

    return score;
}

void test(string s, long expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << calculateScore(s) << endl;

    cout << endl;
}

int main() {
    test("aczzx", 5);
    test("abcdef", 0);
    test("az", 1);
    test("azaz", 2);
    test("aazzbb", 4);
    test("ab", 0);
    test("xyzyx", 0);
    test("abcdefgh", 0);
    test("aaaaaaaaaaaaaaaaaaaz", 1);

    return 0;
}
