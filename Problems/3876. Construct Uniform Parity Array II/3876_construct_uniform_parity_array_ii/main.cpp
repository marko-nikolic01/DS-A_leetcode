#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool uniformArray(vector<int>& nums1) {
    int minimumOdd1 = INT_MAX;
    int minimumOdd2 = INT_MIN;
    bool canOdd = true;
    bool canEven = true;

    int n = nums1.size();
    for(int i = --n; i > -1; --i) {
        if((nums1[i] & 1) > 0) {
            if(nums1[i] < minimumOdd1) {
                minimumOdd2 = minimumOdd1;
                minimumOdd1 = nums1[i];
            } else if(nums1[i] < minimumOdd2) {
                minimumOdd2 = nums1[i];
            }
        }
    }

    for(n; n > -1 && (canOdd || canEven); --n) {
        if((nums1[n] & 1) < 1) {
            if(nums1[n] - minimumOdd1 < 1) {
                canOdd = false;
            }
        } else if(nums1[n] - minimumOdd2 < 0) {
            canEven = false;
        }

    }

    return canOdd || canEven;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums1, bool expected) {
    cout << "Array 1: ";
    printArray(nums1);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (uniformArray(nums1) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 4, 7}, true);
    test({2, 3}, false);
    test({4, 6}, true);
    test({1, 3, 5}, true);
    test({1}, true);
    test({2, 4, 6, 8}, true);

    return 0;
}
