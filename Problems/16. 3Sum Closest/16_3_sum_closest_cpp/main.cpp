#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int closest;
    int difference = INT_MAX;

    for(int i = 0; i < n - 2; ++i) {
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int a = i + 1;
        int b = n - 1;
        while(a < b) {
            int sum = nums[i] + nums[a] + nums[b];

            if(sum < target) {
                a++;
            } else {
                b--;
            }

            int newDifference = sum - target;
            if(newDifference < 0) {
                newDifference = -newDifference;
            }

            if(newDifference < difference) {
                closest = sum;
                difference = newDifference;
            }
        }
    }

    return closest;
}

void runTest(vector<int> nums, int target, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " <<  threeSumClosest(nums, target) << endl;

    cout << endl;
}

int main() {
    runTest({-1, 2, 1, -4}, 1, 2);
    runTest({0, 2, 1, -3}, 1, 0);
    runTest({1, 1, 1, 1}, 0, 3);
    runTest({-1, 0, 1, 1}, 1, 1);
    runTest({1, 2, 3, 4, -5}, 10, 9);

    return 0;
}
