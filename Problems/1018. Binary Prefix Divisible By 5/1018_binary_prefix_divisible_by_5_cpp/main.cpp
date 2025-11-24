#include <iostream>
#include <vector>

using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    int n = nums.size();
    vector<bool> isDivisibleBy5(n);
    short remainder = 0;

    for(int i = 0; i < n; ++i) {
        remainder = ((remainder << 1) + nums[i]) % 5;
        isDivisibleBy5[i] = remainder < 1;
    }

    return isDivisibleBy5;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<bool> array) {
    for(bool a : array) {
        cout << (a ? "true" : "false") << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<bool> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(prefixesDivBy5(nums));

    cout << endl;
}

int main() {
    test({0, 1, 1}, {true, false, false});
    test({1, 1, 1}, {false, false, false});
    test({1, 0, 1}, {false, false, true});
    test({1, 0, 0, 1, 0}, {false, false, false, false, false});
    test({1, 0, 1, 0, 0}, {false, false, true, true, true});

    return 0;
}
