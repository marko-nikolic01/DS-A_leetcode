#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int maxLength = 0;
    int zeroCount = 0;

    int left = 0;
    int n = nums.size();
    for(int right = 0; right < n; ++right) {
        if(nums[right] == 0) {
            ++zeroCount;
        }

        while(zeroCount > k) {
            if (nums[left] == 0) {
                --zeroCount;
            }

            ++left;
        }

        if(right - left + 1 > maxLength) {
            maxLength = right - left + 1;
        }
    }

    return maxLength;
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

    cout << "Result: " << longestOnes(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6);
    test({0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10);
    test({0, 0, 0, 0}, 0, 0);
    test({1, 1, 1, 1}, 0, 4);
    test({0, 1, 0, 1, 0}, 5, 5);

    return 0;
}
