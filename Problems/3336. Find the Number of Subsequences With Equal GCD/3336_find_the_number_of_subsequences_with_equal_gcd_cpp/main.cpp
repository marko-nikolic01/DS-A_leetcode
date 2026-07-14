#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int subsequencePairCount(vector<int>& nums) {
    int m = *max_element(nums.begin(), nums.end());
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));

    dp[0][0] = 1;

    for(int num : nums) {
        vector<vector<int>> ndp(m + 1, vector<int>(m + 1));

        for(int j = 0; j <= m; ++j) {
            int divisor1 = gcd(j, num);

            for(int k = 0; k <= m; ++k) {
                int val = dp[j][k];

                if(val == 0) {
                    continue;
                }

                int divisor2 = gcd(k, num);
                ndp[j][k] = (ndp[j][k] + val) % 1000000007;
                ndp[divisor1][k] = (ndp[divisor1][k] + val) % 1000000007;
                ndp[j][divisor2] = (ndp[j][divisor2] + val) % 1000000007;
            }
        }

        dp.swap(ndp);
    }

    int ans = 0;

    for(int j = 1; j <= m; ++j) {
        ans = (ans + dp[j][j]) % 1000000007;
    }

    return ans;
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

    cout << "Result: " << subsequencePairCount(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4}, 10);
    test({10, 20, 30}, 2);
    test({1, 1, 1, 1}, 50);
    test({5}, 0);
    test({7, 7}, 2);

    return 0;
}
