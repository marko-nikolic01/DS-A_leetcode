#include <iostream>
#include <vector>

using namespace std;

int findGCD(vector<int>& nums) {
    short minimum = nums[0];
    short maximum = minimum;

    short i = nums.size();
    while(--i > 0) {
        if(nums[i] < minimum) {
            minimum = nums[i];
        } else if(nums[i] > maximum) {
            maximum = nums[i];
        }
    }

    while(minimum > 0) {
        i = minimum;
        minimum = maximum % minimum;
        maximum = i;
    }

    return maximum;
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

    cout << "Result: " << findGCD(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 5, 6, 9, 10}, 2);
    test({7, 5, 6, 8, 3}, 1);
    test({3, 3}, 3);
    test({1, 1000}, 1);
    test({1000, 1000}, 1000);

    return 0;
}
