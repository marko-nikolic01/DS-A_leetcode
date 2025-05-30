#include <iostream>
#include <vector>

using namespace std;

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int n = edges1.size();
    vector<vector<int>> graph(++n);
    vector<int> colors1(n);
    int color11 = 0;
    int color21 = 0;
    vector<bool> visited(n--, false);

    int i;
    for(i = --n; i > -1; --i) {
        graph[edges1[i][0]].push_back(edges1[i][1]);
        graph[edges1[i][1]].push_back(edges1[i][0]);
    }

    vector<int> traversal;
    int node;

    for(++n; n > -1; --n) {
        if(!visited[n]) {
            traversal.push_back(n);
            visited[n] = true;
            colors1[n] = 0;
            ++color11;

            while(!traversal.empty()) {
                node = traversal.back();
                traversal.pop_back();

                for(i = graph[node].size() - 1; i > -1; --i) {
                    if(!visited[graph[node][i]]) {
                        traversal.push_back(graph[node][i]);
                        visited[graph[node][i]] = true;

                        if(colors1[node] > 0) {
                            colors1[graph[node][i]] = 0;
                            ++color11;
                        } else {
                            colors1[graph[node][i]] = 1;
                            ++color21;
                        }
                    }
                }
            }
        }
    }

    n = edges2.size();
    graph.resize(0);
    graph.resize(++n);
    vector<bool> colors2(n);
    int color12 = 0;
    int color22 = 0;
    visited.resize(0);
    visited.resize(n--, false);

    for(i = --n; i > -1; --i) {
        graph[edges2[i][0]].push_back(edges2[i][1]);
        graph[edges2[i][1]].push_back(edges2[i][0]);
    }

    for(++n; n > -1; --n) {
        if(!visited[n]) {
            traversal.push_back(n);
            visited[n] = true;
            colors2[n] = false;
            ++color12;

            while(!traversal.empty()) {
                node = traversal.back();
                traversal.pop_back();

                for(i = graph[node].size() - 1; i > -1; --i) {
                    if(!visited[graph[node][i]]) {
                        traversal.push_back(graph[node][i]);
                        visited[graph[node][i]] = true;

                        if(colors2[node]) {
                            colors2[graph[node][i]] = false;
                            ++color12;
                        } else {
                            colors2[graph[node][i]] = true;
                            ++color22;
                        }
                    }
                }
            }
        }
    }

    if(color12 > color22) {
        color11 += color12;
        color21 += color12;
    } else {
        color11 += color22;
        color21 += color22;
    }

    for(i = edges1.size(); i > -1; --i) {
        if(colors1[i] < 1) {
            colors1[i] = color11;
        } else {
            colors1[i] = color21;
        }
    }

    return colors1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> edges1, vector<vector<int>> edges2, vector<int> expected) {
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

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxTargetNodes(edges1, edges2));

    cout << endl;
}

int main() {
    test({{0, 1}, {0, 2}, {2, 3}, {2, 4}}, {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}}, {8, 7, 7, 8, 8});
    test({{0, 1}, {0, 2}, {0, 3}, {0, 4}}, {{0, 1}, {1, 2}, {2, 3}}, {3, 6, 6, 6, 6});
    test({{0, 1}, {1, 2}, {2, 3}}, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}, {5, 5, 5, 5});
    test({{0, 1}, {0, 2}, {0, 3}}, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}}, {4, 6, 6, 6});
    test({{0, 1}, {1, 2}, {2, 3}, {1, 4}}, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {1, 5}, {5, 6}}, {7, 6, 7, 6, 7});

    return 0;
}
