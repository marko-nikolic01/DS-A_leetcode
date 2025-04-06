#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    short n = nums.size();
    vector<int> subsets(n);
    vector<short> previous(n);

    short largestSubset = 0;

    short j;
    for(short i = 0; i < n; ++i) {
        previous[i] = -1;

        for(j = 0; j < i; ++j) {
            if(nums[i] % nums[j] < 1 && subsets[j] > subsets[i]) {
                subsets[i] = subsets[j];
                previous[i] = j;
            }
        }

        if(++subsets[i] > subsets[largestSubset]) {
            largestSubset = i;
        }
    }

    subsets.resize(0);
    for(largestSubset; largestSubset > -1; largestSubset = previous[largestSubset]) {
        subsets.push_back(nums[largestSubset]);
    }

    return subsets;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(largestDivisibleSubset(nums));

    cout << endl;
}

int main() {
    test({1, 2, 3}, {2, 1});
    test({1, 2, 4, 8}, {8, 4, 2, 1});
    test({3, 4, 6, 8, 12, 16, 32}, {32, 16, 8, 4});
    test({5, 10, 20, 25, 100}, {100, 20, 10, 5});
    test({1, 3, 6, 24}, {24, 6, 3, 1});

    return 0;
}
