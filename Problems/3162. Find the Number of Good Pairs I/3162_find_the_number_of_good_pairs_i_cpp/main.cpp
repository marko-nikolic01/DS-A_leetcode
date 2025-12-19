#include <iostream>
#include <vector>

using namespace std;

int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    short pairs = 0;

    short i;
    short n = nums1.size() - 1;
    for(short j = nums2.size() - 1; j > -1; --j) {
        nums2[j] *= k;

        for(i = n; i > -1; --i) {
            if(nums1[i] % nums2[j] < 1) {
                ++pairs;
            }
        }
    }

    return pairs;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums1, vector<int> nums2, int k, int expected) {
    cout << "Array 1: ";
    printArray(nums1);

    cout << "Array 2: ";
    printArray(nums2);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfPairs(nums1, nums2, k) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 4}, {1, 3, 4}, 1, 5);
    test({1, 2, 4, 12}, {2, 4}, 3, 2);
    test({6, 12, 18}, {1, 2, 3}, 2, 7);
    test({5, 7, 11}, {2, 3}, 4, 0);
    test({4, 8, 12}, {1}, 1, 3);

    return 0;
}
