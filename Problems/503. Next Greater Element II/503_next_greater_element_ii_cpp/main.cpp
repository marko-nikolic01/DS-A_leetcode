#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    vector<int> nextGreaters(n, -1);
    stack<int> unsolved;

    int solved = 0;

    for(int i = 0; i < 2 * n; ++i) {
        while(!unsolved.empty() && nums[unsolved.top()] < nums[i % n]) {
            nextGreaters[unsolved.top()] = nums[i % n];
            unsolved.pop();

            if(++solved == n - 1) {
                break;
            }
        }

        if(i < n) {
            unsolved.push(i);
        }
    }

    return nextGreaters;
}

void runTest(vector<int> nums, vector<int> expected) {
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
    for (int num : nextGreaterElements(nums)) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    runTest({1, 2, 1}, {2, -1, 2});
    runTest({3, 8, 4, 1, 2}, {8, -1, 8, 2, 3});
    runTest({6, 5, 4, 3, 2, 1}, {-1, 6, 6, 6, 6, 6});
    runTest({5, 4, 3, 2, 1}, {-1, 5, 5, 5, 5});

    return 0;
}
