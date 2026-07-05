#include <iostream>
#include <vector>

using namespace std;

bool isMiddleElementUnique(vector<int>& nums) {
    bool seen = false;
    short n = nums.size();
    short middle = n >> 1;

    while(--n > -1) {
        if(nums[n] == nums[middle]) {
            if(seen) {
                return false;
            }

            seen = true;
        }
    }

    return true;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isMiddleElementUnique(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, true);
    test({1, 2, 2}, false);
    test({5}, true);
    test({4, 4, 4}, false);
    test({1, 3, 3, 3, 5}, false);

    return 0;
}
