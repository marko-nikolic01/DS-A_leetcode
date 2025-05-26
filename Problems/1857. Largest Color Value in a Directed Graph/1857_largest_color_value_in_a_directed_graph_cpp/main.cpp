#include <iostream>
#include <vector>

using namespace std;

int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.length();
    vector<vector<int>> graph(n);
    vector<int> parents(n, 0);

    int i;
    for(i = edges.size() - 1; i > -1; --i) {
        graph[edges[i][0]].push_back(edges[i][1]);
        ++parents[edges[i][1]];
    }

    vector<int> traversal;
    vector<vector<int>> pathValues(n, vector<int>(26, 0));
    int pathValue = -1;
    int nodes = 0;
    int node;

    int j;
    for(int m = --n; m > -1; --m) {
        if(parents[m] == 0) {
            traversal.push_back(m);

            if(++pathValues[m][colors[m] - 'a'] > pathValue) {
                pathValue = pathValues[m][colors[m] - 'a'];
            }

            while(!traversal.empty()) {
                ++nodes;
                node = traversal.back();
                traversal.pop_back();
                parents[node] = -1;

                for(i = graph[node].size() - 1; i > -1; --i) {
                    for(j = 0; j < 26; ++j) {
                        if(pathValues[node][j] > pathValues[graph[node][i]][j]) {
                            pathValues[graph[node][i]][j] = pathValues[node][j];
                        }
                    }

                    if(--parents[graph[node][i]] < 1) {
                        traversal.push_back(graph[node][i]);

                        if(++pathValues[graph[node][i]][colors[graph[node][i]] - 'a'] > pathValue) {
                            pathValue = pathValues[graph[node][i]][colors[graph[node][i]] - 'a'];
                        }
                    }
                }

            }
        }
    }

    return nodes > n ? pathValue : -1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string colors, vector<vector<int>> edges, int expected) {
    cout << "Colors: " << colors << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestPathValue(colors, edges) << endl;

    cout << endl;
}

int main() {
    test("abaca", {{0,1},{0,2},{2,3},{3,4}}, 3);
    test("a", {{0,0}}, -1);
    test("aaaaa", {{0,1},{1,2},{2,3},{3,4}}, 5);
    test("abcde", {{0,1},{0,2},{1,3},{2,4}}, 1);
    test("bbbhb", {{0,2},{3,0},{1,3},{4,1}}, 4);
    test("abc", {{0,1}, {1,2}, {2,0}}, -1);

    return 0;
}
