#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(++n, 0);
    vector<int> sums(n--, 0);
    deque<int> increasing;
    deque<int> decreasing;
    int range;

    dp[0]   = 1;
    sums[0] = 1;

    int l = 0;
    for(int r = 0; r < n; ++r){
        while(!increasing.empty() && nums[increasing.back()] >= nums[r]){
            increasing.pop_back();
        }

        increasing.push_back(r);

        while(!decreasing.empty() && nums[decreasing.back()] <= nums[r]){
            decreasing.pop_back();
        }

        decreasing.push_back(r);

        while(!increasing.empty() && !decreasing.empty()){
            if(nums[decreasing.front()] - nums[increasing.front()] > k){
                if(increasing.front() == l) {
                    increasing.pop_front();
                }

                if(decreasing.front() == l) {
                    decreasing.pop_front();
                }

                ++l;
            } else{
                break;
            }
        }

        range = sums[r];

        if(l > 0) {
            range -= sums[l - 1];
        }

        range %= 1000000007;

        if(range < 0) {
            range += 1000000007;
        }

        dp[r + 1] = range;
        sums[r + 1] = (sums[r] + dp[r + 1]) % 1000000007;
    }

    return dp[n];
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

    cout << "Result: " << countPartitions(nums, k) << endl;

    cout << endl;
}

int main() {
    test({9, 4, 1, 3, 7}, 4, 6);
    test({3, 3, 4}, 0, 2);
    test({15, 23}, 1, 1);
    test({5, 20}, 10, 1);
    test({7, 9}, 5, 2);

    return 0;
}
