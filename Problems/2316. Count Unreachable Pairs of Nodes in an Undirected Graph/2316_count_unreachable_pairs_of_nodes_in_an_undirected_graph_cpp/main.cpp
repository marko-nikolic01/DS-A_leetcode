#include <iostream>
#include <vector>

using namespace std;

long long countPairs(int n, vector<vector<int>>& edges) {
    long pairs = 0;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> traversal;
    long group;
    int nodes = n;
    int node;

    int i;
    for(i = edges.size() - 1; i > -1; --i) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    while(--n > -1) {
        if(!visited[n]) {
            visited[n] = true;
            traversal.push_back(n);
            group = 1;

            while(!traversal.empty()) {
                node = traversal.back();
                traversal.pop_back();

                for(i = graph[node].size() - 1; i > -1; --i) {
                    if(!visited[graph[node][i]]) {
                        visited[graph[node][i]] = true;
                        traversal.push_back(graph[node][i]);
                        ++group;
                    }
                }
            }

            pairs += group * (nodes - group);
        }
    }

    return pairs >> 1;
}

void test(int n, vector<vector<int>> edges, long long expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPairs(n, edges) << endl;

    cout << endl;
}

int main() {
    test(3, {{0, 1}, {0, 2}, {1, 2}}, 0);
    test(7, {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}}, 14);
    test(5, {}, 10);
    test(5, {{0, 1}, {2, 3}}, 8);
    test(10, {{0, 1}, {1, 2}, {3, 4}, {5, 6}, {6, 7}, {7, 5}}, 38);
    test(1, {}, 0);
    test(100, {}, 4950);

    return 0;
}
