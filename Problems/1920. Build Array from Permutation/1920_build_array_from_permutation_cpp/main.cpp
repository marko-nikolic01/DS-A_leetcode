#include <iostream>
#include <vector>

using namespace std;

vector<int> buildArray(vector<int>& nums) {
    short n = nums.size();
    vector<int> result(n);

    for(--n; n > -1; --n) {
        result[n] = nums[nums[n]];
    }

    return result;
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
    printArray(buildArray(nums));

    cout << endl;
}

int main() {
    test({0, 2, 1, 5, 3, 4}, {0, 1, 2, 4, 5, 3});
    test({5, 0, 1, 2, 3, 4}, {4, 5, 0, 1, 2, 3});
    test({0}, {0});
    test({4, 3, 2, 1, 0}, {0, 1, 2, 3, 4});
    test({3, 1, 4, 0, 2}, {0, 1, 2, 3, 4});

    return 0;
}
