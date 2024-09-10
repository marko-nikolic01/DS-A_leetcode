#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> appearances;

    vector<int> majority;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(appearances.find(nums[i]) == appearances.end()) {
            appearances[nums[i]] = 1;
        } else {
            appearances[nums[i]]++;
        }

        if(appearances[nums[i]] == n / 3 + 1) {
            majority.push_back(nums[i]);
        }
    }

    return majority;
}

void printResult(vector<int> nums, vector<int> expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int num : majorityElement(nums)) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    printResult({3, 2, 3}, {3});

    printResult({1, 1, 1, 3, 3, 2, 2, 2}, {1, 2});

    printResult({1}, {1});

    printResult({1, 2}, {});

    printResult({4, 4, 4, 4, 5, 5, 5, 6, 6, 6}, {4});

    return 0;
}
