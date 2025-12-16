#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
    vector<vector<int>> g(n);

    for(auto& e : hierarchy) {
        g[e[0] - 1].push_back(e[1] - 1);
    }

    auto dfs = [&](auto&& self, int u) -> tuple<vector<int>, vector<int>, int> {
        int cost = present[u];
        int dCost = present[u] / 2;

        auto dp0 = vector(budget + 1, 0);
        auto dp1 = vector(budget + 1, 0);

        auto subProfit0 = vector(budget + 1, 0);
        auto subProfit1 = vector(budget + 1, 0);

        int uSize = cost;

        for(auto v : g[u]) {
            auto [subDp0, subDp1, vSize] = self(self, v);
            uSize += vSize;

            for(int i = budget; i >= 0; --i) {
                for (int sub = 0; sub <= min(vSize, i); sub++) {
                    subProfit0[i] = max(subProfit0[i], subProfit0[i - sub] + subDp0[sub]);
                    subProfit1[i] = max(subProfit1[i], subProfit1[i - sub] + subDp1[sub]);
                }
            }
        }

        for(int i = 0; i <= budget; ++i) {
            dp0[i] = dp1[i] = subProfit0[i];

            if(i >= dCost) {
                dp1[i] = max(subProfit0[i], subProfit1[i - dCost] + future[u] - dCost);
            }

            if(i >= cost) {
                dp0[i] = max(subProfit0[i], subProfit1[i - cost] + future[u] - cost);
            }
        }

        return {dp0, dp1, uSize};
    };

    return std::get<0>(dfs(dfs, 0))[budget];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<int> present, vector<int> future, vector<vector<int>> hierarchy, int budget, int expected) {
    cout << "n: " << n << endl;

    cout << "Present: ";
    printArray(present);

    cout << "Future: ";
    printArray(future);

    cout << "Hierarchy: ";
    for(vector<int> h : hierarchy) {
        cout << "[" << h[0] << ", " << h[1] << "] ";
    }
    cout << endl;

    cout << "Budget: " << budget << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxProfit(n, present, future, hierarchy, budget) << endl;

    cout << endl;
}

int main() {
    test(2, {1, 2}, {4, 3}, {{1, 2}}, 3, 5);
    test(2, {3, 4}, {5, 8}, {{1, 2}}, 4, 4);
    test(3, {4, 6, 8}, {7, 9, 11}, {{1, 2}, {1, 3}}, 10, 10);
    test(3, {5, 2, 3}, {8, 5, 6}, {{1, 2}, {2, 3}}, 7, 12);
    test(1, {5}, {10}, {}, 5, 5);

    return 0;
}
