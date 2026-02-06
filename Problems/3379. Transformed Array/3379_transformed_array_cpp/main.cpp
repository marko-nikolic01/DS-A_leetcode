#include <iostream>
#include <vector>

using namespace std;

vector<int> constructTransformedArray(vector<int>& nums) {
    short n = nums.size();
    vector<int> transformed(n);
    short normalization = 100 * n;

    for(short i = n - 1; i > -1; --i) {
        transformed[i] = nums[(i + normalization + nums[i]) % n];
    }

    return transformed;
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
    printArray(constructTransformedArray(nums));

    cout << endl;
}

int main() {
    test({3, -2, 1, 1}, {1, 1, 1, 3});
    test({-1, 4, -1}, {-1, -1, 4});
    test({0, 0, 0, 0}, {0, 0, 0, 0});
    test({2, -3, 1, -1, 2}, {1, -1, -1, 1, -3});
    test({5}, {5});

    return 0;
}
