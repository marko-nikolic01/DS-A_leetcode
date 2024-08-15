#include <iostream>
#include <vector>

using namespace std;

int firstUniqChar(string s) {
    vector<int> occurences(26, 0);

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        occurences[s[i] - 97]++;
    }

    for(int i = 0; i < n; ++i) {
        if(occurences[s[i] - 97] == 1) {
            return i;
        }
    }

    return -1;
}

void testFirstUniqChar(string s, int expected) {
    int result = firstUniqChar(s);
    cout << "String: " << s << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    testFirstUniqChar("leetcode", 0);
    testFirstUniqChar("loveleetcode", 2);
    testFirstUniqChar("aabb", -1);
    testFirstUniqChar("abcd", 0);
    testFirstUniqChar("", -1);

    return 0;
}
