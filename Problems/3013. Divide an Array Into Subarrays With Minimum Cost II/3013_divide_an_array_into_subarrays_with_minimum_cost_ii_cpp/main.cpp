#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

void minimumCost(int idx, int val, int cnt, long bitSum[], int bitCount[], int m) {
    for(idx; idx <= m; idx += idx & -idx) {
        bitSum[idx] += val;
        bitCount[idx] += cnt;
    }
}

long long minimumCost(vector<int>& nums, int k, int dist) {
    long bitSum[100005];
    int bitCount[100005];
    int n = nums.size();
    int m = n;
    int targetK = k - 1;
    vector<int> sorted = nums;
    long minExtra = LLONG_MAX;

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    memset(bitSum, 0, sizeof(bitSum));
    memset(bitCount, 0, sizeof(bitCount));

    int maxP = m > 0 ? 1 << (31 - __builtin_clz(m)) : 0;
    int r;
    int oldV;
    int oldR;
    int idx;
    int cc;
    long cs;

    int p;
    for(int i = 1; i < n; ++i) {
        r = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
        minimumCost(r, nums[i], 1, bitSum, bitCount, m);

        if(i > dist + 1) {
            oldV = nums[i - dist - 1];
            oldR = lower_bound(sorted.begin(), sorted.end(), oldV) - sorted.begin() + 1;
            minimumCost(oldR, -oldV, -1, bitSum, bitCount, m);
        }

        if(i >= targetK) {
            idx = 0;
            cc = 0;
            cs = 0;

            for(p = maxP; p > 0; p >>= 1) {
                if(idx + p <= m && cc + bitCount[idx + p] < targetK) {
                    idx += p; cc += bitCount[idx]; cs += bitSum[idx];
                }
            }

            if(cc < targetK) {
                cs += (long)(targetK - cc) * sorted[idx];
            }

            minExtra = min(minExtra, cs);
        }
    }

    return nums[0] + minExtra;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int dist, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Distance: " << dist << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumCost(nums, k, dist) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2, 6, 4, 2}, 3, 3, 5);
    test({10, 1, 2, 2, 2, 1}, 4, 3, 15);
    test({10, 8, 18, 9}, 3, 1, 36);
    test({5, 1, 1}, 3, 1, 7);
    test({7, 2, 4, 1, 3}, 3, 2, 10);

    return 0;
}
