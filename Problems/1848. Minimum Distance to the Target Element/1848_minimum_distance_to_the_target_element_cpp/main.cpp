#include <iostream>
#include <vector>

using namespace std;

int getMinDistance(vector<int>& nums, int target, int start) {
    short distance = nums.size();

    for(short i = --distance; i > -1; --i) {
        if(nums[i] == target && abs(i - start) < distance) {
            distance = abs(i - start);
        }
    }

    return distance;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int target, int start, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Target: " << target << endl;

    cout << "Start: " << start << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getMinDistance(nums, target, start) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 5}, 5, 3, 1);
    test({1}, 1, 0, 0);
    test({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 1, 0, 0);
    test({7, 2, 3, 4, 5}, 7, 4, 4);
    test({1, 3, 5, 3, 1}, 3, 2, 1);

    return 0;
}
