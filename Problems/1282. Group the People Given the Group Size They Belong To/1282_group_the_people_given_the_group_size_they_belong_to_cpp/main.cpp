#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> emptyGroups;
    vector<vector<int>> groups;

    for(int i = groupSizes.size() - 1; i > -1; --i) {
        if(groupSizes[i] == 1) {
                groups.push_back({i});
                continue;
            }

        if(emptyGroups.find(groupSizes[i]) == emptyGroups.end()) {
            emptyGroups[groupSizes[i]] = {i};
        } else {
            emptyGroups[groupSizes[i]].push_back(i);
            if(emptyGroups[groupSizes[i]].size() == groupSizes[i]) {
                groups.push_back(emptyGroups[groupSizes[i]]);
                emptyGroups[groupSizes[i]].resize(0);
            }
        }
    }

    return groups;
}

void test(vector<int> groupSizes, vector<vector<int>> expected) {
    cout << "Group sizes: ";
    for (int size : groupSizes) {
        cout << size << " ";
    }
    cout << endl;

    cout << "Expected: [";
    for (const auto& group : expected) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i];
            if (i < group.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;

    cout << "Result: [";
    for (const auto& group : groupThePeople(groupSizes)) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i];
            if (i < group.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;

    cout << endl;
}

int main() {
    test({3, 3, 3, 3, 3, 1, 3}, {{5}, {6, 4, 3}, {2, 1, 0}});
    test({2, 1, 3, 3, 3, 2}, {{4, 3, 2}, {1}, {5, 0}});
    test({1, 1, 1, 1, 1}, {{4}, {3}, {2}, {1}, {0}});
    test({4, 4, 4, 4, 4, 4, 4, 4}, {{7, 6, 5, 4}, {3, 2, 1, 0}});
    test({6, 6, 6, 6, 6, 6}, {{5, 4, 3, 2, 1, 0}});
    test({1, 2, 1, 2, 1, 2, 2}, {{6, 5}, {4}, {2}, {3, 1}, {0}});

    return 0;
}
