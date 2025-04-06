#include <iostream>
#include <vector>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    short n = graph.size();
    vector<bool> isColored(n, false);
    vector<bool> colors(n);

    vector<short> traversal;
    short node;

    short j;
    for(short i = --n; i > -1; --i) {
        if(!isColored[i]) {
            traversal.push_back(i);
            isColored[i] = true;
            colors[i] = false;

            while(!traversal.empty()) {
                node = traversal.back();
                traversal.pop_back();

                for(j = graph[node].size() - 1; j > -1; --j) {
                    if(!isColored[graph[node][j]]) {
                        traversal.push_back(graph[node][j]);
                        isColored[graph[node][j]] = true;
                        colors[graph[node][j]] = !colors[node];
                    } else if(colors[graph[node][j]] == colors[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

void test(vector<vector<int>> graph, bool expected) {
    cout << "Graph: ";
    for(vector<int> nodes : graph) {
        cout << "[";
        for(int i = 0; i < nodes.size(); ++i) {
            cout << nodes[i];
            if(i != nodes.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isBipartite(graph) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{1,2,3},{0,2},{0,1,3},{0,2}}, false);
    test({{1,3},{0,2},{1,3},{0,2}}, true);
    test({{1},{0},{3},{2}}, true);
    test({{1},{0,3},{3},{1,2}}, true);
    test({{},{2,4,6},{1,4,8,9},{7,8},{1,2},{6,9},{1,5,7},{3,6,9},{2,3},{2,4,5,7}}, false);

    return 0;
}
