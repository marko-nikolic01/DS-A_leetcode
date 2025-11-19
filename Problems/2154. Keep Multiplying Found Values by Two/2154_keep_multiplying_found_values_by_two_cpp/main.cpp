#include <iostream>
#include <vector>

using namespace std;

int findFinalValue(vector<int>& nums, int original) {
    vector<bool> occurences(1001, false);

    for(short i = nums.size() - 1; i > -1; --i) {
        occurences[nums[i]] = true;
    }

    while(original < 1001 && occurences[original]) {
        original <<= 1;
    }

    return original;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int original, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Original: " << original << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findFinalValue(nums, original) << endl;

    cout << endl;
}

int main() {
    test({5, 3, 6, 1, 12}, 3, 24);
    test({2, 7, 9}, 4, 4);
    test({1, 2, 4, 8, 16}, 1, 32);
    test({10, 5, 20, 40}, 5, 80);
    test({7, 14, 28, 56, 3}, 3, 6);

    return 0;
}
