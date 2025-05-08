#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minTimeToReach(vector<vector<int>>& moveTime) {
    short m = moveTime.size();
    short n = moveTime[0].size() - 1;
    if(--m < 1 && n < 1) {
        return 0;
    }

    auto cmp = [](const tuple<int, short, short, bool>& a, const tuple<int, short, short, bool>& b) {
        return get<0>(a) > get<0>(b) || (get<0>(a) == get<0>(b) && get<3>(a));
    };
    priority_queue<tuple<int, short, short, bool>, vector<tuple<int, short, short, bool>>, decltype(cmp)> traversal(cmp);
    traversal.push({0, 0, 0, false});
    moveTime[0][0] = -1;

    int time;
    int currentTime;
    short timeIncrement;
    bool nextTimeIncrement;
    short x;
    short y;

    while(true) {
        nextTimeIncrement = get<3>(traversal.top());
        timeIncrement = nextTimeIncrement ? 2 : 1;
        nextTimeIncrement = !nextTimeIncrement;

        currentTime = get<0>(traversal.top()) + timeIncrement;
        x = get<1>(traversal.top());
        y = get<2>(traversal.top());
        traversal.pop();

        if(x > 0 && moveTime[x - 1][y] > -1) {
            traversal.push({max(currentTime, moveTime[x - 1][y] + timeIncrement), x - 1, y, nextTimeIncrement});
            moveTime[x - 1][y] = -1;
        }

        if(x < m && moveTime[x + 1][y] > -1) {
            if(x + 1 == m && y == n) {
                return max(currentTime, moveTime[m][n] + timeIncrement);
            }

            traversal.push({max(currentTime, moveTime[x + 1][y] + timeIncrement), x + 1, y, nextTimeIncrement});
            moveTime[x + 1][y] = -1;
        }

        if(y > 0 && moveTime[x][y - 1] > -1) {
            traversal.push({max(currentTime, moveTime[x][y - 1] + timeIncrement), x, y - 1, nextTimeIncrement});
            moveTime[x][y - 1] = -1;
        }

        if(y < n && moveTime[x][++y] > -1) {
            if(y == n && x == m) {
                return max(currentTime, moveTime[m][n] + timeIncrement);
            }

            traversal.push({max(currentTime, moveTime[x][y] + timeIncrement), x, y, nextTimeIncrement});
            moveTime[x][y] = -1;
        }
    }

    return 0;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> moveTime, int expected) {
    cout << "Move times:" << endl;
    printMatrix(moveTime);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minTimeToReach(moveTime) << endl;

    cout << endl;
}

int main() {
    test({{0, 4}, {4, 4}}, 7);
    test({{0, 0, 0, 0}, {0, 0, 0, 0}}, 6);
    test({{0, 1}, {1, 2}}, 4);
    test({{0, 2, 4}, {1, 3, 5}, {2, 6, 6}}, 8);
    test({{0, 100}, {100, 0}}, 103);

    return 0;
}
