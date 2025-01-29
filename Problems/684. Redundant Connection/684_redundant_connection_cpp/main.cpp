#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    short n = edges.size();

    vector<vector<short>> graph(n);
    vector<bool> visited(n, false);
    unordered_set<int> canEdgeBeDeleted;

    short i = --n;
    for(i; i > -1; --i) {
        graph[--edges[i][0]].push_back(--edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<short> traversal;
    vector<short> traversalIndexes;
    vector<short> parents;

    visited[0] = true;
    traversal.push_back(0);
    traversalIndexes.push_back(-1);
    parents.push_back(-1);

    short node;

    while(true) {
        node = traversal.back();
        i = ++traversalIndexes.back();

        if(i < graph[node].size() && graph[node][i] == parents.back()) {
            i = ++traversalIndexes.back();
        }

        if(i < graph[node].size()) {
            if(!visited[graph[node][i]]) {
                visited[graph[node][i]] = true;
                traversal.push_back(graph[node][i]);
                traversalIndexes.push_back(-1);
                parents.push_back(node);
            } else {
                i = graph[node][i];

                if(node < i) {
                    canEdgeBeDeleted.insert(1000 * node + i);
                } else {
                    canEdgeBeDeleted.insert(1000 * i + node);
                }

                short previousNode = node;
                traversal.pop_back();

                while(true) {
                    node = traversal.back();

                    if(node < previousNode) {
                        canEdgeBeDeleted.insert(1000 * node + previousNode);
                    } else {
                        canEdgeBeDeleted.insert(1000 * previousNode + node);
                    }

                    if(node == i) {
                        break;
                    }

                    previousNode = node;
                    traversal.pop_back();
                }

                for(n; n > -1; --n) {
                    if(canEdgeBeDeleted.find(1000 * edges[n][0] + edges[n][1]) != canEdgeBeDeleted.end()) {
                        ++edges[n][0];
                        ++edges[n][1];
                        return edges[n];
                    }
                }
            }
        } else {
            traversal.pop_back();
            traversalIndexes.pop_back();
            parents.pop_back();
        }
    }

    return {};
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> edges, vector<int> expected) {
    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findRedundantConnection(edges));

    cout << endl;
}

int main() {
    test({{1, 2}, {1, 3}, {2, 3}}, {2, 3});
    test({{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}}, {1, 4});
    test({{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}}, {3, 4});
    test({{1, 2}, {2, 3}, {3, 4}, {4, 5}, {2, 5}}, {2, 5});
    test({{1, 2}, {1, 3}, {2, 4}, {3, 5}, {2, 5}}, {2, 5});
    test({{1, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {2, 5}}, {2, 5});
    test({{1, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {1, 5}}, {1, 5});

    return 0;
}
