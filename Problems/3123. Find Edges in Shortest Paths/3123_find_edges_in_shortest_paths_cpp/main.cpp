#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
    int i = edges.size();
    vector<bool> isPartOfShortestPath(i, false);

    vector<vector<pair<int, int>>> graph(n);
    unordered_map<int, int> edgeIndexes;

    for(--i; i > -1; --i) {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});

        edgeIndexes[50001 * (edges[i][0] - 10000) + edges[i][1]] = i;
        edgeIndexes[50001 * (edges[i][1] - 10000) + edges[i][0]] = i;
    }

    vector<vector<int>> parents(n);
    vector<int> shortestPath(n, 2147483647);
    shortestPath[0] = 0;

    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> traversal(cmp);
    traversal.push({0, 0});

    int pathLength;

    while(!traversal.empty()) {
        n = traversal.top().first;
        pathLength = traversal.top().second;
        traversal.pop();

        for(i = graph[n].size() - 1; i > -1; --i) {
            if(pathLength + graph[n][i].second < shortestPath[graph[n][i].first]) {
                parents[graph[n][i].first].resize(1);
                parents[graph[n][i].first][0] = n;

                shortestPath[graph[n][i].first] = pathLength + graph[n][i].second;

                traversal.push({graph[n][i].first, shortestPath[graph[n][i].first]});
            } else if(pathLength + graph[n][i].second == shortestPath[graph[n][i].first]) {
                parents[graph[n][i].first].push_back(n);
            }
        }
    }

    n = graph.size();
    vector<int> parentTraversal = {--n};
    shortestPath[n] = -1;

    while(!parentTraversal.empty()) {
        n = parentTraversal.back();
        parentTraversal.pop_back();

        for(i = parents[n].size() - 1; i > -1; --i) {
            isPartOfShortestPath[edgeIndexes[50001 * (n - 10000) + parents[n][i]]] = true;

            if(shortestPath[parents[n][i]] > -1) {
                shortestPath[parents[n][i]] = -1;
                parentTraversal.push_back(parents[n][i]);
            }
        }
    }

    return isPartOfShortestPath;
}

void printArray(vector<bool> array) {
    for(bool a : array) {
        cout << (a ? "true" : "false") << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> edges, vector<bool> expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << ", " << edge[2] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findAnswer(n, edges));

    cout << endl;
}

int main() {
    test(6, {{0,1,4}, {0,2,1}, {1,3,2}, {1,4,3}, {1,5,1}, {2,3,1}, {3,5,3}, {4,5,2}}, {true, true, true, false, true, true, true, false}),
    test(3, {{0,1,2}, {1,2,2}}, {true, true}),
    test(3, {{0,1,2}, {1,2,2}, {0,2,3}}, {false, false, true}),
    test(4, {{0,1,1}, {1,2,1}, {2,3,1}, {0,3,3}}, {true, true, true, true}),
    test(5, {{0,1,1}, {1,2,1}, {2,4,1}, {0,3,2}, {3,4,1}}, {true, true, true, true, true});

    return 0;
}
