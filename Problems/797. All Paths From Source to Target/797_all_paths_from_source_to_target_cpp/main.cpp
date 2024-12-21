#include <iostream>
#include <vector>

using namespace std;

void allPathsSourceTarget(vector<vector<int>>& graph, int node, vector<vector<int>>& paths, vector<int>& path) {
    int n = graph.size() - 1;

    for(int i = graph[node].size() - 1; i > -1; --i) {
        path.push_back(graph[node][i]);

        if(graph[node][i] == n) {
            paths.push_back(path);
        } else {
            allPathsSourceTarget(graph, graph[node][i], paths, path);
        }

        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> paths;
    vector<int> path = {0};

    allPathsSourceTarget(graph, 0, paths, path);

    return paths;
}

void printMatrix(vector<vector<int>> matrix) {
    for (vector<int> row : matrix) {
        cout << "[";
        for (int i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i != row.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    }
    cout << endl;
}

void test(vector<vector<int>> graph, vector<vector<int>> expected) {
    cout << "Graph: ";
    printMatrix(graph);

    vector<vector<int>> result = allPathsSourceTarget(graph);

    cout << "Expected: ";
    printMatrix(expected);

    cout << "Result: ";
    printMatrix(allPathsSourceTarget(graph));

    cout << endl;
}

int main() {
    test({{1, 2}, {3}, {3}, {}}, {{0, 2, 3}, {0, 1, 3}});
    test({{1}, {}}, {{0, 1}});
    test({{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}}, {{0, 1, 4}, {0, 1, 2, 3, 4}, {0, 1, 3, 4}, {0, 3, 4}, {0, 4}});
    test({{1, 2, 3}, {2}, {3}, {}}, {{0, 3}, {0, 2, 3}, {0, 1, 2, 3}});
    test({{1}, {2}, {3}, {}}, {{0, 1, 2, 3}});

    return 0;
}
