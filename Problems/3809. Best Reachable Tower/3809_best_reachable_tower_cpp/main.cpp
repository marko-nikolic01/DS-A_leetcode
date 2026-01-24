#include <iostream>
#include <vector>

using namespace std;

vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
    vector<int> tower(2, -1);
    int quality = -1;

    for(int i = towers.size() - 1; i > -1; --i) {
        if(abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1]) <= radius && (towers[i][2] > quality || (towers[i][2] == quality && (towers[i][0] < tower[0] || (towers[i][0] == tower[0] && towers[i][1] < tower[1]))))) {
            tower[0] = towers[i][0];
            tower[1] = towers[i][1];
            quality = towers[i][2];
        }
    }

    return tower;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> towers, vector<int> center, int radius, vector<int> expected) {
    cout << "Towers: ";
    for(vector<int> tower : towers) {
        cout << "[" << tower[0] << ", " << tower[1] << ", " << tower[2] << "] ";
    }
    cout << endl;

    cout << "Center: ";
    printArray(center);

    cout << "Radius: " << radius << endl;

    cout << "expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(bestTower(towers, center, radius));

    cout << endl;
}

int main() {
    test({{1, 2, 5}, {2, 1, 7}, {3, 1, 9}}, {1, 1}, 2, {3, 1});
    test({{1, 3, 4}, {2, 2, 4}, {4, 4, 7}}, {0, 0}, 5, {1, 3});
    test({{5, 6, 8}, {0, 3, 5}}, {1, 2}, 1, {-1, -1});
    test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0}, 0, {0, 0});
    test({{2, 2, 10}, {1, 1, 10}, {1, 2, 10}}, {0, 0}, 10, {1, 1});

    return 0;
}
