#include <iostream>
#include <vector>

using namespace std;

vector<int> transformArray(vector<int>& nums) {
    short left = 0;

    for(short n = nums.size() - 1; n >= left; --n) {
        if((nums[n] & 1) > 0) {
            nums[n] = 1;
        } else {
            nums[n++] = nums[left];
            nums[left++] = 0;
        }
    }

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
    printArray(transformArray(nums));

    cout << endl;
}

int main() {
    test({4, 3, 2, 1}, {0, 0, 1, 1});
    test({1, 5, 1, 4, 2}, {0, 0, 1, 1, 1});
    test({10, 15, 20, 25}, {0, 0, 1, 1});
    test({7, 8, 9, 10, 11}, {0, 0, 1, 1, 1});
    test({100, 101, 102, 103, 104, 105}, {0, 0, 0, 1, 1, 1});

    return 0;
}
