#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long countPalindromePaths(int x, int mask, string &s, vector<vector<int>>& con, unordered_map<int, int>& have) {
    long r = 0;

    int i;
    if(x) {
        mask ^= 1 << (s[x] - 'a');

        i = 1 << 25;
        while(i > 0) {
            if(have.count(mask ^ i)) {
                r += have[mask ^ i];
            }

            i >>= 1;
        }

        r += have[mask]++;
    }

    int n = con[x].size();
    for(i = 0; i < n; ++i) {
        r += countPalindromePaths(con[x][i], mask, s, con, have);
    }

    return r;
}

long long countPalindromePaths(vector<int>& parent, string s) {
    int n = s.length();
    vector<vector<int>> con(n);
    unordered_map<int, int> have;

    ++have[0];

    for(int i = 1; i < n; ++i) {
        con[parent[i]].push_back(i);
    }

    return countPalindromePaths(0, 0, s, con, have);
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> parent, string s, long long expected) {
    cout << "Parents: ";
    printArray(parent);

    cout << "Edges: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPalindromePaths(parent, s) << endl;

    cout << endl;
}

int main() {
    test({-1, 0, 0, 1, 1, 2}, "acaabc", 8);
    test({-1, 0, 0, 0, 0}, "aaaaa", 10);
    test({-1, 0}, "aa", 1);
    test({-1, 0, 1}, "aaa", 3);
    test({-1, 0, 1, 2}, "aaaa", 6);

    return 0;
}
