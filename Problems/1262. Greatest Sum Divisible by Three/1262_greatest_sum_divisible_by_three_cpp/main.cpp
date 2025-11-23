#include <iostream>
#include <vector>

using namespace std;

int maxSumDivThree(vector<int>& nums) {
    vector<int> sums(3, 0);
    vector<int> nextSums(3);
    short remainder;

    short j;
    for(int i = nums.size() - 1; i > -1; --i) {
        for(j = 0; j < 3; ++j) {
            nextSums[j] = sums[j] + nums[i];
        }

        for(j = 0; j < 3; ++j) {
            remainder = nextSums[j] % 3;

            if(nextSums[j] > sums[remainder]) {
                sums[remainder] = nextSums[j];
            }
        }
    }

    return sums[0];
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

    cout << "Result: " << maxSumDivThree(nums) << endl;

    cout << endl;
}

int main() {
    test({3, 6, 5, 1, 8}, 18);
    test({4}, 0);
    test({1, 2, 3, 4, 4}, 12);
    test({2, 2, 2, 2, 2}, 6);
    test({8, 1, 7, 2, 5, 4}, 27);

    return 0;
}
