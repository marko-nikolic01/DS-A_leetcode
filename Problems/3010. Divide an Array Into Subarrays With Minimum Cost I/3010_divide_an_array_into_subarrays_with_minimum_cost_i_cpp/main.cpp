#include <iostream>
#include <vector>

using namespace std;

int minimumCost(vector<int>& nums) {
    short minimum1 = 50;
    short minimum2 = 50;

    for(short i = nums.size() - 1; i > 0; --i) {
        if(nums[i] < minimum1) {
            minimum2 = minimum1;
            minimum1 = nums[i];
        } else if(nums[i] < minimum2) {
            minimum2 = nums[i];
        }
    }

    return nums[0] + minimum1 + minimum2;
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

    cout << "Result: " << minimumCost(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 12}, 6);
    test({5, 4, 3}, 12);
    test({10, 3, 1, 1}, 12);
    test({7, 6, 5, 4, 3}, 14);
    test({2, 1, 2, 1, 2}, 4);

    return 0;
}
