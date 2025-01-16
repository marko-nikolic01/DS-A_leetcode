#include <iostream>
#include <vector>

using namespace std;

void maximalPathQuality(vector<int>& values, short time, vector<vector<int>>& graph, int node, vector<bool>& visited, int currentQuality, int& quality) {
    bool visitedTemp = visited[node];
    visited[node] = true;

    if(!visitedTemp) {
        currentQuality += values[node];
    }

    if(node == 0 && currentQuality > quality) {
        quality = currentQuality;
    }

    for(short i = graph[node].size() - 2; i > -1; i -= 2) {
        if(graph[node][i] <= time) {
            maximalPathQuality(values, time - graph[node][i], graph, graph[node][i + 1], visited, currentQuality, quality);
        }
    }

    visited[node] = visitedTemp;
}

int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
    int n = values.size();
    vector<vector<int>> graph(n);

    for(short i = edges.size() - 1; i > -1; --i) {
        graph[edges[i][0]].push_back(edges[i][2]);
        graph[edges[i][0]].push_back(edges[i][1]);

        graph[edges[i][1]].push_back(edges[i][2]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n, false);

    n = 0;
    maximalPathQuality(values, maxTime, graph, 0, visited, 0, n);

    return n;
}

void test(vector<int> values, vector<vector<int>> edges, int maxTime, int expected) {
    cout << "Values: ";
    for(int value : values) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << " " << edge[2] << "] ";
    }
    cout << endl;

    cout << "Maximum time: " << maxTime << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximalPathQuality(values, edges, maxTime) << endl;

    cout << endl;
}

int main() {
    test({0, 32, 10, 43}, {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}}, 49, 75);
    test({5, 10, 15, 20}, {{0, 1, 10}, {1, 2, 10}, {0, 3, 10}}, 30, 25);
    test({1, 2, 3, 4}, {{0, 1, 10}, {1, 2, 11}, {2, 3, 12}, {1, 3, 13}}, 50, 7);
    test({10, 20, 30, 40}, {{0, 1, 15}, {1, 2, 20}, {2, 3, 25}, {3, 0, 15}}, 75, 100);
    test({5, 8, 13, 21}, {{0, 1, 10}, {1, 2, 10}, {0, 3, 20}, {2, 3, 15}}, 35, 13);

    return 0;
}
