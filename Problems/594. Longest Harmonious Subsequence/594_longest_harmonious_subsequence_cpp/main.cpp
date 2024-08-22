#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> lengths;

    int max = 0;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(lengths.find(nums[i]) == lengths.end()) {
            lengths[nums[i]] = 1;
        } else {
            lengths[nums[i]]++;
        }

        if(lengths.find(nums[i] - 1) != lengths.end()) {
            if(max < lengths[nums[i]] + lengths[nums[i] - 1]) {
                max = lengths[nums[i]] + lengths[nums[i] - 1];
            }
        }

        if(lengths.find(nums[i] + 1) != lengths.end()) {
            if(max < lengths[nums[i]] + lengths[nums[i] + 1]) {
                max = lengths[nums[i]] + lengths[nums[i] + 1];
            }
        }
    }

    return max;
}


void runTestCase(vector<int> nums, int expected) {
    int result = findLHS(nums);

    cout << "Vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    cout << "Test Cases:\n";

    runTestCase({1, 3, 2, 2, 5, 2, 3, 7}, 5);
    runTestCase({1, 2, 3, 4}, 2);
    runTestCase({1, 1, 1, 1}, 0);
    runTestCase({1, 2, 2, 1, 1, 2}, 6);
    runTestCase({2, 2, 2, 2}, 0);

    return 0;
}
