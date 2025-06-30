#include <iostream>
#include <vector>

using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    short n = nums.size();
    nums.resize(n << 1);

    short iConcatenation = n;
    for(short i = 0; i < n; ++i) {
        nums[iConcatenation++] = nums[i];
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
    printArray(getConcatenation(nums));

    cout << endl;
}

int main() {
    test({1, 2, 1}, {1, 2, 1, 1, 2, 1});
    test({1, 3, 2, 1}, {1, 3, 2, 1, 1, 3, 2, 1});
    test({5}, {5, 5});
    test({7, 8, 9}, {7, 8, 9, 7, 8, 9});
    test({10, 20, 30, 40, 50}, {10, 20, 30, 40, 50, 10, 20, 30, 40, 50});

    return 0;
}
