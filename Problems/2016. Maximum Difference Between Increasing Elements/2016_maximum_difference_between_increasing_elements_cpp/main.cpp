#include <iostream>
#include <vector>

using namespace std;

int maximumDifference(vector<int>& nums) {
    int difference = -1;

    short n = nums.size();
    int max = nums[--n];
    int min = max;

    for(--n; n > -1; --n) {
        if(nums[n] > max) {
            max = nums[n];
            min = max;
        } else if(nums[n] < min) {
            min = nums[n];

            if(max - min > difference) {
                difference = max - min;
            }
        }
    }

    return difference;
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

    cout << "Result: " << maximumDifference(nums) << endl;

    cout << endl;
}

int main() {
    test({7, 1, 5, 4}, 4);
    test({9, 4, 3, 2}, -1);
    test({1, 5, 2, 10}, 9);
    test({87, 68, 91, 86, 58, 63, 43, 98, 6, 40}, 55);
    test({2, 3, 10, 1, 4, 8, 1, 2}, 8);

    return 0;
}
