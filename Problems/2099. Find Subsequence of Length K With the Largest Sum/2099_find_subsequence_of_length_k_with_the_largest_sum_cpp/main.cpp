#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    unordered_map<int, int> largestNumbers;
    int iLargestNumbers = 0;

    int i = nums.size();
    while(iLargestNumbers++ < k) {
        ++largestNumbers[sorted[--i]];
    }

    iLargestNumbers = 0;
    sorted.resize(k);

    i = 0;
    while(iLargestNumbers < k) {
        if(--largestNumbers[nums[i]] > -1) {
            sorted[iLargestNumbers++] = nums[i];
        }

        ++i;
    }

    return sorted;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxSubsequence(nums, k));

    cout << endl;
}

int main() {
    test({2, 1, 3, 3}, 2, {3, 3});
    test({-1, -2, 3, 4}, 3, {-1, 3, 4});
    test({3, 4, 3, 3}, 2, {3, 4});
    test({1, 2, 3, 4, 5}, 3, {3, 4, 5});
    test({5, -1, 4, -2, 3}, 2, {5, 4});

    return 0;
}
