#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int i = nums.size();
    int distinct = 1;
    int previous = nums[--i] + k;
    int next;

    for(--i; i > -1; --i) {
        next = max(nums[i] - k, min(nums[i] + k, previous - 1));

        if(next < previous) {
            ++distinct;
            previous = next;
        }
    }

    return distinct;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDistinctElements(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 2, 3, 3, 4}, 2, 6);
    test({4, 4, 4, 4}, 1, 3);
    test({56, 56, 54, 54}, 0, 2);
    test({6, 7, 6, 6, 7}, 1, 4);
    test({31, 31, 30, 31, 30, 29}, 2, 6);
    test({10, 10, 10, 5, 10}, 1, 4);

    return 0;
}
