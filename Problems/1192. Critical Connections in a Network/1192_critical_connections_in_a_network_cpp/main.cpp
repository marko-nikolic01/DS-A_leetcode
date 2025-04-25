#include <iostream>
#include <vector>

using namespace std;

int criticalConnections(vector<vector<int>>& critical, vector<vector<int>>& servers, vector<int>& visited, int server, int parent, int& n) {
    visited[server] = ++n;

    int minNext = n;
    int nNext;

    for(int i = servers[server].size() - 1; i > -1; --i) {
        if(servers[server][i] != parent) {
            if(visited[servers[server][i]] > 0) {
                if(visited[servers[server][i]] < minNext) {
                    minNext = visited[servers[server][i]];
                }
            } else {
                nNext = criticalConnections(critical, servers, visited, servers[server][i], server, n);
                if(nNext > visited[server]) {
                    critical.push_back({server, servers[server][i]});
                }

                if(nNext < minNext) {
                    minNext = nNext;
                }
            }
        }
    }

    return minNext;
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> critical;

    vector<vector<int>> servers(n);

    for(int i = connections.size() - 1; i > -1; --i) {
        servers[connections[i][0]].push_back(connections[i][1]);
        servers[connections[i][1]].push_back(connections[i][0]);
    }

    vector<int> visited(n, -1);

    criticalConnections(critical, servers, visited, 0, -1, n);

    return critical;
}

void test(int n, vector<vector<int>> connections, vector<vector<int>> expected) {
    cout << "n: " << n << endl;

    cout << "Connections: ";
    for(vector<int> connection : connections) {
        cout << "[" << connection[0] << ", " << connection[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[" << e[0] << ", " << e[1] << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<int> result : criticalConnections(n, connections)) {
        cout << "[" << result[0] << ", " << result[1] << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test(4, {{0, 1}, {1, 2}, {2, 0}, {1, 3}}, {{1, 3}});
    test(2, {{0, 1}}, {{0, 1}});
    test(3, {{0, 1}, {1, 2}, {2, 0}}, {});
    test(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}, {{3, 4}, {2, 3}, {1, 2}, {0, 1}});
    test(6, {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}}, {{1, 3}});

    return 0;
}
