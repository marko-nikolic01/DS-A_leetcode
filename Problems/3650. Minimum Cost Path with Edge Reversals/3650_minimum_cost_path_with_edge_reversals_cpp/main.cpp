#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minCost(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> graph(n);

    int i;
    for(i = edges.size() - 1; i > -1; --i) {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2] << 1});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> traversal;
    vector<bool> visited(n--, false);
    int node;
    int cost;

    traversal.push({0, 0});

    while(!traversal.empty()) {
        cost = traversal.top().first;
        node = traversal.top().second;
        traversal.pop();

        if(node == n) {
            return cost;
        } else if(visited[node]) {
            continue;
        }

        visited[node] = true;

        for(i = graph[node].size() - 1; i > -1; --i) {
            if(!visited[graph[node][i].first]) {
                traversal.push({cost + graph[node][i].second, graph[node][i].first});
            }
        }
    }

    return -1;
}

void test(int n, vector<vector<int>> edges, int expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << ", " << edge[2] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minCost(n, edges) << endl;

    cout << endl;
}

int main() {
    test(4, {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}}, 5);
    test(4, {{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}}, 3);
    test(3, {{1, 0, 5}, {1, 2, 2}}, 12);
    test(5, {{0, 1, 2}, {1, 2, 2}, {3, 2, 1}, {3, 4, 1}}, 7);
    test(3, {{1, 0, 1}, {2, 1, 1}}, 4);
    test(3, {{1, 0, 1}}, -1);

    return 0;
}
