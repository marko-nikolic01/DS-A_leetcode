#include <iostream>
#include <vector>

using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int i1 = 0;
    int i2 = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    while(i1 < n1 && i2 < n2) {
        if(nums1[i1] < nums2[i2]) {
            ++i1;
        } else if(nums1[i1] > nums2[i2]) {
            ++i2;
        } else {
            return nums1[i1];
        }
    }

    return -1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums1, vector<int> nums2, int expected) {
    cout << "Array 1: ";
    printArray(nums1);

    cout << "Array 2: ";
    printArray(nums2);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getCommon(nums1, nums2) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, {2, 4}, 2);
    test({1, 2, 3, 6}, {2, 3, 4, 5}, 2);
    test({1, 3, 5}, {2, 4, 6}, -1);
    test({1, 2, 3, 7}, {4, 5, 6, 7}, 7);
    test({5}, {5}, 5);
    test({5}, {1}, -1);

    return 0;
}
