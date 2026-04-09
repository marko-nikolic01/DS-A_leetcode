#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int xorAfterQueries(long x, long y) {
    long power = 1;

    for(y; y > 0; y >>= 1) {
        if((y & 1) > 0) {
            power = power * x % 1000000007;
        }

        x = x * x % 1000000007;
    }

    return power;
}

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int xorSum = 0;
    int n = nums.size();
    int t = sqrt(n);
    vector<vector<vector<int>>> groups(t);
    vector<long> dif(n + t);
    int r;

    int i;
    int j;
    int m = queries.size();
    for(i = 0; i < m; ++i) {
        if(queries[i][2] < t) {
            groups[queries[i][2]].push_back({queries[i][0], queries[i][1], queries[i][3]});
        } else {
            for(queries[i][0]; queries[i][0] <= queries[i][1]; queries[i][0] += queries[i][2]) {
                nums[queries[i][0]] = (long)nums[queries[i][0]] * queries[i][3] % 1000000007;
            }
        }
    }

    for(i = 1; i < t; ++i) {
        if(groups[i].empty()) {
            continue;
        }

        fill(dif.begin(), dif.end(), 1);

        m = groups[i].size();
        for(j = 0; j < m; ++j) {
            dif[groups[i][j][0]] = dif[groups[i][j][0]] * groups[i][j][2] % 1000000007;
            r = ((groups[i][j][1] - groups[i][j][0]) / i + 1) * i + groups[i][j][0];
            dif[r] = dif[r] * xorAfterQueries(groups[i][j][2], 1000000005) % 1000000007;
        }

        for(j = i; j < n; ++j) {
            dif[j] = dif[j] * dif[j - i] % 1000000007;
        }

        for(j = 0; j < n; ++j) {
            nums[j] = (long)nums[j] * dif[j] % 1000000007;
        }
    }

    for(i = 0; i < n; ++i) {
        xorSum = xorSum ^ nums[i];
    }

    return xorSum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<vector<int>> queries, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << ", " << query[2] << ", " << query[3] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << xorAfterQueries(nums, queries) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 1}, {{0, 2, 1, 4}}, 4);
    test({2, 3, 1, 5, 4}, {{1, 4, 2, 3}, {0, 2, 1, 2}}, 31);
    test({5, 2, 3}, {{0, 2, 1, 2}}, 8);
    test({1, 2, 3, 4, 5}, {{0, 4, 2, 2}, {1, 3, 1, 3}}, 16);
    test({10, 20, 30}, {{0, 1, 1, 5}, {1, 2, 1, 2}}, 198);

    return 0;
}
