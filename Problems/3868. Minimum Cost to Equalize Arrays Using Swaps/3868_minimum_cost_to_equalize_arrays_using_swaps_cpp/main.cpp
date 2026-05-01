#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minCost(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> differences;

    int i = nums1.size();
    while(--i > -1) {
        ++differences[nums1[i]];
        --differences[nums2[i]];
    }

    for(unordered_map<int, int>::iterator it = differences.begin(); it != differences.end(); ++it) {
        if((it->second & 1) > 0) {
            return -1;
        }

        i += abs(it->second);
    }

    return ++i >> 2;
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

    cout << "Result: " << minCost(nums1, nums2) << endl;

    cout << endl;
}

int main() {
    test({10, 20}, {20, 10}, 0);
    test({10, 10}, {20, 20}, 1);
    test({10, 20}, {30, 40}, -1);
    test({5, 5, 5}, {5, 5, 5}, 0);
    test({1, 2, 3}, {3, 1, 2}, 0);

    return 0;
}
