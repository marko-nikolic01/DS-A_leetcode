#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long maxTotalValue(vector<int>& nums, int k) {
    long totalValue = 0;
    int n = nums.size();
    int logn = 32 - __builtin_clz(n);
    vector<vector<int>> stMax(n, vector<int>(logn));
    vector<vector<int>> stMin(n, vector<int>(logn));
    priority_queue<tuple<int, int, int>> pq;

    for(int i = 0; i < n; i++) {
        stMax[i][0] = stMin[i][0] = nums[i];
    }

    for(int j = 1; j < logn; j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
        }
    }

    auto queryMax = [&](int l, int r) {
        int j = 31 - __builtin_clz(r - l + 1);

        return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
    };

    auto queryMin = [&](int l, int r) {
        int j = 31 - __builtin_clz(r - l + 1);

        return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
    };

    for(int l = 0; l < n; l++) {
        pq.emplace(queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1);
    }

    while(k-- > 0) {
        auto [value, l, r] = pq.top();
        pq.pop();
        totalValue += value;

        if(r > l) {
            pq.emplace(queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1);
        }
    }

    return totalValue;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxTotalValue(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2}, 2, 4);
    test({4, 2, 5, 1}, 3, 12);
    test({3, 3, 3, 3}, 4, 0);
    test({1, 1}, 2, 0);
    test({3}, 1, 0);

    return 0;
}
