#include <iostream>
#include <vector>

using namespace std;

bool uniformArray(vector<int>& nums1) {
    return true;
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
    test({2, 3}, true);
    test({4, 6}, true);
    test({1, 3, 5}, true);
    test({1}, true);
    test({2, 4, 6, 8}, true);

    return 0;
}
