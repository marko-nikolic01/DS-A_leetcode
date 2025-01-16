#include <iostream>
#include <vector>

using namespace std;

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    int xorSum = 0;

    if((n2 & 1) > 0) {
        for(int i = 0; i < n1; ++i) {
            xorSum ^= nums1[i];
        }
    }

    if((n1 & 1) > 0) {
        for(--n2; n2 > -1; --n2) {
            xorSum ^= nums2[n2];
        }
    }

    return xorSum;
}

void runTest(vector<int> nums1, vector<int> nums2, int expected) {
    cout << "Numbers 1: ";
    for(int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Numbers 2: ";
    for(int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << xorAllNums(nums1, nums2) << endl;

    cout << endl;
}

int main() {
    runTest({2, 1, 3}, {10, 2, 5, 0}, 13);
    runTest({1, 2}, {3, 4}, 0);
    runTest({0}, {0}, 0);
    runTest({1}, {2, 3, 4}, 4);
    runTest({4, 5, 6}, {7, 8}, 15);
    runTest({9, 10, 11}, {12}, 4);
    runTest({1, 1, 1}, {2, 2, 2}, 3);

    return 0;
}
