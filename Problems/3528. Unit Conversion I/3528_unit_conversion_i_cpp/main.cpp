#include <iostream>
#include <vector>

using namespace std;

vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
    int n = conversions.size();
    vector<int> unitConversions(++n, 1);
    vector<vector<pair<int, int>>> graph(n--);
    vector<int> traversal(1, 0);
    int unit;

    while(--n > -1) {
        graph[conversions[n][0]].push_back({conversions[n][1], conversions[n][2]});
    }

    while(!traversal.empty()) {
        unit = traversal.back();
        traversal.pop_back();

        for(n = graph[unit].size() - 1; n > -1; --n) {
            unitConversions[graph[unit][n].first] = ((long)unitConversions[unit] * graph[unit][n].second) % 1000000007;
            traversal.push_back(graph[unit][n].first);
        }
    }

    return unitConversions;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> conversions, vector<int> expected) {
    cout << "Conversions: ";
    for(vector<int> conversion : conversions) {
        cout << "[" << conversion[0] << ", " << conversion[1] << ", " << conversion[2] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(baseUnitConversions(conversions));

    cout << endl;
}

int main() {
    test({{0, 1, 2}, {1, 2, 3}}, {1, 2, 6});
    test({{0, 1, 2}, {0, 2, 3}, {1, 3, 4}, {1, 4, 5}, {2, 5, 2}, {4, 6, 3}, {5, 7, 4}}, {1, 2, 3, 8, 10, 6, 30, 24});
    test({{0, 1, 1000000000}, {1, 2, 1000000000}}, {1, 1000000000, 49});
    test({{0, 1, 5}}, {1, 5});
    test({{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}}, {1, 1, 1, 1, 1});
    return 0;
}
