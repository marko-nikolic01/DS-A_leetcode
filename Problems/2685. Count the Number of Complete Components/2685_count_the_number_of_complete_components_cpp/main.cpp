#include <iostream>
#include <vector>

using namespace std;

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    short components = 0;

    vector<vector<short>> graph(n);

    short i = edges.size();
    for(--i; i > -1; --i) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<short> traversal;

    long visited = 0;
    long currentVisited;
    long neighbours;

    short node;

    bool isComponent;

    for(--n; n > -1; --n) {
        if((visited & (1l << n)) < 1) {
            currentVisited = 1l << n;

            isComponent = true;

            for(i = graph[n].size() - 1; i > -1; --i) {
                currentVisited |= 1l << graph[n][i];

                traversal.push_back(graph[n][i]);
            }

            visited |= currentVisited;

            while(!traversal.empty()) {
                node = traversal.back();
                traversal.pop_back();

                neighbours = 1l << node;

                for(i = graph[node].size() - 1; i > -1; --i) {
                    neighbours |= 1l << graph[node][i];

                    if((visited & (1l << node)) < 1) {
                        traversal.push_back(graph[node][i]);
                    }
                }

                if(neighbours != currentVisited) {
                    isComponent = false;
                }

                visited |= neighbours;
            }

            if(isComponent) {
                ++components;
            }
        }
    }

    return components;
}

void test(int n, vector<vector<int>> edges, int expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for (vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countCompleteComponents(n, edges) << endl;

    cout << endl;
}

int main() {
    test(6, {{0,1},{0,2},{1,2},{3,4}}, 3);
    test(6, {{0,1},{0,2},{1,2},{3,4},{3,5}}, 1);
    test(5, {{0,1},{1,2},{2,3},{3,4}}, 0);
    test(4, {{0,1},{1,2},{2,0},{3,3}}, 2);
    test(7, {{0,1},{1,2},{2,0},{3,4},{4,5},{5,3},{6,6}}, 3);

    return 0;
}
