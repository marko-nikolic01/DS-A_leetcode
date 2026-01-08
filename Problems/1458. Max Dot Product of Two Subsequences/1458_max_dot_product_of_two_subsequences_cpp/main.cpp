#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    short n2 = nums2.size();
    vector<int> products(n2, INT_MIN);
    int maxProduct;
    int previousMaxProduct;

    short j;
    short n1 = nums1.size();
    for(short i = 0; i < n1; ++i) {
        maxProduct = 0;

        for(j = 0; j < n2; ++j) {
            previousMaxProduct = maxProduct;

            if(products[j] > maxProduct) {
                maxProduct = products[j];
            }

            if(previousMaxProduct + nums1[i] * nums2[j] > products[j]) {
                products[j] = previousMaxProduct + nums1[i] * nums2[j];
            }
        }
    }

    maxProduct = products[--n2];

    while(--n2 > -1) {
        if(products[n2] > maxProduct) {
            maxProduct = products[n2];
        }
    }

    return maxProduct;
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

    cout << "Result: " << maxDotProduct(nums1, nums2) << endl;

    cout << endl;
}

int main() {
    test({2, 1, -2, 5}, {3, 0, -6}, 18);
    test({3, -2}, {2, -6, 7}, 21);
    test({-1, -1}, {1, 1}, -1);
    test({5, -4, -3}, {-2, -1}, 11);
    test({-5, -1, -2}, {-3, -4}, 23);

    return 0;
}
