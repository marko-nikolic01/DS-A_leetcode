#include <iostream>
#include <vector>

using namespace std;

vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    vector<vector<vector<int>>> graph(n);

    int i;
    for(i = edges.size() - 1; i > -1; --i) {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    vector<int> traversal;
    int node;

    vector<int> groups(n, -1);
    int group = 0;

    vector<int> costs;

    for(--n; n > -1; --n) {
        if(groups[n] < 0) {
            traversal.push_back(n);
            groups[n] = group;
            costs.push_back(2147483647);

            while(!traversal.empty()) {
                node = traversal.back();
                traversal.pop_back();

                for(i = graph[node].size() - 1; i > -1; --i) {
                    if(groups[graph[node][i][0]] < 0) {
                        traversal.push_back(graph[node][i][0]);
                        groups[graph[node][i][0]] = group;
                    }

                    costs[group] &= graph[node][i][1];
                }
            }

            ++group;
        }
    }

    n = query.size();
    vector<int> minimumCosts(n);

    for(--n; n > -1; --n) {
        minimumCosts[n] = groups[query[n][0]] == groups[query[n][1]] ? costs[groups[query[n][0]]] : -1;
    }

    return minimumCosts;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> edges, vector<vector<int>> query, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << ", " << edge[2] << "] ";
    }
    cout << endl;

    cout << "Queries: ";
    for(vector<int> q : query) {
        cout << "[" << q[0] << ", " << q[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(minimumCost(n, edges, query));

    cout << endl;
}

int main() {
    test(5, {{0,1,7}, {1,3,7}, {1,2,1}}, {{0,3}, {3,4}}, {1, -1});
    test(4, {{0,1,4}, {1,2,2}, {2,3,8}, {0,3,16}}, {{0,2}, {1,3}, {0,3}}, {0, 0, 0});
    test(6, {{0,1,10}, {2,3,5}, {4,5,3}}, {{0,1}, {2,3}, {4,5}, {0,2}, {1,5}}, {10, 5, 3, -1, -1});
    test(3, {{0,2,7}, {0,1,15}, {1,2,6}, {1,2,1}}, {{1,2}}, {0});
    test(3, {{0,1,5}, {1,2,8}}, {{0,1}, {1,2}, {0,2}}, {0, 0, 0});

    return 0;
}
