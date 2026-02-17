#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateElements(vector<int>& nums, int k) {
    vector<pair<int, int>> nonNegative;

    int i;
    int n = nums.size();
    for(i = 0; i < n; ++i) {
        if(nums[i] > -1) {
            nonNegative.push_back({nums[i], i});
        }
    }

    n = nonNegative.size();
    if(n > 0) {
        int j;
        k %= n;
        for(i = 0; i < n; ++i) {
            j = (n + i - k) % n;
            nums[nonNegative[j].second] = nonNegative[i].first;
        }
    }

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(rotateElements(nums, k));

    cout << endl;
}

int main() {
    test({1, -2, 3, -4}, 3, {3, -2, 1, -4});
    test({-3, -2, 7}, 1, {-3, -2, 7});
    test({5, 4, -9, 6}, 2, {6, 5, -9, 4});
    test({-6, -2}, 18866, {-6, -2});
    test({1}, 1, {1});

    return 0;
}
