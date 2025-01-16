#include <iostream>
#include <vector>

using namespace std;

int countSubarrays(vector<int>& nums) {
    short subarrays = 0;

    for(short i = nums.size() - 1; i > 1; --i) {
        if(nums[i] + nums[i - 2] == nums[i - 1] / 2.) {
            ++subarrays;
        }
    }

    return subarrays;
}

void test(vector<int> nums, int expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSubarrays(nums) << endl;

    cout << endl;
}

int main()
{
    test({1, 2, 1, 4, 1}, 1);
    test({1, 1, 1}, 0);
    test({1, 4, 2, 4, 1}, 0);
    test({10, 20, 10, 5, 1}, 0);
    test({0, 0, 0, 0, 0}, 3);

    return 0;
}
