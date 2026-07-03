#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
    int n = online.size();
    vector<vector<pair<int, int>>> g(n);
    vector<int> deg(n, 0);
    queue<int> q;
    int l = INT_MAX;
    int r = 0;
    int u;
    int mid;

    int i;
    for(i = edges.size() - 1; i > -1; --i) {
        if(online[edges[i][0]] && online[edges[i][1]]) {
            g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            ++deg[edges[i][1]];
            l = min(l, edges[i][2]);
            r = max(r, edges[i][2]);
        }
    }

    for(i = 1; i < n; ++i) {
        if(!deg[i]) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        u = q.front();
        q.pop();

        for(auto& [v, _] : g[u]) {
            --deg[v];

            if(v && deg[v] == 0) {
                q.push(v);
            }
        }
    }

    auto check = [&](int mid) -> bool {
        vector<long long> dp(n, LLONG_MAX >> 1);
        vector<int> cdeg = deg;
        queue<int> q;
        int u;

        dp[0] = 0;
        q.push(0);

        while(!q.empty()) {
            u = q.front();
            q.pop();

            if(u == n - 1) {
                return dp[u] <= k;
            }

            for(auto& [v, w] : g[u]) {
                if(w >= mid) {
                    dp[v] = min(dp[v], dp[u] + w);
                }
                cdeg[v]--;
                if (!cdeg[v]) {
                    q.push(v);
                }
            }
        }

        return false;
    };

    if(!check(l)) {
        return -1;
    }

    while(l <= r) {
        mid = (l + r) >> 1;

        if(check(mid)) {
            l = ++mid;
        } else {
            r = --mid;
        }
    }

    return r;
}

void printArray(vector<bool> array) {
    for(bool a : array) {
        cout << (a ? "true" : "false") << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> edges, vector<bool> online, long long k, int expected) {
    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << ", " << edge[2] << "] ";
    }
    cout << endl;

    cout << "Online: ";
    printArray(online);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findMaxPathScore(edges, online, k) << endl;

    cout << endl;
}

int main() {
    test({{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}}, {true, true, true, true}, 10, 3);
    test({{0, 1, 7}, {1, 4, 5}, {0, 2, 6}, {2, 3, 6}, {3, 4, 2}, {2, 4, 6}}, {true, true, true, false, true}, 12, 6);
    test({{0, 1, 5}}, {true, true}, 5, 5);
    test({{0, 1, 2}, {1, 2, 3}}, {true, false, true}, 100, -1);
    test({{0, 1, 4}, {1, 2, 6}, {0, 2, 1}}, {true, true, true}, 3, 1);

    return 0;
}
