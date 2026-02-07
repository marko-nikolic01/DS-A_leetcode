#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();
    int removals = n--;

    sort(nums.begin(), nums.end());

    int right = removals;
    for(int left = --right; left > -1; --left) {
        while((long)k * nums[left] < nums[right]) {
            --right;
        }

        while(left > -1 && (long)k * nums[left] >= nums[right]) {
            --left;
        }

        removals = min(removals, ++left + n - right);
    }

    return removals;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minRemoval(nums, k) << endl;

    cout << endl;
}

int main() {
    test({2, 1, 5}, 2, 1);
    test({1, 6, 2, 9}, 3, 2);
    test({4, 6}, 2, 0);
    test({1, 2, 3, 4, 5}, 1, 4);
    test({10, 10, 10, 10}, 5, 0);

    return 0;
}
