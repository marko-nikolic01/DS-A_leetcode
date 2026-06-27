#include <iostream>
#include <vector>

using namespace std;

long long countMajoritySubarrays(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> pre((n << 1) + 1, 0);
    int cnt = n;
    long ans = 0;
    long presum = 0;

    pre[n] = 1;

    for(int i = 0; i < n; ++i) {
        if(nums[i] == target) {
            presum += pre[cnt];
            ++cnt;
            ++pre[cnt];
        } else {
            --cnt;
            presum -= pre[cnt];
            ++pre[cnt];
        }

        ans += presum;
    }

    return ans;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int target, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countMajoritySubarrays(nums, target) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 2, 3}, 2, 5);
    test({1, 1, 1, 1}, 1, 10);
    test({1, 2, 3}, 4, 0);
    test({2}, 2, 1);
    test({1, 2, 1, 2, 2}, 2, 8);

    return 0;
}
