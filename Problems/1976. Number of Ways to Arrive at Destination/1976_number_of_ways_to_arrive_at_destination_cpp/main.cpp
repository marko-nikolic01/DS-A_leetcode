#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<short, int>>> graph(n);

    int i = roads.size();
    for(--i; i > -1; --i) {
        graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    auto cmp = [](const pair<short, long>& a, const pair<short, long>& b) {
        return a.second > b.second;
    };
    priority_queue<pair<short, long>, vector<pair<short, long>>, decltype(cmp)> traversal(cmp);
    traversal.push({0, 0});

    vector<long> shortestTimes(n, 9223372036854775807);
    vector<int> shortestWays(n--, 0);
    shortestTimes[0] = 0;
    shortestWays[0] = 1;

    short node;
    long time;
    while(traversal.top().first != n) {
        node = traversal.top().first;
        time = traversal.top().second;
        traversal.pop();

        for(i = graph[node].size() - 1; i > -1; --i) {
            if(time + graph[node][i].second < shortestTimes[graph[node][i].first]) {
                shortestTimes[graph[node][i].first] = time + graph[node][i].second;
                shortestWays[graph[node][i].first] = shortestWays[node];

                traversal.push({graph[node][i].first, shortestTimes[graph[node][i].first]});
            } else if(time + graph[node][i].second == shortestTimes[graph[node][i].first]) {
                shortestWays[graph[node][i].first] = (shortestWays[graph[node][i].first] + shortestWays[node]) % 1000000007;
            }
        }
    }

    return shortestWays[n];
}

void test(int n, vector<vector<int>> roads, int expected) {
    cout << "n: " << n << endl;

    cout << "Roads: ";
    for(vector<int> road : roads) {
        cout << "[" << road[0] << ", " << road[1] << ", " << road[2] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPaths(n, roads) << endl;

    cout << endl;
}

int main() {
    test(7, {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}}, 4);
    test(2, {{1, 0, 10}}, 1);
    test(3, {{0, 1, 1}, {1, 2, 1}, {0, 2, 2}}, 2);
    test(5, {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}}, 1);
    test(4, {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {2, 3, 1}}, 2);

    return 0;
}
