#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maximumMedianSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    long medianSum = 0;
    int i = nums.size();
    int limit = i-- / 3 - 1;

    for(--i; i > limit; i -= 2) {
        medianSum += nums[i];
    }

    return medianSum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumMedianSum(nums) << endl;

    cout << endl;
}

int main()
{
    test({2, 1, 3, 2, 1, 3}, 5);
    test({1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1, 1, 1}, 3000000000);
    test({7, 7, 7, 7, 7, 7}, 14);
    test({1, 2, 3, 4, 5, 6}, 8);
    test({9, 8, 7, 3, 2, 1}, 11);

    return 0;
}
