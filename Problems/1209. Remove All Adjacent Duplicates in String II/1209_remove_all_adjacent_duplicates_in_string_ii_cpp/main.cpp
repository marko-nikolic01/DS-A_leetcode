#include <iostream>
#include <vector>

using namespace std;

string removeDuplicates(string s, int k) {
    vector<pair<char, short>> streaks;

    int i;
    int n = s.length();
    for(i = 0; i < n; ++i) {
        if(streaks.empty() || s[i] != streaks.back().first) {
            streaks.push_back({s[i], 1});
        } else if(++streaks.back().second == k) {
            streaks.pop_back();
        }
    }

    s.resize(0);

    n = streaks.size();
    for(i = 0; i < n; ++i) {
        while(--streaks[i].second > -1) {
            s.push_back(streaks[i].first);
        }
    }

    return s;
}

void test(string s, int k, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << removeDuplicates(s, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test("abcd", 2, "abcd");
    test("deeedbbcccbdaa", 3, "aa");
    test("pbbcggttciiippooaais", 2, "ps");
    test("aabbcc", 2, "");
    test("aabbaabb", 2, "");

    return 0;
}
