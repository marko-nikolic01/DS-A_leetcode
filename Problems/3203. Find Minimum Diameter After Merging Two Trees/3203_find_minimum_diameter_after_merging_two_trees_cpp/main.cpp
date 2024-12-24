#include <iostream>
#include <vector>

using namespace std;

int minimumDiameterAfterMerge(vector<vector<int>>& tree, int node, int parent, int& diameter) {
    int subdiameter1 = 0;
    int subdiameter2 = 0;

    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i] != parent) {
            int depth = minimumDiameterAfterMerge(tree, tree[node][i], node, diameter);

            if(depth > subdiameter1) {
                subdiameter2 = subdiameter1;
                subdiameter1 = depth;
            } else if(depth > subdiameter2) {
                subdiameter2 = depth;
            }
        }
    }

    if(subdiameter1 + subdiameter2 > diameter) {
        diameter = subdiameter1 + subdiameter2;
    }

    return ++subdiameter1;
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int n = edges1.size();
    vector<vector<int>> tree(n + 1);
    for(int i = n - 1; i > -1; --i) {
        tree[edges1[i][0]].push_back({edges1[i][1]});
        tree[edges1[i][1]].push_back({edges1[i][0]});
    }

    int diameter1 = 0;
    minimumDiameterAfterMerge(tree, 0, 0, diameter1);

    n = edges2.size();
    tree.assign(n + 1, vector<int>());
    for(int i = n - 1; i > -1; --i) {
        tree[edges2[i][0]].push_back({edges2[i][1]});
        tree[edges2[i][1]].push_back({edges2[i][0]});
    }

    int diameter2 = 0;
    minimumDiameterAfterMerge(tree, 0, 0, diameter2);

    n = (diameter1 + 1) / 2 + (diameter2 + 1) / 2;

    if(++n > diameter1 && n > diameter2) {
        return n;
    }
    return diameter1 > diameter2 ? diameter1 : diameter2;
}

void test(vector<vector<int>> edges1, vector<vector<int>> edges2, int expected) {
    cout << "Tree 1: ";
    for (vector<int> edge : edges1) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Tree 2: ";
    for (vector<int> edge : edges2) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumDiameterAfterMerge(edges1, edges2) << endl;

    cout << endl;
}

int main() {
    test({{0, 1}, {0, 2}, {0, 3}}, {{0, 1}}, 3);
    test({{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}}, {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}}, 5);
    test({}, {}, 1);
    test({{0, 1}, {1, 2}}, {{0, 1}, {1, 2}, {1, 3}}, 3);
    test({{0, 1}}, {{0, 1}, {1, 2}}, 3);
    test({{0, 1}, {0, 2}, {0, 3}}, {}, 2);
    test({}, {{0, 1}, {0, 2}, {0, 3}}, 2);

    return 0;
}
