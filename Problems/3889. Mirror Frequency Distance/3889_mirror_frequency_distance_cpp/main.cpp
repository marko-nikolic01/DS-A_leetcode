#include <iostream>
#include <vector>

using namespace std;

int mirrorFrequency(string s) {
    int sum = 0;
    vector<int> digits(10, 0);
    vector<int> letters(26, 0);

    int i;
    for(i = s.length() - 1; i > -1; --i) {
        if(s[i] < ':') {
            ++digits[s[i] - '0'];
        } else {
            ++letters[s[i] - 'a'];
        }
    }

    for(i = 0; i < 5; ++i) {
        sum += abs(digits[i] - digits[9 - i]);
    }

    for(i = 0; i < 13; ++i) {
        sum += abs(letters[i] - letters[25 - i]);
    }

    return sum;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << mirrorFrequency(s) << endl;

    cout << endl;
}

int main() {
    test("ab1z9", 3);
    test("4m7n", 2);
    test("byby", 0);
    test("aabbcczzyyxx", 0);
    test("aaaa0000", 8);
    test("bibidi", 6);
    test("babidi", 6);
    test("boo", 3);

    return 0;
}
