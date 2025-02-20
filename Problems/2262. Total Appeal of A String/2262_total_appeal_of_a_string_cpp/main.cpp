#include <iostream>
#include <vector>

using namespace std;

long long appealSum(string s) {
    vector<int> letters(26, -1);
    letters[s[0] - 'a'] = 0;

    int previous = 1;
    long appeal = 1;

    int n = s.length();
    for(int i = 1; i < n; ++i) {
        previous += i - letters[s[i] - 'a'];
        appeal += previous;

        letters[s[i] - 'a'] = i;
    }

    return appeal;
}

void test(string s, long long expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << appealSum(s) << endl;

    cout << endl;
}

int main() {
    test("abbca", 28);
    test("code", 20);
    test("a", 1);
    test("abc", 10);
    test("zzz", 6);
    test("abcdef", 56);
    test("abababab", 64);

    return 0;
}
