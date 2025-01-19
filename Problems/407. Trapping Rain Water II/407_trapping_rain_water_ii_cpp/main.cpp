#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
    int water = 0;

    auto comparator = [](const tuple<int, short, short>& a, const tuple<int, short, short>& b) {
        return get<0>(a) > get<0>(b);
    };
    priority_queue<tuple<int, short, short>, vector<tuple<int, short, short>>, decltype(comparator)> border(comparator);

    short m = heightMap.size();
    short n = heightMap[0].size();

    vector<vector<bool>> visited(m--, vector<bool>(n--, false));

    for(short i = m; i > 0; --i) {
        border.push({heightMap[i][0], i, 0});
        border.push({heightMap[i][n], i, n});

        visited[i][0] = true;
        visited[i][n] = true;
    }

    for(short i = n; i > -1; --i) {
        border.push({heightMap[0][i], 0, i});
        border.push({heightMap[m][i], m, i});

        visited[0][i] = true;
        visited[m][i] = true;
    }

    int height;
    short x;
    short y;

    while(!border.empty()) {
        height = get<0>(border.top());
        x = get<1>(border.top());
        y = get<2>(border.top());
        border.pop();

        if(x > 0 && !visited[x - 1][y]) {
            visited[x - 1][y] = true;

            if(heightMap[x - 1][y] < height) {
                water += height - heightMap[x - 1][y];

                border.push({height, x - 1, y});
            } else {
                border.push({heightMap[x - 1][y], x - 1, y});
            }
        }

        if(x < m && !visited[x + 1][y]) {
            visited[x + 1][y] = true;

            if(heightMap[x + 1][y] < height) {
                water += height - heightMap[x + 1][y];

                border.push({height, x + 1, y});
            } else {
                border.push({heightMap[x + 1][y], x + 1, y});
            }
        }

        if(y > 0 && !visited[x][y - 1]) {
            visited[x][y - 1] = true;

            if(heightMap[x][y - 1] < height) {
                water += height - heightMap[x][y - 1];

                border.push({height, x, y - 1});
            } else {
                border.push({heightMap[x][y - 1], x, y - 1});
            }
        }

        if(y < n && !visited[x][y + 1]) {
            visited[x][y + 1] = true;

            if(heightMap[x][y + 1] < height) {
                water += height - heightMap[x][y + 1];

                border.push({height, x, y + 1});
            } else {
                border.push({heightMap[x][y + 1], x, y + 1});
            }
        }
    }

    return water;
}

void printMatrix(vector<vector<int>>& matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void testTrapRainWater(vector<vector<int>> heightMap, int expected) {
    cout << "Height map:" << endl;
    printMatrix(heightMap);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << trapRainWater(heightMap) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> test1 = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    int expected1 = 4;
    testTrapRainWater(test1, expected1);

    vector<vector<int>> test2 = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    int expected2 = 10;
    testTrapRainWater(test2, expected2);

    vector<vector<int>> test3 = {{1,2,3},{3,2,1},{2,3,4}};
    int expected3 = 0;
    testTrapRainWater(test3, expected3);

    vector<vector<int>> test4 = {{1,2,3,4},{2,3,4,5},{3,4,5,6}};
    int expected4 = 0;
    testTrapRainWater(test4, expected4);

    vector<vector<int>> test5 = {{5,4,3},{4,3,2},{3,2,1}};
    int expected5 = 0;
    testTrapRainWater(test5, expected5);

    return 0;
}
