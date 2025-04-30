#include <iostream>
#include <vector>

using namespace std;

int findNumbers(vector<int>& nums) {
    short count = 0;

    for(short i = nums.size() - 1; i > -1; --i) {
        if(nums[i] > 9 && (nums[i] < 100 || (nums[i] > 999 && nums[i] < 10000) || nums[i] == 100000)) {
            ++count;
        }
    }

    return count;
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

    cout << "Result: " << findNumbers(nums) << endl;

    cout << endl;
}

int main() {
    test({12, 345, 2, 6, 7896}, 2);
    test({555, 901, 482, 1771}, 1);
    test({1, 22, 333, 4444, 55555}, 2);
    test({100, 1000, 10000, 100000}, 2);
    test({7, 88, 999, 1001, 12345}, 2);

    return 0;
}
