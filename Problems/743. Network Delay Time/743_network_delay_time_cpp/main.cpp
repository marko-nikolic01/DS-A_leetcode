#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<short, short>>> graph(n);
    vector<int> delayTimes(n, INT_MAX);
    int time = 0;
    int t;

    int s = n;

    short i;
    for(i = times.size() - 1; i > -1; --i) {
        graph[--times[i][0]].push_back({--times[i][1], times[i][2]});
    }

    priority_queue<pair<int, short>, vector<pair<int, short>>, greater<pair<int, short>>> traversal;
    traversal.push({0, --k});
    delayTimes[k] = 0;

    while(n > 0 && !traversal.empty()) {
        t = traversal.top().first;
        k = traversal.top().second;
        traversal.pop();

        if(t > delayTimes[k]) {
            continue;
        }

        --n;

        if(t > time) {
            time = t;
        }

        for(i = graph[k].size() - 1; i > -1; --i) {
            if(t + graph[k][i].second < delayTimes[graph[k][i].first]) {
                delayTimes[graph[k][i].first] = t + graph[k][i].second;
                traversal.push({delayTimes[graph[k][i].first], graph[k][i].first});
            }
        }
    }

    return n < 1 ? t : -1;
}

void test(vector<vector<int>> times, int n, int k, int expected) {
    cout << "Times: ";
    for(vector<int> time : times) {
        cout << "[" << time[0] << ", " << time[1] << ", " << time[2] << "] ";
    }
    cout << endl;

    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << networkDelayTime(times, n, k) << endl;

    cout << endl;
}

int main(){
    test({{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2, 2);
    test({{1, 2, 1}}, 2, 1, 1);
    test({{1, 2, 1}}, 2, 2, -1);
    test({{1, 2, 3}, {2, 3, 4}, {1, 3, 10}}, 3, 1, 7);
    test({{1, 2, 1}, {1, 3, 4}, {2, 3, 1}}, 3, 1, 2);

    return 0;
}
