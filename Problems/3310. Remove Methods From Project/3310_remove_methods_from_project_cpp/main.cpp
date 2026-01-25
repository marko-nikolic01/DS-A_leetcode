#include <iostream>
#include <vector>

using namespace std;

vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> graph(n);

    int i;
    for(i = invocations.size() - 1; i > -1; --i) {
        graph[invocations[i][0]].push_back(invocations[i][1]);
    }

    vector<int> traversal(1, k);
    vector<int> suspicious(n, 0);

    ++suspicious[k];

    while(!traversal.empty()) {
        k = traversal.back();
        traversal.pop_back();

        for(i = graph[k].size() - 1; i > -1; --i) {
            if(suspicious[graph[k][i]] < 1) {
                traversal.push_back(graph[k][i]);
                ++suspicious[graph[k][i]];
            }
        }
    }

    int j;
    for(i = --n; i > -1; --i) {
        if(suspicious[i] == 0) {
            traversal.push_back(i);
            --suspicious[i];

            while(!traversal.empty()) {
                k = traversal.back();
                traversal.pop_back();

                for(j = graph[k].size() - 1; j > -1; --j) {
                    if(suspicious[graph[k][j]] > 0) {
                        for(n; n > -1; --n) {
                            suspicious[n] = n;
                        }

                        return suspicious;
                    } else if(suspicious[graph[k][j]] > -1) {
                        traversal.push_back(graph[k][j]);
                        --suspicious[graph[k][j]];
                    }
                }
            }
        }
    }

    k = -1;
    for(i = 0; i <= n; ++i) {
        if(suspicious[i] < 1) {
            suspicious[++k] = i;
        }
    }

    suspicious.resize(++k);

    return suspicious;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, int k, vector<vector<int>> invocations, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Invocations: ";
    for(vector<int> invocation : invocations) {
        cout << "[" << invocation[0] << ", " << invocation[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(remainingMethods(n, k, invocations));

    cout << endl;
}

int main() {
    test(4, 1, {{1, 2}, {0, 1}, {3, 2}}, {0, 1, 2, 3});
    test(5, 0, {{1, 2}, {0, 2}, {0, 1}, {3, 4}}, {3, 4});
    test(3, 2, {{1, 2}, {0, 1}, {2, 0}}, {});
    test(3, 2, {{0, 2}}, {0, 1, 2});
    test(3, 0, {{1, 2}, {2, 1}}, {1, 2});
    test(6, 3, {{3, 4}, {3, 5}, {0, 1}, {1, 2}}, {0, 1, 2});

    return 0;
}
