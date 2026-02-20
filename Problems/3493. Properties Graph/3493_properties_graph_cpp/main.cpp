#include <iostream>
#include <vector>

using namespace std;

int numberOfComponents(vector<vector<int>>& properties, int k) {
    short n = properties.size();
    vector<pair<long, long>> sets(n, {0, 0});
    vector<vector<short>> graph(n);
    short components = 0;
    short edges;
    long intersection;

    short i;
    short j;
    for(i = --n; i > -1; --i) {
        for(j = properties[i].size() - 1; j > -1; --j) {
            if(--properties[i][j] < 63) {
                sets[i].first |= 1L << properties[i][j];
            } else {
                sets[i].second |= 1L << (properties[i][j] - 63);
            }
        }
    }

    for(i = n; i > 0; --i) {
        for(j = i - 1; j > -1; --j) {
            edges = 0;
            intersection = sets[i].first & sets[j].first;

            while(intersection > 0) {
                if((intersection & 1) > 0) {
                    ++edges;
                }

                intersection >>= 1;
            }

            intersection = sets[i].second & sets[j].second;

            while(intersection > 0) {
                if((intersection & 1) > 0) {
                    ++edges;
                }

                intersection >>= 1;
            }

            if(edges >= k) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<short> traversal;

    for(n; n > -1; --n) {
        if(sets[n].first > -1) {
            ++components;
            traversal.push_back(n);
            sets[n].first = -1;

            while(!traversal.empty()) {
                i = traversal.back();
                traversal.pop_back();

                for(j = graph[i].size() - 1; j > -1; --j) {
                    if(sets[graph[i][j]].first > -1) {
                        traversal.push_back(graph[i][j]);
                        sets[graph[i][j]].first = -1;
                    }
                }
            }
        }
    }

    return components;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> properties, int k, int expected) {
    cout << "Properties:" << endl;
    printMatrix(properties);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfComponents(properties, k) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {1, 1}, {3, 4}, {4, 5}, {5, 6}, {7, 7}}, 1, 3);
    test({{1, 2, 3}, {2, 3, 4}, {4, 3, 5}}, 2, 1);
    test({{1, 1}, {1, 1}}, 2, 2);
    test({{1}, {2}, {3}}, 1, 3);
    test({{1, 2}, {2, 3}, {4, 5}}, 1, 2);

    return 0;
}
