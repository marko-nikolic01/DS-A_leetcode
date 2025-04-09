#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int minOperations(vector<int>& nums, int k) {
    bitset<101> occurences;

    for(short i = nums.size() - 1; i > -1; --i) {
        if(nums[i] < k) {
            return -1;
        } else if(nums[i] > k) {
            occurences.set(nums[i]);
        }
    }

    return occurences.count();
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

    cout << "Result: " << minOperations(nums, k) << endl;

    cout << endl;
}

int main() {
    test({5, 2, 5, 4, 5}, 2, 2);
    test({2, 1, 2}, 2, -1);
    test({9, 7, 5, 3}, 1, 4);
    test({10, 10, 10}, 10, 0);
    test({10, 10, 5, 5}, 5, 1);
    test({3, 3, 3, 2, 2, 2, 1}, 2, -1);

    return 0;
}
