#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool longestSubsequenceRepeatedK(string& s, string& t, int k) {
    int pos = 0;
    int matched = 0;

    int n = s.size();
    int m = t.size();
    for(char ch : s) {
        if(ch == t[pos]) {
            ++pos;

            if(pos == m) {
                pos = 0;
                ++matched;

                if(matched == k) {
                    return true;
                }
            }
        }
    }

    return false;
}

string longestSubsequenceRepeatedK(string s, int k) {
    vector<int> freq(26);

    for(char ch : s) {
        ++freq[ch - 'a'];
    }

    vector<char> candidate;

    for(int i = 25; i >= 0; i--) {
        if(freq[i] >= k) {
            candidate.push_back('a' + i);
        }
    }

    queue<string> q;

    for(char ch : candidate) {
        q.push(string(1, ch));
    }

    string ans = "";

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if(curr.size() > ans.size()) {
            ans = curr;
        }

        for(char ch : candidate) {
            string next = curr + ch;

            if(longestSubsequenceRepeatedK(s, next, k)) {
                q.push(next);
            }
        }
    }

    return ans;
}

void test(string s, int k, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << longestSubsequenceRepeatedK(s, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test("letsleetcode", 2, "let");
    test("bb", 2, "b");
    test("ab", 2, "");
    test("abababab", 3, "ba");
    test("aabbaabbaabb", 3, "aabb");

    return 0;
}
