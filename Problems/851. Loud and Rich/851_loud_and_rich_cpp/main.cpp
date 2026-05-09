#include <iostream>
#include <vector>

using namespace std;

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    short n = quiet.size();
    vector<short> loud(n);
    vector<vector<short>> richerGraph(n);
    vector<short> richerLeft(n, 0);
    vector<short> traversal;

    short i;
    for(i = richer.size() - 1; i > -1; --i) {
        richerGraph[richer[i][0]].push_back(richer[i][1]);
        ++richerLeft[richer[i][1]];
    }

    while(--n > -1) {
        loud[n] = quiet[n];
        quiet[n] = n;

        if(richerLeft[n] < 1) {
            traversal.push_back(n);
        }
    }

    while(!traversal.empty()) {
        n = traversal.back();
        traversal.pop_back();

        for(i = richerGraph[n].size() - 1; i > -1; --i) {
            if(loud[quiet[n]] < loud[quiet[richerGraph[n][i]]]) {
                quiet[richerGraph[n][i]] = quiet[n];
            }

            if(--richerLeft[richerGraph[n][i]] < 1) {
                traversal.push_back(richerGraph[n][i]);
            }
        }
    }

    return quiet;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> richer, vector<int> quiet, vector<int> expected) {
    cout << "Richer than: ";
    for(vector<int> r : richer) {
        cout << "[" << r[0] << ", " << r[1] << "] ";
    }
    cout << endl;

    cout << "Quietness: ";
    printArray(quiet);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(loudAndRich(richer, quiet));

    cout << endl;
}

int main() {
    test({{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}}, {3, 2, 5, 4, 6, 1, 7, 0}, {5, 5, 2, 5, 4, 5, 6, 7});
    test({}, {0}, {0});
    test({{0, 1}, {1, 2}, {2, 3}}, {3, 1, 2, 0}, {0, 1, 1, 3});
    test({}, {1, 0, 2, 3}, {0, 1, 2, 3});
    test({{0, 2}, {1, 2}}, {0, 2, 1}, {0, 1, 0});
    test({{0, 1}, {0, 2}, {1, 3}, {2, 3}}, {2, 0, 3, 1}, {0, 1, 0, 1});

    return 0;
}
