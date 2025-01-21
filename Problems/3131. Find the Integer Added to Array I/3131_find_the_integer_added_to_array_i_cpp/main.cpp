#include <iostream>
#include <vector>

using namespace std;

int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    for(short i = nums1.size() - 1; i > 0; --i) {
        if(nums1[i] < nums1[0]) {
            nums1[0] = nums1[i];
        }

        if(nums2[i] < nums2[0]) {
            nums2[0] = nums2[i];
        }
    }

    return nums2[0] - nums1[0];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums1, vector<int> nums2, int expected) {
    cout << "Numbers 1: ";
    printArray(nums1);

    cout << "Numbers 2: ";
    printArray(nums2);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << addedInteger(nums1, nums2) << endl;

    cout << endl;
}

int main() {
    test({2, 6, 4}, {9, 7, 5}, 3);
    test({10}, {5}, -5);
    test({1, 1, 1, 1}, {1, 1, 1, 1}, 0);
    test({0, 2, 4}, {5, 7, 9}, 5);
    test({-5, 0, 10}, {5, 10, 20}, 10);
    test({100, 200, 300}, {400, 500, 600}, 300);
    test({0, 0, 0}, {1, 1, 1}, 1);

    return 0;
}
