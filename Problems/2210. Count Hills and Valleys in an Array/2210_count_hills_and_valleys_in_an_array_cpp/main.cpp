#include <iostream>
#include <vector>

using namespace std;

int countHillValley(vector<int>& nums) {
    short hillsAndValleys = 0;
    short i = nums.size();
    short previous = nums[--i];

    for(--i; i > -1; --i) {
        if(nums[i] < previous) {
            previous = nums[i];
            break;
        } else if(nums[i] > previous) {
            previous = -nums[i];
            break;
        }
    }

    for(--i; i > -1; --i) {
        if(previous < 0) {
            if(nums[i] < -previous) {
                ++hillsAndValleys;
                previous = nums[i];
            } else if(nums[i] > -previous) {
                previous = -nums[i];
            }
        } else {
            if(nums[i] > previous) {
                ++hillsAndValleys;
                previous = -nums[i];
            } else if(nums[i] < previous) {
                previous = nums[i];
            }
        }
    }

    return hillsAndValleys;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Hills and valleys: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countHillValley(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 4, 1, 1, 6, 5}, 3);
    test({6, 6, 5, 5, 4, 1}, 0);
    test({1, 3, 1, 3, 1}, 3);
    test({5, 5, 6, 5, 5}, 1);
    test({1, 2, 3, 4, 5}, 0);

    return 0;
}
