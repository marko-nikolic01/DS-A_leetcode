#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

int minOperations(string s, int k) {
    int n = s.size();
    int m = 0;
    vector<int> dist(n + 1, INT_MAX);
    vector<set<int>> nodeSets(2);

    int i;
    for(i = 0; i <= n; ++i) {
        nodeSets[i % 2].insert(i);

        if(i < n && s[i] == '0') {
            ++m;
        }
    }

    queue<int> q;
    int c1;
    int c2;
    int lnode;
    int rnode;
    int m2;

    q.push(m);
    dist[m] = 0;
    nodeSets[m & 1].erase(m);


    set<int>::iterator it;
    while(!q.empty()) {
        m = q.front();
        q.pop();
        c1 = max(k - n + m, 0);
        c2 = min(m, k);
        lnode = m + k - 2 * c2;
        rnode = m + k - 2 * c1;
        i = lnode & 1;

        it = nodeSets[i].lower_bound(lnode);
        while(it != nodeSets[i].end() && *it <= rnode) {
            m2 = *it;
            dist[m2] = dist[m] + 1;
            q.push(m2);
            it = next(it);
            nodeSets[i].erase(m2);
        }
    }

    return dist[0] == INT_MAX ? -1 : dist[0];
}

void test(string s, int k, int expected) {
    cout << "s: " << s << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minOperations(s, k) << endl;

    cout << endl;
}

int main() {
    test("110", 1, 1);
    test("0101", 3, 2);
    test("101", 2, -1);
    test("00000", 2, -1);
    test("111111", 5, 0);

    return 0;
}
