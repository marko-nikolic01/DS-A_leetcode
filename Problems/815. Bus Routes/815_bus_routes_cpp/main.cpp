#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if(source == target) {
        return 0;
    }

    unordered_map<int, vector<short>> stops;
    int stop;
    short time;

    short i;
    int j;
    for(i = routes.size() - 1; i > -1; --i) {
        for(j = routes[i].size() - 1; j > -1; --j) {
            stops[routes[i][j]].push_back(i);
        }
    }

    if(stops.find(source) == stops.end() || stops.find(target) == stops.end()) {
        return -1;
    }

    queue<pair<int, short>> traversal;
    traversal.push({source, 0});

    unordered_map<int, vector<short>>:: iterator it;
    while(!traversal.empty()) {
        stop = traversal.front().first;
        time = traversal.front().second + 1;
        traversal.pop();

        it = stops.find(stop);
        for(i = it->second.size() - 1; i > -1; --i) {
            for(j = routes[it->second[i]].size() - 1; j > -1; --j) {
                if(routes[it->second[i]][j] == target) {
                    return time;
                }

                if(stops[routes[it->second[i]][j]].size() > 0) {
                    traversal.push({routes[it->second[i]][j], time});
                }
            }

            routes[it->second[i]].resize(0);
        }

        it->second.resize(0);
    }

    return -1;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> routes, int source, int target, int expected) {
    cout << "Routes:" << endl;
    printMatrix(routes);

    cout << "Source: " << source << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numBusesToDestination(routes, source, target) << endl;

    cout << endl;
}

int main() {
    test({{1, 2, 7}, {3, 6, 7}}, 1, 6, 2);
    test({{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}}, 15, 12, -1);
    test({{1, 7}, {3, 5}}, 5, 5, 0);
    test({{1, 2, 7}, {3, 6, 7}}, 8, 6, -1);
    test({{2, 4, 6, 8, 10}}, 2, 10, 1);

    return 0;
}
