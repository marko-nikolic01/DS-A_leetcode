#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int missingInteger(vector<int>& nums) {
    short n = nums.size();
    unordered_set<short> numbers(nums.begin(), nums.end());
    short prefixLength = 1;

    for(short i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1] + 1) {
            ++prefixLength;
        } else {
            break;
        }
    }

    prefixLength = ((nums[prefixLength - 1] + nums[0]) * prefixLength) >> 1;

    while(numbers.count(prefixLength) > 0) {
        ++prefixLength;
    }

    return prefixLength;
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

    cout << "Result: " << missingInteger(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 2, 5}, 6);
    test({3, 4, 5, 1, 12, 14, 13}, 15);
    test({5}, 6);
    test({1, 2, 3, 4, 5}, 15);
    test({50, 1, 2, 3}, 51);

    return 0;
}
