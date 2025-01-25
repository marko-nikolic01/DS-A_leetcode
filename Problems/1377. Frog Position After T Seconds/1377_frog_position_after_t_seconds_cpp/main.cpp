#include <iostream>
#include <vector>

using namespace std;

int frogPosition(vector<vector<short>>& tree, short t, int& target, short node, short parent, long choices) {
    short n = tree[node].size();
    if(node == target) {
        if(node > 0) {
            --n;
        }

        if(t < 1 || n < 1) {
            return choices;
        }
        return -1;
    }

    if(--t < 0) {
        return -2;
    }

    if(node > 0) {
        choices *= --n;
    } else {
        choices *= n--;
    }

    int result;

    for(n; n > -1; --n) {
        if(tree[node][n] != parent) {
            result = frogPosition(tree, t, target, tree[node][n], node, choices);

            if(result > -2) {
                return result;
            }
        }
    }

    return -2;
}

double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<vector<short>> tree(n);

    for(short i = edges.size() - 1; i > -1; --i) {
        tree[--edges[i][0]].push_back(--edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }

    long choices = frogPosition(tree, t, --target, 0, 0, 1);

    return choices > -1 ? 1./choices : 0;
}

void test(int n, vector<vector<int>> edges, int t, int target, double expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for (vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Time: " << t << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << frogPosition(n, edges, t, target) << endl;

    cout << endl;
}

int main() {
    test(7, {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}}, 2, 4, 0.1666666667);
    test(7, {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}}, 1, 7, 0.3333333333);
    test(4, {{1, 2}, {1, 3}, {2, 4}}, 3, 4, 0.5);
    test(4, {{1, 2}, {1, 3}, {1, 4}}, 1, 3, 0.3333333333);
    test(5, {{1, 2}, {1, 3}, {3, 4}, {3, 5}}, 4, 5, 0.25);
    test(2, {{1, 2}}, 1, 2, 1);
    test(3, {{1, 2}, {1, 3}}, 1, 3, 0.5);
    test(2, {{1, 2}}, 1, 1, 0);
    test(3, {{1, 2}, {2, 3}}, 2, 3, 1);

    return 0;
}
