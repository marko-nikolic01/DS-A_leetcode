#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> secondGreaterElement(vector<int>& nums) {
    stack<int> nextGreater;
    nextGreater.push(0);

    priority_queue<int> secondNextGreater;

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        while(!secondNextGreater.empty() && nums[i] > nums[secondNextGreater.top()]) {
            nums[secondNextGreater.top()] = nums[i];
            secondNextGreater.pop();
        }

        while(!nextGreater.empty() && nums[i] > nums[nextGreater.top()]) {
            secondNextGreater.push(nextGreater.top());
            nextGreater.pop();
        }

        nextGreater.push(i);
    }

    while(!nextGreater.empty()) {
        nums[nextGreater.top()] = -1;
        nextGreater.pop();
    }

    while(!secondNextGreater.empty()) {
        nums[secondNextGreater.top()] = -1;
        secondNextGreater.pop();
    }

    return nums;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for(int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for(int result : secondGreaterElement(nums)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {2, 4, 0, 9, 6};
    vector<int> expected1 = {9, 6, 6, -1, -1};
    test(nums1, expected1);

    vector<int> nums2 = {3, 3};
    vector<int> expected2 = {-1, -1};
    test(nums2, expected2);

    vector<int> nums3 = {11, 13, 15, 12, 0, 15, 12, 11, 9};
    vector<int> expected3 = {15, 15, -1, -1, 12, -1, -1, -1, -1};
    test(nums3, expected3);

    vector<int> nums4 = {1, 2, 3, 4, 5};
    vector<int> expected4 = {3, 4, 5, -1, -1};
    test(nums4, expected4);

    vector<int> nums5 = {5, 4, 3, 2, 1};
    vector<int> expected5 = {-1, -1, -1, -1, -1};
    test(nums5, expected5);

    return 0;
}
