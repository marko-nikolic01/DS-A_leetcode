#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count = 1;
    int index = 1;

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
       if(nums[i] == nums[index - 1]) {
        if(count < 2) {
            nums[index++] = nums[i];
            count++;
        }
       } else {
        nums[index++] = nums[i];
        count = 1;
       }
    }

    return index;
}

void printVector(const vector<int>& vec, int length) {
    cout << "[";
    for (int i = 0; i < length; ++i) {
        cout << vec[i];
        if (i < length - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void testRemoveDuplicates(vector<int> nums, const vector<int>& expected) {
    cout << "Input: ";
    printVector(nums, nums.size());

    cout << "Expected: ";
    printVector(expected, expected.size());

    cout << "Result: ";
    printVector(nums, removeDuplicates(nums));
    cout << endl;
}

int main() {
    testRemoveDuplicates({1, 1, 1, 2, 2, 3}, {1, 1, 2, 2, 3});
    testRemoveDuplicates({0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 0, 1, 1, 2, 2, 3, 3, 4});
    testRemoveDuplicates({1, 1, 1, 1}, {1, 1});
    testRemoveDuplicates({1, 2, 2, 3, 3, 3, 4}, {1, 2, 2, 3, 3, 4});
    testRemoveDuplicates({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});

    return 0;
}
