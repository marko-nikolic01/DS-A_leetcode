#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    vector<pair<int, int>> indexes;

    int n = score.size();
    for(int i = 0; i < n; ++i) {
        indexes.push_back({score[i], i});
    }
    sort(indexes.begin(), indexes.end(), greater<pair<int, int>>());

    vector<string> ranks(n);
    ranks[indexes[0].second] = "Gold Medal";
    if(n > 1) {
        ranks[indexes[1].second] = "Silver Medal";
    }
    if(n > 2) {
        ranks[indexes[2].second] = "Bronze Medal";
    }
    for(int i = 3; i < n; ++i) {
        ranks[indexes[i].second] = to_string(i + 1);
    }

    return ranks;
}

int main() {
    vector<vector<int>> testCases = {
        {5, 4, 3, 2, 1},
        {10, 3, 8, 9, 4},
        {1},
        {100, 90, 80, 70, 60, 50}
    };

    vector<vector<string>> expectedResults = {
        {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"},
        {"Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"},
        {"Gold Medal"},
        {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"},
        {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5", "6"}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        vector<string> result = findRelativeRanks(testCases[i]);

        cout << "Number: ";
        for (int num : testCases[i]) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Expected: ";
        for (const string& expected : expectedResults[i]) {
            cout << expected << " ";
        }
        cout << endl;

        cout << "Result: ";
        for (const string& res : result) {
            cout << res << " ";
        }
        cout << endl << endl;
    }

    return 0;
}
