#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minTime(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    vector<int> visited(n, false);

    int i;
    for(i = edges.size() - 1; i > -1; --i) {
        graph[edges[i][0]].push_back(i);
    }

    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> times(cmp);
    int time;
    int node;

    times.push({0, 0});
    --n;

    while(!times.empty()) {
        node = times.top().first;
        time = times.top().second;
        times.pop();

        if(node == n) {
            return time;
        } else if(visited[node]) {
            continue;
        }
        visited[node] = true;

        for(i = graph[node].size() - 1; i > -1; --i) {
            if(!visited[edges[graph[node][i]][1]] && time <= edges[graph[node][i]][3]) {
                times.push({edges[graph[node][i]][1], max(time, edges[graph[node][i]][2]) + 1});
            }
        }
    }

    return -1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> edges, int expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << ", " << edge[2] << ", " << edge[3] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minTime(n, edges) << endl;

    cout << endl;
}

int main() {
    test(3, { {0, 1, 0, 1}, {1, 2, 2, 5} }, 3);
    test(4, { {0, 1, 0, 3}, {1, 3, 7, 8}, {0, 2, 1, 5}, {2, 3, 4, 7} }, 5);
    test(3, { {1, 0, 1, 3}, {1, 2, 3, 5} }, -1);
    test(2, { {0, 1, 0, 10} }, 1);
    test(3, { {0, 1, 5, 5}, {1, 2, 6, 10} }, 7);

    return 0;
}
