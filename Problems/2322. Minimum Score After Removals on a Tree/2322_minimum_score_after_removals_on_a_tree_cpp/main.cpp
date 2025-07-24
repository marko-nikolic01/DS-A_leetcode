#include <iostream>
#include <vector>
#include <climits>
#include <functional>

using namespace std;

int minimumScore(int part1, int part2, int part3) {
    return max(part1, max(part2, part3)) - min(part1, min(part2, part3));
}

int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    int cnt = 0;
    vector<int> sum(n);
    vector<int> in(n);
    vector<int> out(n);
    vector<vector<int>> adj(n);

    int i;
    for(i = n - 2; i > -1; --i) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    function<void(int, int)> dfs = [&](int x, int fa) {
        in[x] = cnt++;
        sum[x] = nums[x];

        for(short i = adj[x].size() - 1; i > -1; --i) {
            if(adj[x][i] == fa) {
                continue;
            }

            dfs(adj[x][i], x);

            sum[x] ^= sum[adj[x][i]];
        }

        out[x] = cnt;
    };

    dfs(0, -1);

    int res = INT_MAX;

    for(cnt = 1; cnt < n; ++cnt) {
        for(i = cnt + 1; i < n; ++i) {
            if(in[i] > in[cnt] && in[i] < out[cnt]) {
                res = min(res, minimumScore(sum[0] ^ sum[cnt], sum[cnt] ^ sum[i], sum[i]));
            } else if(in[cnt] > in[i] && in[cnt] < out[i]) {
                res = min(res, minimumScore(sum[0] ^ sum[i], sum[i] ^ sum[cnt], sum[cnt]));
            } else {
                res = min(res, minimumScore(sum[0] ^ sum[cnt] ^ sum[i], sum[cnt], sum[i]));
            }
        }
    }

    return res;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<vector<int>> edges, int expected) {
    cout << "Values: ";
    printArray(nums);

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumScore(nums, edges) << endl;

    cout << endl;
}

int main() {
    test({1, 5, 5, 4, 11}, {{0, 1}, {1, 2}, {1, 3}, {3, 4}}, 9);
    test({5, 5, 2, 4, 4, 2}, {{0, 1}, {1, 2}, {5, 2}, {4, 3}, {1, 3}}, 0);
    test({3, 3, 3, 3, 3, 3}, {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {4, 5}}, 3);
    test({1, 2, 3, 4}, {{0, 1}, {1, 2}, {1, 3}}, 1);
    test({8, 1, 2, 3, 4}, {{0, 1}, {0, 2}, {0, 3}, {0, 4}}, 8);

    return 0;
}
