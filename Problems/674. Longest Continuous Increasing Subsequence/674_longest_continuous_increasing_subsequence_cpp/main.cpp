#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    int longest = 0;
    int current = 0;

    for(int n = nums.size() - 2; n > -1; --n) {
        if(nums[n] < nums[n + 1]) {
            if(++current > longest) {
                longest = current;
            }
        } else {
            current = 0;
        }
    }

    return ++longest;
}

void printVector(const vector<int>& nums) {
    cout << "[ ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "]";
}

// Test cases
int main() {
    vector<vector<int>> testCases = {
        {1, 3, 5, 4, 7},
        {2, 2, 2, 2, 2},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {1, 3, 5, 7},
        {10, 9, 8, 7, 6},
        {1, 2, 2, 3, 4},
        {1}
    };

    vector<int> expectedResults = {3, 1, 5, 1, 4, 1, 3, 1};

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test case " << i + 1 << ":" << endl;
        cout << "Input: ";
        printVector(testCases[i]);
        cout << endl;

        cout << "Expected: " << expectedResults[i] << endl;
        cout << "Result: " << findLengthOfLCIS(testCases[i]) << endl;
        cout << endl;
    }

    return 0;
}
