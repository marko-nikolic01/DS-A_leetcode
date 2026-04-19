#include <iostream>
#include <vector>

using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int distance = 0;

    int i1 = 0;
    int i2 = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    while(i1 < n1 && i2 < n2) {
        if(nums1[i1] > nums2[i2]) {
            ++i1;

            continue;
        } else if(i2 - i1 > distance) {
            distance = i2 - i1;
        }

        ++i2;
    }

    return distance;
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

    cout << "Result: " << maxDistance(nums1, nums2) << endl;

    cout << endl;
}

int main() {
    test({55, 30, 5, 4, 2}, {100, 20, 10, 10, 5}, 2);
    test({2, 2, 2}, {10, 10, 1}, 1);
    test({30, 29, 19, 5}, {25, 25, 25, 25, 25}, 2);
    test({10, 8, 6}, {5, 4, 3}, 0);
    test({3, 2, 1}, {3, 3, 3, 3, 3}, 4);

    return 0;
}
