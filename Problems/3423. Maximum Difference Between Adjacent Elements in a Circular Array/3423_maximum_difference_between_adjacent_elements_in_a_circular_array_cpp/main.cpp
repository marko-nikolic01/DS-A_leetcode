#include <iostream>
#include <vector>

using namespace std;

int maxAdjacentDistance(vector<int>& nums) {
    short n = nums.size();
    short distance = abs(nums[--n] - nums[0]);

    for(--n; n > -1; --n) {
        distance = max(distance, (short)abs(nums[n + 1] - nums[n]));
    }

    return distance;
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

    cout << "Result: " << maxAdjacentDistance(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 4}, 3);
    test({-5, -10, -5}, 5);
    test({7, 7, 7, 7}, 0);
    test({100, -100}, 200);
    test({3, -1, 2, 8, -4}, 12);

    return 0;
}
