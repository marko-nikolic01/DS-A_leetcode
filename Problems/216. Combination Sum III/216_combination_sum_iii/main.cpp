#include <iostream>
#include <vector>

using namespace std;

void combinationSum3(vector<vector<int>>& combinations, vector<int>& combination, short k, short n, short number) {
    if(n == 0 && k < 1) {
        combinations.push_back(combination);
    } else if(n > 0 && k > 0 && number < 10) {
        combination.push_back(number);
        combinationSum3(combinations, combination, --k, n - number, number + 1);
        combination.pop_back();
        combinationSum3(combinations, combination, ++k, n, ++number);
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> combinations;
    vector<int> combination;

    combinationSum3(combinations, combination, k, n, 1);

    return combinations;
}

void test(int k, int n, vector<vector<int>> intervals, vector<vector<int>> expected) {
    cout << "k: " << k << endl;

    cout << "n: " << n << endl;

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
    for(vector<int> result : combinationSum3(k, n)) {
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
    test(3, 7, {}, {{1, 2, 4}});
    test(3, 9, {}, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}});
    test(4, 1, {}, {});
    test(2, 9, {}, {{1, 8}, {2, 7}, {3, 6}, {4, 5}});
    test(4, 30, {}, {{6, 7, 8, 9}});

    return 0;
}
