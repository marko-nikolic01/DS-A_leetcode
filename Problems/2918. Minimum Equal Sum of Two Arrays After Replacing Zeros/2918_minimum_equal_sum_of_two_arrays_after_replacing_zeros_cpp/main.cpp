#include <iostream>
#include <vector>

using namespace std;

long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long sum1 = 0;
    long sum2 = 0;

    bool hasZeros1 = false;
    bool hasZeros2 = false;

    int i;
    for(i = nums1.size() - 1; i > -1; --i) {
        if(nums1[i] < 1) {
            ++sum1;
            hasZeros1 = true;
        } else {
            sum1 += nums1[i];
        }
    }

    for(i = nums2.size() - 1; i > -1; --i) {
        if(nums2[i] < 1) {
            ++sum2;
            hasZeros2 = true;
        } else {
            sum2 += nums2[i];
        }
    }

    return sum1 < sum2 ? (hasZeros1 ? sum2 : -1) : (sum1 > sum2 ? (hasZeros2 ? sum1 : -1) : sum1);
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums1, vector<int> nums2, long long expected) {
    cout << "Array 1: ";
    printArray(nums1);

    cout << "Array 2: ";
    printArray(nums2);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minSum(nums1, nums2) << endl;

    cout << endl;
}

int main() {
    test({3,2,0,1,0}, {6,5,0}, 12);
    test({2,0,2,0}, {1,4}, -1);
    test({0,0,0}, {3,3,3}, 9);
    test({1,2,3}, {2,2,2}, 6);
    test({0,0}, {1,1,1,1}, 4);

    return 0;
}
