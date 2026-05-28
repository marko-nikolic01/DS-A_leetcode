#include <iostream>
#include <vector>

using namespace std;

vector<int> limitOccurrences(vector<int>& nums, int k) {
    short occurences = 1;

    short iLimited = 0;
    short n = nums.size();
    for(short i = 1; i < n; ++i) {
        if(nums[i] > nums[iLimited]) {
            nums[++iLimited] = nums[i];
            occurences = 1;
        } else if(++occurences <= k) {
            nums[++iLimited] = nums[i];
        }
    }

    nums.resize(++iLimited);

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(limitOccurrences(nums, k));

    cout << endl;
}

int main() {
    test({1, 1, 1, 2, 2, 3}, 2, {1, 1, 2, 2, 3});
    test({1, 2, 3}, 1, {1, 2, 3});
    test({1, 1, 1, 1}, 3, {1, 1, 1});
    test({1, 1, 2, 2, 3, 3}, 1, {1, 2, 3});
    test({1}, 1, {1});

    return 0;
}
