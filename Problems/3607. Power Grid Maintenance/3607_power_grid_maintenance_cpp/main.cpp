#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    vector<vector<int>> powerStations(c);

    int i;
    for(i = connections.size() - 1; i > -1; --i) {
        powerStations[--connections[i][0]].push_back(--connections[i][1]);
        powerStations[connections[i][1]].push_back(connections[i][0]);
    }

    vector<int> traversal;
    vector<priority_queue<int, vector<int>, greater<int>>> grids;
    vector<int> grid(c, -1);
    int g = -1;
    int station;

    for(--c; c > -1; --c) {
        if(grid[c] > -1) {
            continue;
        }

        traversal.push_back(c);
        grids.push_back(priority_queue<int, vector<int>, greater<int>>());
        grids[++g].push(c);
        grid[c] = g + 1;

        while(!traversal.empty()) {
            station = traversal.back();
            traversal.pop_back();

            for(i = powerStations[station].size() - 1; i > -1; --i) {
                if(grid[powerStations[station][i]] < 0) {
                    traversal.push_back(powerStations[station][i]);
                    grids[g].push(powerStations[station][i]);
                    grid[powerStations[station][i]] = g + 1;
                }
            }
        }
    }

    vector<int> answers;

    int n = queries.size();
    for(i = 0; i < n; ++i) {
        if(queries[i][0] < 2) {
            if(grid[--queries[i][1]] < 0) {
                g = -grid[queries[i][1]] - 1;

                while(!grids[g].empty() && grid[grids[g].top()] < 0) {
                    grids[g].pop();
                }

                answers.push_back(grids[g].empty() ? -1 : grids[g].top() + 1);
            } else {
                answers.push_back(++queries[i][1]);
            }
        } else if(grid[--queries[i][1]] > 0) {
            grid[queries[i][1]] = -grid[queries[i][1]];
        }
    }

    return answers;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int c, vector<vector<int>> connections, vector<vector<int>> queries, vector<int> expected) {
    cout << "c: " << c << endl;

    cout << "Connections: ";
    for(vector<int> connection : connections) {
        cout << "[" << connection[0] << ", " << connection[1] << "] ";
    }
    cout << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(processQueries(c, connections, queries));

    cout << endl;
}

int main() {
    test(5, {{1, 2}, {2, 3}, {3, 4}, {4, 5}}, {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}}, {3, 2, 3});
    test(3, {}, {{1, 1}, {2, 1}, {1, 1}}, {1, -1});
    test(1, {}, {{2, 1}, {2, 1}, {1, 1}, {1, 1}, {2, 1}, {1, 1}, {1, 1}, {2, 1}}, {-1, -1, -1, -1});
    test(4, {}, {{1, 2}, {2, 2}, {1, 2}, {1, 3}, {2, 3}, {1, 3}}, {2, -1, 3, -1});
    test(5, {{1, 2}, {2, 3}, {4, 5}}, {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 3}, {2, 3}, {1, 3}, {1, 4}}, {3, 2, 3, -1, 4});

    return 0;
}
