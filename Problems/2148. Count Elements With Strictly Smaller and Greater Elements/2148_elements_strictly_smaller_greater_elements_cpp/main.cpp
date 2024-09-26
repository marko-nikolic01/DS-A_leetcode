#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int countElements(vector<int>& nums) {
    int max = INT_MIN;
    int maxCount = 0;

    int min = INT_MAX;
    int minCount = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] > max) {
            max = nums[i];
            maxCount = 1;
        } else if(nums[i] == max) {
            maxCount++;
        }

        if(nums[i] < min) {
            min = nums[i];
            minCount = 1;
        } else if(nums[i] == min) {
            minCount++;
        }
    }

    return max == min ? 0 : nums.size() - maxCount - minCount;
}

void runTest(vector<int> nums, int expected) {
    int result = countElements(nums);
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << result << endl;

    cout << endl;
}

int main()
{
    runTest({1, 2, 3, 4, 5}, 3);
    runTest({1, 1, 1, 1, 1}, 0);
    runTest({1, 2, 2, 3, 4, 4, 5}, 5);
    runTest({5, 5, 5, 5}, 0);
    runTest({0, 10, 0, 10}, 0);
    runTest({3, 3, 4, 4, 5, 5}, 2);
    runTest({1}, 0);
    runTest({4, 1, 3, 5, 2}, 3);

    return 0;
}
