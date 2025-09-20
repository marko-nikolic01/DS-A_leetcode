#include <iostream>
#include <vector>

using namespace std;

int countStableSubsequences(vector<int>& nums) {
    long evenSubsequences1 = 0;
    long evenSubsequences2 = 0;
    long oddSubsequences1 = 0;
    long oddSubsequences2 = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        if((nums[i] & 1) < 1) {
            evenSubsequences2 = (evenSubsequences2 + evenSubsequences1) % 1000000007;
            evenSubsequences1 = (++evenSubsequences1 + oddSubsequences1 + oddSubsequences2) % 1000000007;
        } else {
            oddSubsequences2 = (oddSubsequences2 + oddSubsequences1) % 1000000007;
            oddSubsequences1 = (++oddSubsequences1 + evenSubsequences1 + evenSubsequences2) % 1000000007;
        }
    }

    return (evenSubsequences1 + evenSubsequences2 + oddSubsequences1 + oddSubsequences2) % 1000000007;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countStableSubsequences(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 5}, 6);
    test({2, 3, 4, 2}, 14);
    test({7}, 1);
    test({2, 4}, 3);
    test({2, 4, 6}, 6);
    test({1, 2, 3, 4}, 15);

    return 0;
}
