#include <iostream>
#include <unordered_set>

using namespace std;

bool hasAllCodes(string s, int k) {
    unordered_set<int> codes;
    int code;

    int j;
    int n;
    for(int i = s.length(); i >= k; --i) {
        code = 0;

        n = --i - k;
        for(j = ++i - 1; j > n; --j) {
            code = (code << 1) | (s[j] - '0');
        }

        codes.insert(code);
    }

    return codes.size() == (1 << k);
}

void test(string s, int k, bool expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (hasAllCodes(s, k) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("00110110", 2, true);
    test("0110", 1, true);
    test("0110", 2, false);
    test("0000000001011100", 4, false);
    test("00011011100", 3, false);

    return 0;
}
