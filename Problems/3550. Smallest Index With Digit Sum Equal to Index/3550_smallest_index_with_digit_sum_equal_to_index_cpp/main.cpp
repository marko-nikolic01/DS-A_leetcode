#include <iostream>
#include <vector>

using namespace std;

int smallestIndex(vector<int>& nums) {
    short sum;

    short n = nums.size();
    for(short i = 0; i < n; ++i) {
        sum = 0;

        while(nums[i] > 0) {
            sum += nums[i] % 10;
            nums[i] /= 10;
        }

        if(sum == i) {
            return i;
        }
    }

    return -1;
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

    cout << "Result: " << smallestIndex(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2}, 2);
    test({1, 10, 11}, 1);
    test({1, 2, 3}, -1);
    test({0, 1, 2, 3}, 0);
    test({9, 18, 27, 36, 45}, -1);

    return 0;
}
