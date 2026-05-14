#include <iostream>
#include <vector>

using namespace std;

bool isGood(vector<int>& nums) {
    short n = nums.size();
    vector<bool> seen(--n, false);
    short unique = 0;

    for(short i = n--; i > -1; --i) {
        if(--nums[i] > n) {
            return false;
        } else if(!seen[nums[i]]) {
            seen[nums[i]] = true;
            ++unique;
        } else if(nums[i] < n) {
            return false;
        }
    }

    return unique > n;
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

    cout << "Result: " << (isGood(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 3, 3, 2}, true);
    test({1, 1}, true);
    test({2, 1, 3}, false);
    test({3, 4, 4, 1, 2, 1}, false);
    test({2, 2, 2}, false);
    test({2, 2}, false);

    return 0;
}
