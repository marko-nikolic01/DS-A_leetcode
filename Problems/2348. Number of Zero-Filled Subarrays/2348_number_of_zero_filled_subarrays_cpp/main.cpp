#include <iostream>
#include <vector>

using namespace std;

long long zeroFilledSubarray(vector<int>& nums) {
    long zeros = 0;
    long zeroSubarrays = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] == 0) {
            ++zeros;
        } else if(zeros > 0) {
            zeroSubarrays += zeros++ * (zeros) / 2;
            zeros = 0;
        }
    }

    if(zeros > 0) {
        zeroSubarrays += zeros++ * (zeros) / 2;
    }

    return zeroSubarrays;
}

void test(vector<int> nums, long long expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << zeroFilledSubarray(nums) << endl;

    cout << endl;
}

int main() {
    test({0, 0, 0}, 6);
    test({1, 0, 0, 0, 2}, 6);
    test({0, 0, 1, 0, 0, 0}, 9);
    test({0, 0, 0, 0, 0}, 15);
    test({1, 2, 3}, 0);
    test({0, 1, 2, 0, 0}, 4);
    test({0, 0, 0, 2, 0, 0}, 9);
    test({0, 1, 2, 0, 0, 3, 0, 0, 0, 4, 0, 5, 0, 0}, 14);
    test({1, 3, 0, 0, 2, 0, 0, 4}, 6);

    return 0;
}
