#include <iostream>
#include <vector>

using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();

    vector<int> pivotNums(n, pivot);
    int smallerIndex = 0;
    int greaterIndex = n - 1;

    for(int i = 0; i < n; ++i) {
        if(nums[i] < pivot) {
            pivotNums[smallerIndex++] = nums[i];
        }

        if(nums[n - i - 1] > pivot) {
            pivotNums[greaterIndex--] = nums[n - i - 1];
        }
    }

    return pivotNums;
}

void test(vector<int> nums, int pivot, vector<int> expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Pivot: " << pivot << endl;

    vector<int> result = pivotArray(nums, pivot);

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : pivotArray(nums, pivot)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({9, 12, 5, 10, 14, 3, 10}, 10, {9, 5, 3, 10, 10, 12, 14});
    test({1, 2, 3, 4, 5}, 3, {1, 2, 3, 4, 5});
    test({7, 9, 2, 8, 6, 5}, 5, {2, 5, 7, 9, 8, 6});
    test({10, 10, 10}, 10, {10, 10, 10});
    test({1}, 1, {1});
    test({-3, 4, 3, 2}, 2, {-3, 2, 4, 3});
    test({1, 2, 3, 4, 5, 6, 7}, 4, {1, 2, 3, 4, 5, 6, 7});

    return 0;
}
