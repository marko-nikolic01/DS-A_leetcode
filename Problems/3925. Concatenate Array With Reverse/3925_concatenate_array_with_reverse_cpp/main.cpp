#include <iostream>
#include <vector>

using namespace std;

vector<int> concatWithReverse(vector<int>& nums) {
    for(short i = nums.size() - 1; i > -1; --i) {
        nums.push_back(nums[i]);
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
    printArray(concatWithReverse(nums));

    cout << endl;
}

int main() {
    test({1, 2, 3}, {1, 2, 3, 3, 2, 1});
    test({1}, {1, 1});
    test({5, 10, 15, 20}, {5, 10, 15, 20, 20, 15, 10, 5});
    test({7, 7, 7}, {7, 7, 7, 7, 7, 7});
    test({9, 8, 1, 4, 2}, {9, 8, 1, 4, 2, 2, 4, 1, 8, 9});

    return 0;
}
