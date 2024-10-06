#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numberGame(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for(int i = nums.size() - 1; i > 0; i -= 2) {
       int temp = nums[i];
       nums[i] = nums[i - 1];
       nums[i - 1] = temp;
    }

    return nums;
}

void test(vector<int> input, vector<int> expected) {
    cout << "Input: ";
    for (int num : input) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int num : numberGame(input)) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({5, 4, 2, 3}, {3, 2, 5, 4});
    test({1, 2, 3, 4}, {2, 1, 4, 3});
    test({10, 20, 30, 40}, {20, 10, 40, 30});
    test({7, 6, 5, 4}, {5, 4, 7, 6});
    test({8, 1, 3, 2}, {2, 1, 8, 3});

    return 0;
}
