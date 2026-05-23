#include <iostream>
#include <vector>

using namespace std;

int minimumSwaps(vector<int>& nums) {
    short swaps = 0;

    short n = nums.size() - 1;
    for(short i = 0; i < n; ++i) {
        if(nums[i] < 1) {
            while(n > -1 && nums[n] < 1) {
                --n;
            }

            if(i < n--) {
                ++swaps;
            }
        }
    }

    return swaps;
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

    cout << "Result: " << minimumSwaps(nums) << endl;

    cout << endl;
}

int main() {
    test({0, 1, 0, 3, 12}, 2);
    test({0, 1, 0, 2}, 1);
    test({1, 2, 0}, 0);
    test({0, 0}, 0);
    test({1, 2, 3, 0, 0}, 0);
    test({1, 2, 0, 3, 4}, 1);
    test({0, 0, 0, 0}, 0);
    test({0}, 0);

    return 0;
}
