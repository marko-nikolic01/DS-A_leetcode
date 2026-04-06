#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int distance = 0;
    unordered_map<int, unordered_set<int>> obstacle;
    int x = 0;
    int y = 0;
    short dx = 0;
    short dy = 1;
    short dTemp;

    short i;
    for(i = obstacles.size() - 1; i > -1; --i) {
        obstacle[obstacles[i][0]].insert(obstacles[i][1]);
    }

    short n = commands.size();
    while(++i < n) {
        if(commands[i] < -1) {
            dTemp = dx;
            dx = dx != 0 ? 0 : (dy < 0 ? 1 : -1);
            dy = dy != 0 ? 0 : (dTemp < 0 ? -1 : 1);
        } else if(commands[i] < 0) {
            dTemp = dx;
            dx = dx != 0 ? 0 : (dy < 0 ? -1 : 1);
            dy = dy != 0 ? 0 : (dTemp < 0 ? 1 : -1);
        } else {
            while(--commands[i] > -1 && (obstacle.find(x + dx) == obstacle.end() || obstacle[x + dx].find(y + dy) == obstacle[x + dx].end())) {
                x += dx;
                y += dy;
            }

            if(x * x + y * y > distance) {
                distance = x * x + y * y;
            }
        }
    }

    return distance;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> commands, vector<vector<int>> obstacles, int expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Obstacles: ";
    for(vector<int> obstacle : obstacles) {
        cout << "[" << obstacle[0] << ", " << obstacle[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << robotSim(commands, obstacles) << endl;

    cout << endl;
}

int main() {
    test({4, -1, 3}, {}, 25);
    test({4, -1, 4, -2, 4}, {{2, 4}}, 65);
    test({6, -1, -1, 6}, {{0, 0}}, 36);
    test({7, -2, -2, 7, 5}, {}, 49);
    test({3, -1, 3, -1, 3, -1, 3}, {}, 18);

    return 0;
}
