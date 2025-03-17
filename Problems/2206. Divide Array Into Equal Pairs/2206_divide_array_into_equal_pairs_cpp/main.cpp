#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool divideArray(vector<int>& nums) {
    bitset<501> occurences;

    for(short i = nums.size() - 1; i > -1; --i) {
        occurences.flip(nums[i]);
    }

    return occurences.none();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (divideArray(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({3,2,3,2,2,2}, true);
    test({1,2,3,4}, false);
    test({5,5,7,7,9,9}, true);
    test({1,1,1,1,2,2,2,2}, true);
    test({1,2,2,1,3,3,4,4}, true);
    test({1,1,1,2,2,3,3,3}, false);
    test({9,9,19,10,9,12,2,12,3,3,11,5,8,4,13,6,2,11,9,19,11,15,9,17,15,12,5,14,12,16,18,16,10,3,8,9,16,20,2,4,16,12,11,14,20,16,2,18,17,20,3,13,16,17,1,1,11,20,20,4}, false);

    return 0;
}
