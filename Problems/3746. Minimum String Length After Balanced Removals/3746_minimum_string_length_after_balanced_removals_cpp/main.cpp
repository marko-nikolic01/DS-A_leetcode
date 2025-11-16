#include <iostream>
#include <vector>

using namespace std;

int minLengthAfterRemovals(string s) {
    vector<bool> remaining;
    int n = -1;

    for(int i = s.length() - 1; i > -1; --i) {
        remaining.push_back(s[i] == 'a');
        ++n;

        while(n > 0 && remaining[n] != remaining[n - 1]) {
            remaining.pop_back();
            remaining.pop_back();
            n -= 2;
        }
    }

    return remaining.size();
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minLengthAfterRemovals(s) << endl;

    cout << endl;
}

int main() {
    test("aabbab", 0);
    test("aaaa", 4);
    test("aaabb", 1);
    test("ababab", 0);
    test("abbaaaabb", 1);
    test("a", 1);
    test("b", 1);

    return 0;
}
