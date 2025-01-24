#include <iostream>
#include <vector>

using namespace std;

void eventualSafeNodes(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& isSafe, short& safeNodes, short node) {
    visited[node] = true;
    isSafe[node] = false;

    bool areDescendantsSafe = true;

    for(short i = graph[node].size() - 1; i > -1; --i) {
        if(!visited[graph[node][i]]) {
            eventualSafeNodes(graph, visited, isSafe, safeNodes, graph[node][i]);
        }

        areDescendantsSafe &= isSafe[graph[node][i]];
    }

    if(areDescendantsSafe) {
        isSafe[node] = true;
    } else {
        --safeNodes;
    }
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    short n = graph.size();

    vector<bool> isSafe(n);
    vector<bool> visited(n, false);

    short safeNodes = n;
    for(short i = 0; i < n; ++i) {
        if(!visited[i]) {
            eventualSafeNodes(graph, visited, isSafe, safeNodes, i);
        }
    }

    graph[0].resize(safeNodes);

    for(--n; n > -1; --n) {
        if(isSafe[n]) {
            graph[0][--safeNodes] = n;
        }
    }

    return graph[0];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printGraph(vector<vector<int>> graph) {
    for(short i = 0; i < graph.size(); ++i) {
        cout << i << ": ";
        for(int node : graph[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> graph, vector<int> expected) {
    cout << "Graph:" << endl;
    printGraph(graph);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result:   ";
    printArray(eventualSafeNodes(graph));

    cout << endl;
}

int main() {
    vector<vector<int>> graph1 = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> expected1 = {2, 4, 5, 6};
    test(graph1, expected1);

    vector<vector<int>> graph2 = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    vector<int> expected2 = {4};
    test(graph2, expected2);

    vector<vector<int>> graph3 = {{}, {0}, {1}, {2}, {3}};
    vector<int> expected3 = {0, 1, 2, 3, 4};
    test(graph3, expected3);

    vector<vector<int>> graph4 = {{1, 2}, {2}, {3}, {4}, {}};
    vector<int> expected4 = {0, 1, 2, 3, 4};
    test(graph4, expected4);

    vector<vector<int>> graph5 = {{}, {}, {}, {}, {}};
    vector<int> expected5 = {0, 1, 2, 3, 4};
    test(graph5, expected5);

    vector<vector<int>> graph6 = {{1}, {2}, {3}, {1}};
    vector<int> expected6 = {};
    test(graph6, expected6);

    return 0;
}
