#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void getResults(vector<int>& bt, int x, int v) {
    for (; x < bt.size(); x += x & -x) {
        bt[x] = max(bt[x], v);
    }
}

int getResults(vector<int>& bt, int x) {
    int res = 0;

    for(x; x > 0; x -= x & -x) {
        res = max(res, bt[x]);
    }

    return res;
}

vector<bool> getResults(vector<vector<int>>& queries) {
    int mx = 50000;
    set<int> st = {0, mx};
    vector<int> bt;
    vector<bool> ans;

    for(auto& q : queries) {
        if(q[0] == 1) {
            st.insert(q[1]);
        }
    }

    bt.resize(mx + 1);
    int pre = 0;

    for(int x : st) {
        if(x == 0) {
            continue;
        }

        getResults(bt, x, x - pre);
        pre = x;
    }

    reverse(queries.begin(), queries.end());

    for(auto& q : queries) {
        if(q[0] == 2) {
            int x = q[1];
            int sz = q[2];
            auto it = st.upper_bound(x);
            --it;
            int pre = *it;
            int max_space = getResults(bt, pre);
            max_space = max(max_space, x - pre);
            ans.push_back(max_space >= sz);
        } else {
            int x = q[1];
            auto it = st.find(x);
            int pre = *prev(it);
            int nxt = *next(it);
            getResults(bt, nxt, nxt - pre);
            st.erase(it);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

void printArray(vector<bool> array) {
    for(bool a : array) {
        cout << (a ? "true" : "false") << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> queries, vector<bool> expected) {
    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[";
        for(int i = 0; i < query.size(); ++i) {
            cout << query[i];
            if(i != query.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(getResults(queries));

    cout << endl;
}

int main() {
    test({{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}}, {false, true, true});
    test({{1, 7}, {2, 7, 6}, {1, 2}, {2, 7, 5}, {2, 7, 6}}, {true, true, false});
    test({{2, 1, 1}}, {true});
    test({{2, 1, 2}}, {false});
    test({{2, 3, 3}}, {true});

    return 0;
}
