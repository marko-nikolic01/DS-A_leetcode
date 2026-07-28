#include <iostream>
#include <vector>

using namespace std;

bool predictTheWinner(vector<int>& nums) {
    short n = nums.size();
    if((n & 1) < 1) {
        return true;
    }

    vector<int> dp(n);

    short j;
    for(short i = --n; i > -1; --i) {
        dp[i] = nums[i];

        for(j = i + 1; j <= n; ++j) {
            dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
    }

    return dp[n] > -1;
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

    cout << "Result: " << (predictTheWinner(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 5, 2}, false);
    test({1, 5, 233, 7}, true);
    test({1}, true);
    test({1, 2}, true);
    test({1, 100, 1, 1, 1}, false);

    return 0;
}
