#include <iostream>
#include <vector>

using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    int previous;

    int i = nums.size();
    while(--i > -1) {
        if (nums[i] > 0) {
            previous = i;
            break;
        }
    }

    while(--i > -1) {
        if (nums[i] > 0) {
            if (previous - i <= k) {
                return false;
            }

            previous = i;
        }
    }

    return true;
}

void printArray(vector<int> array) {
    for (int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (kLengthApart(nums, k) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 0, 0, 0, 1, 0, 0, 1}, 2, true);
    test({1, 0, 0, 1, 0, 1}, 2, false);
    test({0, 1, 0, 0, 1, 0, 0, 1}, 2, true);
    test({1, 0, 0, 0, 0, 0}, 5, true);
    test({0, 0, 0, 1, 0, 0, 0, 0}, 3, true);
    test({1, 1, 0, 0, 0}, 1, false);

    return 0;
}
