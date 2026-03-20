#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    int subarrays = 0;
    unordered_map<int, int> count;
    bool includeK = false;
    int balance = 0;

    ++count[0];

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if (nums[i] < k) {
            --balance;
        } else if(nums[i] > k) {
            ++balance;
        } else {
            includeK = true;
        }

        if(includeK) {
            subarrays += count[balance] + count[balance - 1];
        } else {
            ++count[balance];
        }
    }

    return subarrays;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSubarrays(nums, k) << endl;

    cout << endl;
}

int main() {
    test({3, 2, 1, 4, 5}, 4, 3);
    test({2, 3, 1}, 3, 1);
    test({1}, 1, 1);
    test({1, 2, 3, 4, 5}, 1, 2);
    test({1, 2, 3, 4, 5}, 3, 5);

    return 0;
}
