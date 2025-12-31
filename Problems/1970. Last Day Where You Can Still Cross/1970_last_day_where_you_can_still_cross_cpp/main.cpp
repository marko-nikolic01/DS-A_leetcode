#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    int lastDay = INT_MAX;
    vector<vector<int>> lastDays(row, vector<int>(col, INT_MAX));
    priority_queue<tuple<int, short, short>> traversal;
    int day;
    int x;
    short y;

    int i = cells.size();
    for(x = cells.size() - 1; x > -1; --x) {
        lastDays[--cells[x][0]][--cells[x][1]] = x;
    }

    --row;
    for(x = col - 1; x > -1; --x) {
        traversal.push({lastDays[row][x], row, x});
        lastDays[row][x] = -1;
    }

    while(!traversal.empty()) {
        day = get<0>(traversal.top());
        x = get<1>(traversal.top());
        y = get<2>(traversal.top());
        traversal.pop();

        if(day < lastDay) {
            lastDay = day;
        }

        if(x < 1) {
            break;
        } else if(lastDays[x - 1][y] > 0) {
            traversal.push({lastDays[--x][y], x, y});
            lastDays[x++][y] = -1;
        }

        if(x < row && lastDays[x + 1][y] > 0) {
            traversal.push({lastDays[++x][y], x, y});
            lastDays[x--][y] = -1;
        }

        if(y > 0 && lastDays[x][y - 1] > 0) {
            traversal.push({lastDays[x][--y], x, y});
            lastDays[x][y++] = -1;
        }

        if(++y < col && lastDays[x][y] > 0) {
            traversal.push({lastDays[x][y], x, y});
            lastDays[x][y] = -1;
        }
    }

    return lastDay;
}

void test(int row, int col, vector<vector<int>> cells, int expected) {
    cout << "Rows: " << row << endl;

    cout << "Columns: " << col << endl;

    cout << "Cells: ";
    for(vector<int> cell : cells) {
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << latestDayToCross(row, col, cells) << endl;

    cout << endl;
}

int main() {
    test(2, 2, {{1, 1}, {2, 1}, {1, 2}, {2, 2}}, 2);
    test(2, 2, {{1, 1}, {1, 2}, {2, 1}, {2, 2}}, 1);
    test(3, 3, {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}}, 3);
    test(3, 2, {{1, 1}, {2, 1}, {3, 1}, {1, 2}, {2, 2}, {3, 2}}, 3);
    test(4, 4, {{1, 1}, {2, 1}, {3, 1}, {4, 1}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4}}, 12);

    return 0;
}
