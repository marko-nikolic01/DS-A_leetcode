#include <iostream>
#include <vector>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> rearrangedArray(n--);

    int positiveIndex = n - 1;
    int negativeIndex = n;

    for(n; n > -1; --n) {
        if(nums[n] > 0) {
            rearrangedArray[positiveIndex] = nums[n];
            positiveIndex -= 2;
        } else {
            rearrangedArray[negativeIndex] = nums[n];
            negativeIndex -= 2;
        }
    }

    return rearrangedArray;
}

void runTest(vector<int> nums, vector<int> expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int num : rearrangeArray(nums)) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    runTest({3, 1, -2, -5, 2, -4}, {3, -2, 1, -5, 2, -4});
    runTest({-1, 1}, {1, -1});
    runTest({-1, -2, 1, 2}, {1, -1, 2, -2});

    return 0;
}
