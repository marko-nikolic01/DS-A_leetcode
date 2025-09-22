#include <iostream>
#include <vector>

using namespace std;

int evenNumberBitwiseORs(vector<int>& nums) {
    short evenOr = 0;

    for(short i = nums.size() - 1; i > -1; --i) {
        if((nums[i] & 1) < 1) {
            evenOr |= nums[i];
        }
    }

    return evenOr;
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

    cout << "Result: " << evenNumberBitwiseORs(nums) << endl;

    cout << endl;
}


int main() {
    test({1,2,3,4,5,6}, 6);
    test({7,9,11}, 0);
    test({1,8,16}, 24);
    test({10}, 10);
    test({2,2,2,3,5,7,8}, 10);

    return 0;
}
