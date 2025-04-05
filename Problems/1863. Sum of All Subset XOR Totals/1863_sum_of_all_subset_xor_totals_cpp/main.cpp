#include <iostream>
#include <vector>

using namespace std;

int subsetXORSum(vector<int>& nums) {
    int sum = 0;

    short n = nums.size();
    for(short i = 0; i < n; ++i) {
        sum |= nums[i];
    }

    return sum << --n;
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

    cout << "Result: " << subsetXORSum(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3}, 6);
    test({5, 1, 6}, 28);
    test({3, 4, 5, 6, 7, 8}, 480);
    test({5, 1, 5}, 20);
    test({5, 17, 17, 12, 17}, 464);

    return 0;
}
