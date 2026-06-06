#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    int left = 0;
    int right;
    int middle;

    sort(items.begin(), items.end());

    int i;
    int n = items.size() - 1;
    for(i = 0; i <= n; ++i) {
        if(items[i][1] > left) {
            left = items[i][1];
        }

        items[i][1] = left;
    }

    for(i = queries.size() - 1; i > -1; --i) {
        if(items[0][0] > queries[i]) {
            queries[i] = 0;
        } else {
            left = 0;
            right = n;

            while(true) {
                middle = (left + right) >> 1;

                if(items[middle][0] > queries[i]) {
                    right = --middle;
                } else if(middle < n && items[middle + 1][0] <= queries[i]) {
                    left = ++middle;
                } else {
                    queries[i] = items[middle][1];

                    break;
                }
            }
        }
    }

    return queries;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> items, vector<int> queries, vector<int> expected) {
    cout << "Items: ";
    for(vector<int> item : items) {
        cout << "[" << item[0] << ", " << item[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maximumBeauty(items, queries));

    cout << endl;
}

int main() {
    test({{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}}, {1, 2, 3, 4, 5, 6}, {2, 4, 5, 5, 6, 6});
    test({{1, 2}, {1, 2}, {1, 3}, {1, 4}}, {1}, {4});
    test({{10, 1000}}, {5}, {0});
    test({{5, 10}, {10, 20}, {15, 30}}, {1, 5, 7, 10, 14, 15, 20}, {0, 10, 10, 20, 20, 30, 30});
    test({{2, 5}, {4, 1}, {6, 10}, {8, 7}}, {2, 4, 6, 8}, {5, 5, 10, 10});
    test({{1, 10}, {3, 30}, {5, 50}, {7, 70}, {9, 90}}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {0, 10, 10, 30, 30, 50, 50, 70, 70, 90, 90});

    return 0;
}
