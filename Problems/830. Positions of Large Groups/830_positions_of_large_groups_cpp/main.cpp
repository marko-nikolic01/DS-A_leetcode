#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> groups;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        int j = i + 1;
        while(j < n && s[j] == s[i]) {
            j++;
        }

        if(--j - i > 1) {
            groups.push_back({i, j});
        }

        i = j;
    }

    return groups;
}

void testLargeGroupPositions(const string& input, const vector<vector<int>>& expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Expected: [";
    for (const auto& group : expected) {
        cout << "[" << group[0] << ", " << group[1] << "]";
    }
    cout << "]" << endl;

    cout << "Result: [";
    for (const auto& group : largeGroupPositions(input)) {
        cout << "[" << group[0] << ", " << group[1] << "]";
    }
    cout << "]" << endl;

    cout << endl;
}

int main() {
    testLargeGroupPositions("abbxxxxzzy", {{3, 6}});
    testLargeGroupPositions("abc", {});
    testLargeGroupPositions("abcdddeeeeaabbbcd", {{3, 5}, {6, 9}, {12, 14}});
    testLargeGroupPositions("aaa", {{0, 2}});
    testLargeGroupPositions("aabbccc", {{4, 6}});

    return 0;
}
