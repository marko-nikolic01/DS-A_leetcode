#include <iostream>
#include <vector>

using namespace std;

int countPairs(vector<int>& nums, int k) {
    short pairs = 0;

    short j;
    for(short i = nums.size() - 1; i > 0; --i) {
        for(j = i - 1; j > -1; --j) {
            if(nums[i] == nums[j] && (i * j) % k < 1) {
                ++pairs;
            }
        }
    }

    return pairs;
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

    cout << "Result: " << countPairs(nums, k) << endl;

    cout << endl;
}

int main() {
    test({3,1,2,2,2,1,3}, 2, 4);
    test({1,2,3,4}, 1, 0);
    test({1,1,1,1}, 2, 5);
    test({2,4,6,8,10}, 3, 0);
    test({5,5,5,5,5}, 5, 4);

    return 0;
}
