#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minScore(int n, vector<vector<int>>& roads) {
    int distance = INT_MAX;
    vector<vector<pair<int, int>>> graph(n);
    vector<bool> visited(n, false);
    vector<int> traversal;
    int city;

    visited[--n] = true;
    traversal.push_back(n);

    for(n = roads.size() - 1; n > -1; --n) {
        graph[--roads[n][0]].push_back({--roads[n][1], roads[n][2]});
        graph[roads[n][1]].push_back({roads[n][0], roads[n][2]});
    }

    while(!traversal.empty()) {
        city = traversal.back();
        traversal.pop_back();

        for(n = graph[city].size() - 1; n > -1; --n) {
            if(graph[city][n].second < distance) {
                distance = graph[city][n].second;
            }

            if(!visited[graph[city][n].first]) {
                visited[graph[city][n].first] = true;
                traversal.push_back(graph[city][n].first);
            }
        }
    }

    return distance;
}

void test(int n, vector<vector<int>> roads, int expected) {
    cout << "n: " << n << endl;

    cout << "Roads: ";
    for(vector<int> road : roads) {
        cout << "[" << road[0] << ", " << road[1] << ", " << road[2] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minScore(n, roads) << endl;

    cout << endl;
}

int main() {
    test(4, {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}}, 5);
    test(4, {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}}, 2);
    test(2, {{1, 2, 1}}, 1);
    test(3, {{1, 2, 5}, {2, 3, 1}}, 1);
    test(5, {{1, 2, 10}, {2, 3, 10}, {3, 4, 10}, {4, 5, 10}}, 10);

    return 0;
}
