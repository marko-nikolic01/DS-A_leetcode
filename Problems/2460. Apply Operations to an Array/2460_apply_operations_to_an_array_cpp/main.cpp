#include <iostream>
#include <vector>

using namespace std;

vector<int> applyOperations(vector<int>& nums) {
    short previous = nums[0];
    short index = nums[0] < 1 ? 0 : 1;

    short n = nums.size();
    for(short i = 1; i < n; ++i) {
        if(nums[i] < 1) {
            previous = 0;
            continue;
        } else if(nums[i] == previous) {
            nums[index - 1] = previous << 1;
            previous = 0;
            nums[i] = 0;
        } else {
            previous = nums[i];
            nums[i] = 0;
            nums[index++] = previous;
        }
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
    printArray(applyOperations(nums));

    cout << endl;
}

int main()
{
    test({1, 2, 2, 1, 1, 0}, {1, 4, 2, 0, 0, 0});
    test({0, 1}, {1, 0});
    test({847, 847, 0, 0, 0, 399, 416, 416, 879, 879, 206, 206, 206, 272}, {1694, 399, 832, 1758, 412, 206, 272, 0, 0, 0, 0, 0, 0, 0});
    test({2, 2, 4}, {4, 4, 0});
    test({4, 4, 8, 8, 16}, {8, 16, 16, 0, 0});
    test({1, 1, 1, 1, 2, 2, 3, 3, 0}, {2, 2, 4, 6, 0, 0, 0, 0, 0});
    test({0, 0, 0, 0, 5, 5, 10, 10, 20, 20}, {10, 20, 40, 0, 0, 0, 0, 0, 0, 0});
    test({0, 0, 0}, {0, 0, 0});
    test({1000, 1000, 1000, 1000, 1000}, {2000, 2000, 1000, 0, 0});

    return 0;
}
