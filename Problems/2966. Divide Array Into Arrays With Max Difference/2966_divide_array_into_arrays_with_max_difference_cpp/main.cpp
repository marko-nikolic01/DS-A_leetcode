#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> divisions(n / 3, vector<int>(3));

    sort(nums.begin(), nums.end());

    int iDivision = 0;
    for(int i = 0; i < n; ++i) {
        if(nums[i + 2] - nums[i] > k) {
            return {};
        }

        divisions[iDivision][0] = nums[i++];
        divisions[iDivision][1] = nums[i++];
        divisions[iDivision++][2] = nums[i];
    }

    return divisions;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, vector<vector<int>> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[" << e[0] << ", " << e[1] << ", " << e[2] << "] ";
    }
    cout << endl;

    cout << "Result:   ";
    for(vector<int> result : divideArray(nums, k)) {
        cout << "[" << result[0] << ", " << result[1] << ", " << result[2] << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({1, 3, 4, 8, 7, 9, 3, 5, 1}, 2, {{1, 1, 3}, {3, 4, 5}, {7, 8, 9}});
    test({2, 4, 2, 2, 5, 2}, 2, {});
    test({4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11}, 14, {{2, 2, 2}, {4, 5, 5}, {5, 5, 7}, {7, 8, 8}, {9, 9, 10}, {11, 12, 12}});
    test({5, 5, 5, 5, 5, 5}, 0, {{5, 5, 5}, {5, 5, 5}});
    test({1, 2, 3, 100, 101, 102}, 2, {{1, 2, 3}, {100, 101, 102}});
    test({1, 2, 3, 100, 1001, 1002}, 2, {});

    return 0;
}
