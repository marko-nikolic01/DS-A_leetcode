#include <iostream>
#include <vector>

using namespace std;

bool isIsomorphic(string s, string t) {
    int n = s.size();

    if(n != t.size()) {
        return false;
    }

    vector<int> positionsA(127, 0);
    vector<int> positionsB(127, 0);

    for(int i = 0; i < n; ++i) {
        if(positionsA[s[i]] != positionsB[t[i]]) {
            return false;
        }

        positionsA[s[i]] = i + 1;
        positionsB[t[i]] = i + 1;
    }

    return true;
}

void printTestCase(string s, string t, bool expected) {
    bool result = isIsomorphic(s, t);
    cout << "s: " << s << ", t: " << t << ", Expected: " << (expected ? "true" : "false") << ", Result: " << (result ? "true" : "false") << "\n";
}

int main() {
    printTestCase("egg", "add", true);
    printTestCase("foo", "bar", false);
    printTestCase("paper", "title", true);
    printTestCase("ab", "aa", false);
    printTestCase("abc", "xyz", true);
    printTestCase("aabb", "xxyy", true);
    printTestCase("aabb", "xxxy", false);

    return 0;
}
