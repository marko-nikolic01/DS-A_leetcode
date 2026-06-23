#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxBuilding(int n, vector<vector<int>>& restrictions) {
    auto&& r = restrictions;

    r.push_back({1, 0});
    sort(r.begin(), r.end());

    if(r.back()[0] != n) {
        r.push_back({n, n - 1});
    }

    int m = r.size();
    for(int i = 1; i < m; ++i) {
        r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
    }

    for(int i = m - 2; i >= 0; --i) {
        r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
    }

    int ans = 0;
    for(int i = 0; i < m - 1; ++i) {
        int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
        ans = max(ans, best);
    }

    return ans;
}

void test(int n, vector<vector<int>> restrictions, int expected) {
    cout << "n: " << n << endl;

    cout << "Restrictions: ";
    for(vector<int> restriction : restrictions) {
        cout << "[" << restriction[0] << ", " << restriction[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxBuilding(n, restrictions) << endl;

    cout << endl;
}

int main() {
    test(5, {{2,1},{4,1}}, 2);
    test(6, {}, 5);
    test(10, {{5,3},{2,5},{7,4},{10,3}}, 5);
    test(2, {}, 1);
    test(7, {{7,0}}, 3);

    return 0;
}
