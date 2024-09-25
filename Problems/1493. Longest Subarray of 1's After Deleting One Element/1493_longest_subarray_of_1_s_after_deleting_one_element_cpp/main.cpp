#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int length = 0;

    int current = 0;
    int last = 0;

    bool zeroExists = false;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] == 1) {
            if(++current + last > length) {
                length = current + last;
            }
        } else {
            zeroExists = true;
            last = current;
            current = 0;
        }
    }

    return zeroExists ? length : --length;
}

void runTest(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestSubarray(nums) << endl;

    cout << endl;
}

int main()
{
    runTest({1, 1, 0, 1}, 3);
    runTest({0, 1, 1, 1, 0, 1, 1, 0}, 5);
    runTest({1, 1, 1, 1}, 3);
    runTest({0, 0, 0}, 0);
    runTest({1, 1, 0, 1, 1, 1}, 5);
    runTest({1}, 0);
    runTest({0}, 0);
    runTest({0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0}, 5);
    runTest({0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1}, 5);

    return 0;
}
