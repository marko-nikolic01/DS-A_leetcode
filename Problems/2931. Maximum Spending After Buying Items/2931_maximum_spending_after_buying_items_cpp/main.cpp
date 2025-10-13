#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxSpending(vector<vector<int>>& values) {
    vector<int> items;
    long price = 0;

    long i;
    int m = values.size();
    short n = values[0].size() - 1;
    for(short j = --m; j > -1; --j) {
        for(i = n; i > -1; --i) {
            items.push_back(values[j][i]);
        }
    }

    sort(items.begin(), items.end());

    m = ++m * ++n;
    for(i = 0; i < m; ++i) {
        price += (i + 1) * items[i];
    }

    return price;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> values, long long expected) {
    cout << "Values:" << endl;
    printMatrix(values);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSpending(values) << endl;

    cout << endl;
}

int main() {
    test({{8, 5, 2}, {6, 4, 1}, {9, 7, 3}}, 285);
    test({{10, 8, 6, 4, 2}, {9, 7, 5, 3, 2}}, 386);
    test({{5, 4, 3, 2, 1}}, 55);
    test({{7, 3}, {9, 1}}, 64);
    test({{4, 4, 4}, {3, 3, 3}, {2, 2, 2}}, 153);

    return 0;
}
