#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> balls;
    unordered_map<int, int> colors;

    int distinctColors = 0;

    limit = queries.size();
    vector<int> result(limit);

    for(int i = 0; i < limit; ++i) {
        if(--colors[balls[queries[i][0]]] == 0) {
            --distinctColors;
        }

        balls[queries[i][0]] = queries[i][1];

        if(++colors[queries[i][1]] < 2) {
            ++distinctColors;
        }

        result[i] = distinctColors;
    }

    return result;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int limit, vector<vector<int>> queries, vector<int> expected) {
    cout << "Limit: " << limit << endl;;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << " " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(queryResults(limit, queries));

    cout << endl;
}

int main() {
    vector<vector<int>> queries1 = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
    vector<int> expected1 = {1, 2, 2, 3};
    test(4, queries1, expected1);

    vector<vector<int>> queries2 = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
    vector<int> expected2 = {1, 2, 2, 3, 4};
    test(4, queries2, expected2);

    vector<vector<int>> queries3 = {{0, 10}, {1, 20}, {2, 10}, {3, 30}, {0, 20}};
    vector<int> expected3 = {1, 2, 2, 3, 3};
    test(5, queries3, expected3);

    vector<vector<int>> queries4 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {1, 2}};
    vector<int> expected4 = {1, 2, 3, 4, 3};
    test(4, queries4, expected4);

    vector<vector<int>> queries5 = {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}};
    vector<int> expected5 = {1, 1, 1, 1, 1};
    test(4, queries5, expected5);

    return 0;
}
