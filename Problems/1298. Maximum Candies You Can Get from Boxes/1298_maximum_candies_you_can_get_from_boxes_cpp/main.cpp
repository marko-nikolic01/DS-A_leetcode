#include <iostream>
#include <vector>

using namespace std;

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    short box = 0;

    short i;
    int n = initialBoxes.size();
    for(i = 0; i < n; ++i) {
        if(status[initialBoxes[i]] > 0) {
            initialBoxes[box++] = initialBoxes[i];
            status[initialBoxes[i]] = 0;
        } else {
            status[initialBoxes[i]] = -1;
        }
    }
    initialBoxes.resize(box);

    n = 0;

    while(!initialBoxes.empty()) {
        box = initialBoxes.back();
        initialBoxes.pop_back();

        n += candies[box];

        for(i = keys[box].size() - 1; i > -1; --i) {
            if(status[keys[box][i]] < 0) {
                initialBoxes.push_back(keys[box][i]);
                status[keys[box][i]] = 0;
            } else {
                status[keys[box][i]] = 1;
            }
        }

        for(i = containedBoxes[box].size() - 1; i > -1; --i) {
            if(status[containedBoxes[box][i]] > 0) {
                initialBoxes.push_back(containedBoxes[box][i]);
                status[containedBoxes[box][i]] = 0;
            } else {
                status[containedBoxes[box][i]] = -1;
            }
        }
    }

    return n;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int>& status, vector<int> candies, vector<vector<int>> keys, vector<vector<int>> containedBoxes, vector<int> initialBoxes, int expected) {
    cout << "Statuses: ";
    printArray(status);

    cout << "Candies: ";
    printArray(candies);

    cout << "Keys: ";
    for(vector<int> key : keys) {
        cout << "[";
        for(int i = 0; i < key.size(); ++i) {
            cout << key[i];
            if(i < key.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Contained boxes: ";
    for(vector<int> containedBox : containedBoxes) {
        cout << "[";
        for(int i = 0; i < containedBox.size(); ++i) {
            cout << containedBox[i];
            if(i < containedBox.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Initial boxes: ";
    printArray(initialBoxes);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxCandies(status, candies, keys, containedBoxes, initialBoxes) << endl;

    cout << endl;
}

int main() {
    vector<int> status1 = {1, 0, 1, 0};
    vector<int> candies1 = {7, 5, 4, 100};
    vector<vector<int>> keys1 = {{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes1 = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes1 = {0};
    int expected1 = 16;
    test(status1, candies1, keys1, containedBoxes1, initialBoxes1, expected1);

    vector<int> status2 = {1, 0, 0, 0, 0, 0};
    vector<int> candies2 = {1, 1, 1, 1, 1, 1};
    vector<vector<int>> keys2 = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    vector<vector<int>> containedBoxes2 = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    vector<int> initialBoxes2 = {0};
    int expected2 = 6;
    test(status2, candies2, keys2, containedBoxes2, initialBoxes2, expected2);

    vector<int> status3 = {1, 0, 0};
    vector<int> candies3 = {10, 20, 30};
    vector<vector<int>> keys3 = {{}, {}, {}};
    vector<vector<int>> containedBoxes3 = {{1, 2}, {}, {}};
    vector<int> initialBoxes3 = {0};
    int expected3 = 10;
    test(status3, candies3, keys3, containedBoxes3, initialBoxes3, expected3);

    vector<int> status4 = {1, 1, 1};
    vector<int> candies4 = {5, 10, 15};
    vector<vector<int>> keys4 = {{}, {}, {}};
    vector<vector<int>> containedBoxes4 = {{}, {}, {}};
    vector<int> initialBoxes4 = {};
    int expected4 = 0;
    test(status4, candies4, keys4, containedBoxes4, initialBoxes4, expected4);

    vector<int> status5 = {0, 0};
    vector<int> candies5 = {100, 200};
    vector<vector<int>> keys5 = {{}, {}};
    vector<vector<int>> containedBoxes5 = {{1}, {0}};
    vector<int> initialBoxes5 = {0};
    int expected5 = 0;
    test(status5, candies5, keys5, containedBoxes5, initialBoxes5, expected5);

    return 0;
}
