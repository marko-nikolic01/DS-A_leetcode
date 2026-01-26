#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> pairs;
    int minimumDifference = INT_MAX;
    int difference;

    sort(arr.begin(), arr.end());

    int n = arr.size();
    for(int i = 1; i < n; ++i) {
        difference = arr[i] - arr[i - 1];

        if(difference < minimumDifference) {
            pairs.resize(0);
            pairs.push_back({arr[i - 1], arr[i]});
            minimumDifference = difference;
        } else if(difference == minimumDifference) {
            pairs.push_back({arr[i - 1], arr[i]});
        }
    }

    return pairs;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr, vector<vector<int>> expected) {
    cout << "Array: ";
    printArray(arr);

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[" << e[0] << ", " << e[1] << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<int> result : minimumAbsDifference(arr)) {
        cout << "[" << result[0] << ", " << result[1] << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({4, 2, 1, 3}, {{1, 2}, {2, 3}, {3, 4}});
    test({1, 3, 6, 10, 15}, {{1, 3}});
    test({3, 8, -10, 23, 19, -4, -14, 27}, {{-14, -10}, {19, 23}, {23, 27}});
    test({5, 7, 9, 11}, {{5, 7}, {7, 9}, {9, 11}});
    test({-1000000, 0, 999999, 1000000}, {{999999, 1000000}});

    return 0;
}
