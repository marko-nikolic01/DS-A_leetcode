#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int nHeights = heights.size();
    vector<pair<int, int>> sortedHeights(nHeights);

    for (int i = --nHeights; i > -1; --i) {
        sortedHeights[i] = {i, heights[i]};
    }

    std::sort(sortedHeights.begin(), sortedHeights.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int nQueries = queries.size();
    vector<int> result(nQueries);

    for(--nQueries; nQueries > -1; --nQueries) {
        if(queries[nQueries][0] > queries[nQueries][1]) {
            int temp = queries[nQueries][0];
            queries[nQueries][0] = queries[nQueries][1];
            queries[nQueries][1] = temp;
        }

        if(heights[queries[nQueries][0]] < heights[queries[nQueries][1]] || queries[nQueries][0] == queries[nQueries][1]) {
            result[nQueries] = queries[nQueries][1];
        } else {
            int iHeight = 50000;
            for(int i = nHeights; i > -1 && sortedHeights[i].second > heights[queries[nQueries][0]]; --i) {
                if(sortedHeights[i].first > queries[nQueries][1] && sortedHeights[i].first < iHeight) {
                    iHeight = sortedHeights[i].first;
                }
            }
            result[nQueries] = iHeight == 50000 ? -1 : iHeight;
        }
    }

    return result;
}

void runTest(vector<int> heights, vector<vector<int>> queries, vector<int> expected) {
    cout << "Heights: ";
    for (int height : heights) {
        cout << height << " ";
    }
    cout << endl;

    cout << "Queries: ";
    for (vector<int> query : queries) {
        cout << "[" << query[0] << "," << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : leftmostBuildingQueries(heights, queries)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> heights1 = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries1 = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    vector<int> expected1 = {2, 5, -1, 5, 2};
    runTest(heights1, queries1, expected1);

    vector<int> heights2 = {5, 3, 8, 2, 6, 1, 4, 6};
    vector<vector<int>> queries2 = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
    vector<int> expected2 = {7, 6, -1, 4, 6};
    runTest(heights2, queries2, expected2);

    vector<int> heights3 = {1, 2, 3, 4, 5};
    vector<vector<int>> queries3 = {{0, 4}, {1, 3}, {2, 2}};
    vector<int> expected3 = {4, 3, 2};
    runTest(heights3, queries3, expected3);

    vector<int> heights4 = {10, 20, 30, 40, 50};
    vector<vector<int>> queries4 = {{0, 1}, {1, 3}, {3, 4}};
    vector<int> expected4 = {1, 3, 4};
    runTest(heights4, queries4, expected4);

    vector<int> heights5 = {9, 8, 7, 6, 5};
    vector<vector<int>> queries5 = {{0, 4}, {2, 3}, {1, 2}};
    vector<int> expected5 = {-1, -1, -1};
    runTest(heights5, queries5, expected5);

    vector<int> heights6 = {4, 7, 3, 8, 2};
    vector<vector<int>> queries6 = {{0, 3}, {1, 4}, {2, 3}, {0, 0}};
    vector<int> expected6 = {3, -1, 3, 0};
    runTest(heights6, queries6, expected6);

    return 0;
}
