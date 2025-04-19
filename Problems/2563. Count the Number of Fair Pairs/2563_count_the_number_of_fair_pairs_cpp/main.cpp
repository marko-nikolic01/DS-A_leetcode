#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long pairs = 0;

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;
    while(left < right) {
        if(nums[left] + nums[right] < lower) {
            pairs -= right - left++;
        } else {
            --right;
        }
    }

    ++upper;
    left = 0;
    right = nums.size() - 1;
    while(left < right) {
        if(nums[left] + nums[right] < upper) {
            pairs += right - left++;
        } else {
            --right;
        }
    }

    return pairs;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int lower, int upper, long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Lower: " << lower << endl;

    cout << "Upper: " << upper << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countFairPairs(nums, lower, upper) << endl;

    cout << endl;
}

int main() {
    test({0, 1, 7, 4, 4, 5}, 3, 6, 6);
    test({1, 7, 9, 2, 5}, 11, 11, 1);
    test({-5, -2, 0, 3, 6}, -2, 4, 6);
    test({1, 1, 1, 1}, 2, 2, 6);
    test({10, 20, 30, 40, 50}, 60, 70, 4);

    return 0;
}
