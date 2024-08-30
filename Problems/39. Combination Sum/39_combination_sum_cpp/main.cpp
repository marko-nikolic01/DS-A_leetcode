#include <iostream>
#include <vector>

using namespace std;

void combinationSum(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& combination, int target, int index) {
    if(target == 0) {
        combinations.push_back(combination);
        return;
    }

    if(target < 0 || index >= candidates.size()) {
        return;
    }

    combination.push_back(candidates[index]);
    combinationSum(candidates, combinations, combination, target - candidates[index], index);
    combination.pop_back();
    combinationSum(candidates, combinations, combination, target, index + 1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> combination;

    combinationSum(candidates, combinations, combination, target, 0);

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

void runTest(vector<int>& candidates, int target, const vector<vector<int>>& expected) {
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
    printCombinations(combinationSum(candidates, target));
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> expected1 = {{2, 2, 3}, {7}};
    runTest(candidates1, target1, expected1);

    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> expected2 = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    runTest(candidates2, target2, expected2);

    vector<int> candidates3 = {2};
    int target3 = 1;
    vector<vector<int>> expected3 = {};
    runTest(candidates3, target3, expected3);

    vector<int> candidates4 = {1};
    int target4 = 2;
    vector<vector<int>> expected4 = {{1, 1}};
    runTest(candidates4, target4, expected4);

    vector<int> candidates5 = {2, 3, 7};
    int target5 = 7;
    vector<vector<int>> expected5 = {{2, 2, 3}, {7}};
    runTest(candidates5, target5, expected5);

    return 0;
}
