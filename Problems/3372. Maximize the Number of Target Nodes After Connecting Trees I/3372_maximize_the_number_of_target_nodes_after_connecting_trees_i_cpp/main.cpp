#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    short n = edges1.size();
    vector<vector<short>> graph(++n);
    vector<short> visited(n, -1);
    vector<int> targetNodes(n--);

    short i;
    for(i = n - 1; i > -1; --i) {
        graph[edges1[i][0]].push_back(edges1[i][1]);
        graph[edges1[i][1]].push_back(edges1[i][0]);
    }

    queue<short> traversal;
    short node;
    short depth;
    short currentTargetNodes;

    short j;
    for(n; n > -1; --n) {
        traversal.push(n);
        visited[n] = n;
        depth = -1;
        currentTargetNodes = 0;

        while(depth++ < k && !traversal.empty()) {
            for(j = traversal.size(); j > 0; --j) {
                node = traversal.front();
                traversal.pop();
                ++currentTargetNodes;

                for(i = graph[node].size() - 1; i > -1; --i) {
                    if(visited[graph[node][i]] != n) {
                        traversal.push(graph[node][i]);
                        visited[graph[node][i]] = n;
                    }
                }
            }
        }

        while(!traversal.empty()) {
            traversal.pop();
        }

        targetNodes[n] = currentTargetNodes;
    }

    if(--k < 0) {
        return targetNodes;
    }

    n = edges2.size();
    graph.resize(0);
    graph.resize(++n);
    visited.resize(0);
    visited.resize(n--, -1);
    short maxTargetNodes = 0;

    for(i = n - 1; i > -1; --i) {
        graph[edges2[i][0]].push_back(edges2[i][1]);
        graph[edges2[i][1]].push_back(edges2[i][0]);
    }

    for(n; n > -1; --n) {
        traversal.push(n);
        visited[n] = n;
        depth = -1;
        currentTargetNodes = 0;

        while(depth++ < k && !traversal.empty()) {
            for(j = traversal.size(); j > 0; --j) {
                node = traversal.front();
                traversal.pop();
                ++currentTargetNodes;

                for(i = graph[node].size() - 1; i > -1; --i) {
                    if(visited[graph[node][i]] != n) {
                        traversal.push(graph[node][i]);
                        visited[graph[node][i]] = n;
                    }
                }
            }
        }

        while(!traversal.empty()) {
            traversal.pop();
        }

        if(currentTargetNodes > maxTargetNodes) {
            maxTargetNodes = currentTargetNodes;
        }
    }

    for(i = targetNodes.size() - 1; i > -1; --i) {
        targetNodes[i] += maxTargetNodes;
    }

    return targetNodes;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> edges1, vector<vector<int>> edges2, int k, vector<int> expected) {
    cout << "Edges 1: ";
    for(vector<int> edge : edges1) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Edges 2: ";
    for(vector<int> edge : edges2) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxTargetNodes(edges1, edges2, k));

    cout << endl;
}

int main() {
    test({{0, 1}, {0, 2}, {2, 3}, {2, 4}}, {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}}, 2, {9, 7, 9, 8, 8});
    test({{0, 1}, {0, 2}, {0, 3}, {0, 4}}, {{0, 1}, {1, 2}, {2, 3}}, 1, {6, 3, 3, 3, 3});
    test({{0, 1}, {0, 2}}, {{0, 1}, {0, 2}}, 1, {4, 3, 3});
    test({{0, 1}, {1, 2}, {2, 3}}, {{0, 1}, {1, 2}, {2, 3}}, 2, {6, 7, 7, 6});
    test({{0, 1}}, {{0, 1}}, 0, {1, 1});

    return 0;
}
