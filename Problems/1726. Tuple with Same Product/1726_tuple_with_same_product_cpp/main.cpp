#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, short> products;

    int j;
    for(short i = nums.size() - 1; i > 0; --i) {
        for(j = i - 1; j > -1; --j) {
            ++products[nums[i] * nums[j]];
        }
    }

    j = 0;

    for(unordered_map<int, short>::iterator it = products.begin(); it != products.end(); ++it) {
        j += it->second * --(it->second);
    }

    return 4 * j;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << tupleSameProduct(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 3, 4, 6}, 8);
    test({1, 2, 4, 5, 10}, 16);
    test({1, 2, 3, 4, 6, 12}, 40);
    test({1, 2, 3}, 0);
    test({5, 10, 2, 4, 20}, 16);

    return 0;
}
