#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<vector<int>> winners(2);
    unordered_map<int, int> losses;

    for(int i = matches.size() - 1; i > -1; --i) {
        if(losses.find(matches[i][0]) == losses.end()) {
            losses[matches[i][0]] = 0;
        }

        ++losses[matches[i][1]];
    }

    for(unordered_map<int, int>::iterator it = losses.begin(); it != losses.end(); ++it) {
        if(it->second < 1) {
            winners[0].push_back(it->first);
        } else if(it->second < 2) {
            winners[1].push_back(it->first);
        }
    }

    sort(winners[0].begin(), winners[0].end());
    sort(winners[1].begin(), winners[1].end());

    return winners;
}

void test(vector<vector<int>> matches, vector<vector<int>> expected) {
    cout << "Matches: ";
    for(vector<int> match : matches) {
        cout << "[" << match[0] << ", " << match[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[";
        for(int i = 0; i < e.size(); ++i) {
            cout << e[i];
            if(i != e.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<int> result : findWinners(matches)) {
        cout << "[";
        for(int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if(i != result.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}}, {{1, 2, 10}, {4, 5, 7, 8}});
    test({{2, 3}, {1, 3}, {5, 4}, {6, 4}}, {{1, 2, 5, 6}, {}});
    test({{1, 2}}, {{1}, {2}});
    test({{3, 1}, {4, 1}, {5, 1}, {6, 1}}, {{3, 4, 5, 6}, {}});
    test({{1, 5}, {2, 5}, {3, 5}, {4, 5}, {6, 1}, {6, 2}, {6, 3}}, {{4, 6}, {1, 2, 3}});

    return 0;
}
