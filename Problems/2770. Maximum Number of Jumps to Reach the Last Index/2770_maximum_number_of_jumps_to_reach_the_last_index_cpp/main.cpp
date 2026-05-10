#include <iostream>
#include <vector>

using namespace std;

int maximumJumps(vector<int>& nums, int target) {
    short n = nums.size();
    vector<short> jumps(n--, -1);

    ++jumps[0];

    short j;
    for(short i = 0; i < n; ++i) {
        if(jumps[i] > -1) {
            for(j = i + 1; j <= n; ++j) {
                if(abs(nums[j] - nums[i]) <= target && jumps[i] >= jumps[j]) {
                    jumps[j] = jumps[i] + 1;
                }
            }
        }
    }

    return jumps[n];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int target, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumJumps(nums, target) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 6, 4, 1, 2}, 2, 3);
    test({1, 3, 6, 4, 1, 2}, 3, 5);
    test({1, 3, 6, 4, 1, 2}, 0, -1);
    test({0, 2, 1, 3}, 1, -1);
    test({1, 5}, 10, 1);

    return 0;
}
