#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum2(const vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& combination, int target, int index) {
    if (target == 0) {
        combinations.push_back(combination);
        return;
    }

    for (size_t i = index; i < candidates.size(); ++i) {
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        if (candidates[i] > target) {
            return;
        }

        int candidate = candidates[i];
        combination.push_back(candidate);
        combinationSum2(candidates, combinations, combination, target - candidate, i + 1);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> combination;

    sort(candidates.begin(), candidates.end());

    combinationSum2(candidates, combinations, combination, target, 0);

    return combinations;
}

void printCombinations(const vector<vector<int>>& combinations) {
    cout << "[";
    for (size_t i = 0; i < combinations.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < combinations[i].size(); ++j) {
            cout << combinations[i][j];
            if (j < combinations[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < combinations.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void runTest(vector<int>& candidates, int target, vector<vector<int>>& expected) {
    cout << "Candidates = [";
    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << candidates[i];
        if (i < candidates.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout<< "Target = " << target << endl;

    cout << "Expected: ";
    printCombinations(expected);
    cout << endl;

    cout << "Result: ";
    printCombinations(combinationSum2(candidates, target));
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> candidates1 = {10, 1, 2, 7, 6, 5};
    int target1 = 8;
    vector<vector<int>> expected1 = {{1, 2, 5}, {1, 7}, {2, 6}};
    runTest(candidates1, target1, expected1);

    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    vector<vector<int>> expected2 = {{1, 2, 2}, {5}};
    runTest(candidates2, target2, expected2);

    vector<int> candidates3 = {1, 1, 1, 1};
    int target3 = 2;
    vector<vector<int>> expected3 = {{1, 1}};
    runTest(candidates3, target3, expected3);

    vector<int> candidates4 = {3, 4, 5, 6};
    int target4 = 9;
    vector<vector<int>> expected4 = {{3, 6}, {4, 5}};
    runTest(candidates4, target4, expected4);

    vector<int> candidates5 = {1, 2, 3, 4, 5, 6};
    int target5 = 7;
    vector<vector<int>> expected5 = {{1, 2, 4}, {1, 6}, {2, 5}, {3, 4}};
    runTest(candidates5, target5, expected5);

    return 0;
}
