#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
    int n = s.size();
    set<pair<int, int>> segs;
    multiset<int> lens;

    int i = 0;
    int j;
    while(i < n) {
        j = i;
        while(j < n && s[j] == s[i]) {
            ++j;
        }

        segs.insert({i, j - 1});
        lens.insert(j - i);
        i = j;
    }

    int k = queryIndices.size();
    vector<int> ans(k);

    for(i = 0; i < k; ++i) {
        int pos = queryIndices[i];
        char ch = queryCharacters[i];

        if(s[pos] != ch) {
            auto it = segs.upper_bound({pos, INT_MAX});
            --it;
            int L = it->first, R = it->second;
            segs.erase(it);
            lens.erase(lens.find(R - L + 1));

            if(L <= pos - 1) {
                segs.insert({L, pos - 1});
                lens.insert(pos - L);
            }

            if(pos < R) {
                segs.insert({pos + 1, R});
                lens.insert(R - pos);
            }

            int newL = pos, newR = pos;
            auto rightIt = segs.lower_bound({pos + 1, 0});

            if(rightIt != segs.end() && rightIt->first == pos + 1 && s[pos + 1] == ch) {
                lens.erase(lens.find(rightIt->second - rightIt->first + 1));
                newR = rightIt->second;
                segs.erase(rightIt);
            }

            auto leftIt = segs.lower_bound({pos, 0});

            if(leftIt != segs.begin()) {
                --leftIt;

                if(leftIt->second == pos - 1 && s[pos - 1] == ch) {
                    lens.erase(lens.find(leftIt->second - leftIt->first + 1));
                    newL = leftIt->first;
                    segs.erase(leftIt);
                }
            }

            segs.insert({newL, newR});
            lens.insert(newR - newL + 1);
            s[pos] = ch;
        }

        ans[i] = *lens.rbegin();
    }

    return ans;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string s, string queryCharacters, vector<int> queryIndices, vector<int> expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Query characters: " << "\"" << queryCharacters << "\"" << endl;

    cout << "Query indicies: ";
    printArray(queryIndices);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(longestRepeating(s, queryCharacters, queryIndices));

    cout << endl;
}

int main() {
    test("babacc", "bcb", {1, 3, 3}, {3, 3, 4});
    test("abyzz", "aa", {2, 1}, {2, 3});
    test("aaaa", "a", {2}, {4});
    test("abcde", "aeioo", {0, 4, 2, 1, 3}, {1, 1, 1, 1, 1});
    test("ab", "b", {0}, {2});

    return 0;
}
