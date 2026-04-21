#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    int distance = 0;
    int n = source.size();
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    unordered_map<int, int> distances;
    vector<int> traversal;

    int i;
    for(i = allowedSwaps.size() - 1; i > -1; --i) {
        graph[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
        graph[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
    }

    int j;
    unordered_map<int, int>::iterator it;
    while(--n > -1) {
        if(!visited[n]) {
            traversal.push_back(n);
            visited[n] = true;
            distances.clear();

            while(!traversal.empty()) {
                i = traversal.back();
                traversal.pop_back();

                ++distances[source[i]];
                --distances[target[i]];

                for(j = graph[i].size() - 1; j > -1; --j) {
                    if(!visited[graph[i][j]]) {
                        traversal.push_back(graph[i][j]);
                        visited[graph[i][j]] = true;
                    }
                }
            }

            for(it = distances.begin(); it != distances.end(); ++it) {
                if(it->second > 0) {
                    distance += it->second;
                }
            }
        }
    }

    return distance;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> source, vector<int> target, vector<vector<int>> allowedSwaps, int expected) {
    cout << "Source: ";
    printArray(source);

    cout << "Target: ";
    printArray(target);

    cout << "Allowed swaps: ";
    for(vector<int> allowedSwap : allowedSwaps) {
        cout << "[" << allowedSwap[0] << ", " << allowedSwap[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumHammingDistance(source, target, allowedSwaps) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4}, {2, 1, 4, 5}, {{0, 1}, {2, 3}}, 1);
    test({1, 2, 3, 4}, {1, 3, 2, 4}, {}, 2);
    test({5, 1, 2, 4, 3}, {1, 5, 4, 2, 3}, {{0, 4}, {4, 2}, {1, 3}, {1, 4}}, 0);
    test({3, 3, 3}, {3, 3, 3}, {}, 0);
    test({1, 1, 1}, {2, 2, 2}, {{0, 1}, {1, 2}}, 3);

    return 0;
}
