#include <iostream>
#include <vector>

using namespace std;

long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int pos1 = 0;
    int pos2 = 0;

    while(pos1 < n1 && nums1[pos1] < 0) {
        pos1++;
    }

    while(pos2 < n2 && nums2[pos2] < 0) {
        pos2++;
    }

    long left = -10000000000;
    long right = 10000000000;
    long mid;
    long count;

    int i1;
    int i2;
    while(left <= right) {
        mid = (left + right) / 2;
        count = 0;

        for(i1 = 0, i2 = pos2 - 1; i1 < pos1 && i2 >= 0;) {
            if(static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                i1++;
            } else {
                count += pos1 - i1;
                i2--;
            }
        }

        for(i1 = pos1, i2 = n2 - 1; i1 < n1 && i2 >= pos2;) {
            if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                i2--;
            } else {
                count += i2 - pos2 + 1;
                i1++;
            }
        }

        for(i1 = 0, i2 = pos2; i1 < pos1 && i2 < n2;) {
            if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                i2++;
            } else {
                count += n2 - i2;
                i1++;
            }
        }

        for(i1 = pos1, i2 = 0; i1 < n1 && i2 < pos2;) {
            if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                i1++;
            } else {
                count += n1 - i1;
                i2++;
            }
        }

        if(count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums1, vector<int> nums2, long long k, long long expected) {
    cout << "Array 1: ";
    printArray(nums1);

    cout << "Array 2: ";
    printArray(nums2);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << kthSmallestProduct(nums1, nums2, k) << endl;

    cout << endl;
}

int main() {
    test({2, 5}, {3, 4}, 2, 8);
    test({-4, -2, 0, 3}, {2, 4}, 6, 0);
    test({-2, -1, 0, 1, 2}, {-3, -1, 2, 4, 5}, 3, -6);
    test({1, 2, 3, 4}, {1, 2, 3, 4}, 5, 3);
    test({-5, -3, -1}, {-2, 0, 2}, 4, 0);

    return 0;
}
