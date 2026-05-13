#include <iostream>
#include <vector>

using namespace std;

vector<int> findValidElements(vector<int>& nums) {
    short n = nums.size();
    short maximum = 0;

    short j;
    for(j = --n; j > -1; --j) {
        if(nums[j] > maximum) {
            maximum = nums[j];
            nums[j] = -nums[j];
        }
    }

    maximum = 0;

    for(short i = 0; i <= n; ++i) {
        if(nums[i] < 0) {
            if(-nums[i] > maximum) {
                maximum = -nums[i];
            }

            nums[++j] = -nums[i];
        } else if(nums[i] > maximum) {
            maximum = nums[i];
            nums[++j] = nums[i];
        }
    }

    nums.resize(++j);

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findValidElements(nums));

    cout << endl;
}

int main() {
    test({1, 2, 4, 2, 3, 2}, {1, 2, 4, 3, 2});
    test({5, 5, 5, 5}, {5, 5});
    test({1}, {1});
    test({5, 1, 3}, {5, 3});
    test({3, 1, 4, 2, 5}, {3, 4, 5});
    test({1, 2, 3}, {1, 2, 3});
    test({3, 2, 1}, {3, 2, 1});

    return 0;
}
