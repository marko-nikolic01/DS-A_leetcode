#include <iostream>
#include <vector>

using namespace std;

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, pair<int, int>> occurences;

    int shortest = 50000;
    int degree = 1;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(occurences.find(nums[i]) == occurences.end()) {
            occurences[nums[i]] = {1, i};
        } else {
            occurences[nums[i]].first++;
        }

        if(occurences[nums[i]].first > degree) {
            degree = occurences[nums[i]].first;
            shortest = i - occurences[nums[i]].second + 1;
        } else if(occurences[nums[i]].first == degree) {
            int length = i - occurences[nums[i]].second + 1;
            if(length < shortest) {
                shortest = length;
            }
        }
    }

    return shortest;
}

void runTest(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    int result = findShortestSubArray(nums);
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    runTest({1, 2, 2, 3, 1}, 2);
    runTest({1, 2, 2, 3, 1, 4, 2}, 6);
    runTest({1, 1, 1, 2, 2, 2}, 3);
    runTest({1, 2, 3, 4, 5}, 1);
    runTest({1, 2, 2, 3, 3, 3, 4}, 3);

    return 0;
}
