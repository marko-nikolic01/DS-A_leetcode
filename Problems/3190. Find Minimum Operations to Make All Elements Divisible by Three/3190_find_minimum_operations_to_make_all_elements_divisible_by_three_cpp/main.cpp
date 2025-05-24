#include <iostream>
#include <vector>

using namespace std;

int minimumOperations(vector<int>& nums) {
    short operations = 0;

    for(short i = nums.size() - 1; i > -1; --i) {
        if(nums[i] % 3 > 0) {
            ++operations;
        }
    }

    return operations;
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

    cout << "Result: " << minimumOperations(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4}, 3);
    test({3, 6, 9}, 0);
    test({1, 4, 7}, 3);
    test({2, 5, 8, 11}, 4);
    test({3, 4, 5, 6, 7}, 3);

    return 0;
}
