#include <iostream>
#include <vector>

using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    vector<bool> occurences(10001, false);
    int maxSum = 0;
    int sum = 0;

    int end = nums.size();
    for(int i = --end; i > -1; --i) {
        while(occurences[nums[i]]) {
            occurences[nums[end]] = false;
            sum -= nums[end--];
        }

        occurences[nums[i]] = true;
        sum += nums[i];

        if(sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
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

    cout << "Result: " << maximumUniqueSubarray(nums) << endl;

    cout << endl;
}

int main() {
    test({4, 2, 4, 5, 6}, 17);
    test({1, 2, 3, 4, 5}, 15);
    test({2, 2, 2, 2}, 2);
    test({5, 2, 1, 2, 5, 2, 1, 2, 5}, 8);
    test({1, 1, 2, 3, 4, 1, 1}, 10);

    return 0;
}
