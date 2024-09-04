#include <iostream>
#include <vector>

using namespace std;

void combine(vector<vector<int>>& combinations, vector<int>& combination, int n, int k, int start) {
    if(k == 0) {
        combinations.push_back(combination);
        return;
    }

    for(start; start <= n - k + 1; ++start) {
        combination.push_back(start);
        combine(combinations, combination, n, k - 1, start + 1);
        combination.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> combinations;
    vector<int> combination;

    combine(combinations, combination, n, k, 1);

    return combinations;
}

void printVectorVector(const vector<vector<int>>& vec) {
    for (const auto& v : vec) {
        cout << "[ ";
        for (int num : v) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

void testCombine(int n, int k, const vector<vector<int>>& expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printVectorVector(expected);

    cout << "Result: ";
    printVectorVector(combine(n, k));

    cout << endl;
}

int main() {
    testCombine(4, 2, {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}});
    testCombine(3, 2, {{1, 2}, {1, 3}, {2, 3}});
    testCombine(5, 3, {{1, 2, 3}, {1, 2, 4}, {1, 2, 5}, {1, 3, 4}, {1, 3, 5}, {1, 4, 5}, {2, 3, 4}, {2, 3, 5}, {2, 4, 5}, {3, 4, 5}});
    testCombine(2, 2, {{1, 2}});
    testCombine(1, 1, {{1}});

    return 0;
}
