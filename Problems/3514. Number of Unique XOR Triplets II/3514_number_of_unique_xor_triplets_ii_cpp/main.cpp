#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int uniqueXorTriplets(vector<int>& nums) {
    unordered_set<short> xorTriplets;
    unordered_set<short> xorPairs;

    short j;
    short n = nums.size();
    for(short i = --n; i > -1; --i) {
        for(j = i; j > -1; --j) {
            xorPairs.insert(nums[i] ^ nums[j]);
        }
    }

    for(unordered_set<short>::iterator it = xorPairs.begin(); it != xorPairs.end(); ++it) {
        for(j = n; j > -1; --j) {
            xorTriplets.insert(*it ^ nums[j]);
        }
    }

    return xorTriplets.size();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Tree: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << uniqueXorTriplets(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3}, 2);
    test({6, 7, 8, 9}, 4);
    test({5}, 1);
    test({1, 2, 3}, 4);
    test({2, 2, 2, 2}, 1);

    return 0;
}
