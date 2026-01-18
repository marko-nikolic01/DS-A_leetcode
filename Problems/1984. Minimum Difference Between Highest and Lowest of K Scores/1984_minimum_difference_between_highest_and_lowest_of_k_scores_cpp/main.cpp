#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int difference = nums[--k] - nums[0];

    short i;
    short n = nums.size();
    for(i = k + 1; i < n; ++i) {
        if(nums[i] - nums[i - k] < difference) {
            difference = nums[i] - nums[i - k];
        }
    }

    return difference;
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

    cout << "Result: " << minimumDifference(nums, k) << endl;

    cout << endl;
}

int main() {
    test({90}, 1, 0);
    test({9, 4, 1, 7}, 2, 2);
    test({1, 3, 6, 9, 12}, 3, 5);
    test({10, 100, 300, 200, 1000, 20, 30}, 4, 90);
    test({5, 5, 5, 5, 5}, 3, 0);

    return 0;
}
