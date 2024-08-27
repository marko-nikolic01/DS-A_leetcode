#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    int median1;
    int median2;

    int i1 = 0;
    int i2 = 0;
    for (int count = 0; count <= (n1 + n2) / 2; count++) {
        median2 = median1;

        if (i1 < n1 && (i2 >= n2 || nums1[i1] <= nums2[i2])) {
            median1 = nums1[i1++];
        } else {
            median1 = nums2[i2++];
        }
    }

    if ((n1 + n2) % 2 == 1) {
        return median1;
    }

    return (median1 + median2) / 2.0;
}

void runTestCase(vector<int> nums1, vector<int> nums2, double expected) {
    cout << "nums1: [ ";
    for(int num : nums1) cout << num << " ";
    cout << "]" << endl;

    cout << "nums2: [ ";
    for(int num : nums2) cout << num << " ";
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findMedianSortedArrays(nums1, nums2) << endl;

    cout << endl;
}

int main() {
    runTestCase({1, 3}, {2}, 2.0);
    runTestCase({1, 2}, {3, 4}, 2.5);
    runTestCase({0, 0}, {0, 0}, 0.0);
    runTestCase({}, {1}, 1.0);
    runTestCase({2}, {}, 2.0);
    runTestCase({1, 7, 17, 86}, {5, 8, 9}, 8.0);
    runTestCase({1, 7, 17, 86}, {5, 8, 100, 1000}, 12.5);

    return 0;
}
