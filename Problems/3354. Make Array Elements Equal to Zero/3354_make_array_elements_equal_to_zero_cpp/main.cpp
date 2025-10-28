#include <iostream>
#include <vector>

using namespace std;

int countValidSelections(vector<int>& nums) {
    short validSelections = 0;
    short sum1 = 0;
    short sum2 = 0;

    short n = nums.size();
    for(short i = --n; i > -1; --i) {
        sum1 += nums[i];
    }

    for(n; n > -1; --n) {
        if(nums[n] < 1) {
            if(sum1 == sum2) {
                validSelections += 2;
            } else if(abs(sum1 - sum2) < 2) {
                ++validSelections;
            }
        } else {
            sum1 -= nums[n];
            sum2 += nums[n];
        }
    }

    return validSelections;
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

    cout << "Result: " << countValidSelections(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 0, 2, 0, 3}, 2);
    test({2, 3, 4, 0, 4, 1, 0}, 0);
    test({16, 13, 10, 0, 0, 0, 10, 6, 7, 8, 7}, 3);
    test({0}, 2);
    test({5, 0, 5}, 2);
    return 0;
}
