#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int sum = 0;

    for(int n = nums.size() - 2; n > -1; n -= 2) {
        sum += nums[n];
    }

    return sum;
}

void test(vector<int> nums, int expected) {
    cout << "Array: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    int result = arrayPairSum(nums);

    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    test({1, 4, 3, 2}, 4);
    test({6, 2, 6, 5, 1, 2}, 9);
    test({7, 3, 1, 0, 0, 6}, 7);
    test({1, 2}, 1);
    test({9, 5, 4, 8, 2, 1}, 13);

    return 0;
}
