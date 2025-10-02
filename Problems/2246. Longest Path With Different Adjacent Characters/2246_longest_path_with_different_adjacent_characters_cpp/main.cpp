#include <iostream>
#include <vector>

using namespace std;

int longestPath(vector<vector<int>>& tree, vector<int>& parent, string& s, int& path, int node) {
    int subpath;
    int subpath1 = 0;
    int subpath2 = 0;

    for(int i = tree[node].size() - 1; i > -1; --i) {
        subpath = longestPath(tree, parent, s, path, tree[node][i]);

        if(subpath > subpath1) {
            subpath2 = subpath1;
            subpath1 = subpath;
        } else if(subpath > subpath2) {
            subpath2 = subpath;
        }
    }

    if(++subpath1 + subpath2 > path) {
        path = subpath1 + subpath2;
    }

    return s[node] == s[parent[node]] ? 0 : subpath1;
}

int longestPath(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>> tree(n);

    for(--n; n > 0; --n) {
        tree[parent[n]].push_back(n);
    }

    n = 1;
    parent[0] = 0;
    longestPath(tree, parent, s, n, 0);

    return n;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> parent, string s, int expected) {
    cout << "Parents: ";
    printArray(parent);

    cout << "Nodes: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestPath(parent, s) << endl;

    cout << endl;
}

int main() {
    test({-1, 0, 0, 1, 1, 2}, "abacbe", 3);
    test({-1, 0, 0, 0}, "aabc", 3);
    test({-1, 0, 0, 1, 1}, "aaaaa", 1);
    test({-1, 0, 1, 2, 3}, "abcde", 5);
    test({-1, 0, 0, 0, 0}, "abcde", 3);

    return 0;
}
