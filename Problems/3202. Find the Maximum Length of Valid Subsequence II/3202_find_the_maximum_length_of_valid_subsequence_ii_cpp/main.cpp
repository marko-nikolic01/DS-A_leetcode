#include <iostream>
#include <vector>

using namespace std;

int maximumLength(vector<int>& nums, int k) {
    short length = 0;
    vector<vector<short>> lengths(k, vector<short>(k, 0));

    short j;
    short n = nums.size();
    for(short i = 0; i < n; ++i) {
        nums[i] %= k;

        for(j = 0; j < k; ++j) {
            lengths[nums[i]][j] = lengths[j][nums[i]];

            if(++lengths[nums[i]][j] > length) {
                length = lengths[nums[i]][j];
            }
        }
    }

    return length;
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

    cout << "Result: " << maximumLength(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 5}, 2, 5);
    test({1, 4, 2, 3, 1, 4}, 3, 4);
    test({5, 10, 15, 20}, 5, 4);
    test({7, 1, 3, 9, 2, 6}, 4, 4);
    test({8, 6, 7, 5, 3, 0, 9}, 10, 2);

    return 0;
}
