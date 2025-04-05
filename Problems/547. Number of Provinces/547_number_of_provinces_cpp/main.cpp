#include <iostream>
#include <vector>

using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
    short provinces = 0;

    short n = isConnected.size();
    vector<bool> visited(n, false);

    vector<short> traversal;
    short city;

    short i;
    short j;
    for(short i = --n; i > -1; --i) {
        if(!visited[i]) {
            ++provinces;

            traversal.push_back(i);
            while(!traversal.empty()) {
                city = traversal.back();
                traversal.pop_back();
                visited[city] = true;

                for(j = n; j > -1; --j) {
                    if(isConnected[city][j] && !visited[j]) {
                        traversal.push_back(j);
                    }
                }
            }
        }
    }

    return provinces;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> isConnected, int expected) {
    cout << "Cities:" << endl;
    printMatrix(isConnected);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findCircleNum(isConnected) << endl;

    cout << endl;
}

int main() {
    test({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, 2);
    test({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3);
    test({{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}}, 2);
    test({{1}}, 1);
    test({{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 1, 1, 1}, {0, 0, 0, 1, 1}}, 2);

    return 0;
}
