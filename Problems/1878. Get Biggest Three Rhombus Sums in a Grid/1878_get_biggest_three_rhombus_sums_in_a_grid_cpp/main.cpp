#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct Answer {
    array<int, 3> result{};

    void put(int x) {
        if(x > result[0]) {
            tie(result[0], result[1], result[2]) = tuple{x, result[0], result[1]};
        } else if(x != result[0] && x > result[1]) {
            tie(result[1], result[2]) = tuple{x, result[1]};
        } else if(x != result[0] && x != result[1] && x > result[2]) {
            result[2] = x;
        }
    }

    vector<int> get() const {
        vector<int> results;

        for(short i = 0; i < 3; ++i) {
            if(result[i] > 0) {
                results.push_back(result[i]);
            } else {
                break;
            }
        }

        return results;
    }
};

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    Answer result;
    short m = grid.size();
    short n = grid[0].size();
    vector<vector<int>> sum1(m + 1, vector<int>(n + 2));
    vector<vector<int>> sum2(m + 1, vector<int>(n + 2));
    int ux;
    int uy;
    int dx;
    int dy;
    int lx;
    int ly;
    int rx;
    int ry;

    short i;
    short j;
    for(i = 1; i <= m; ++i) {
        for(j = 1; j <= n; ++j) {
            sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
            sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
        }
    }


    short k;
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            result.put(grid[i][j]);

            for(k = i + 2; k < m; k += 2) {
                ux = i;
                uy = j;
                dx = k;
                dy = j;
                lx = (i + k) >> 1;
                ly = j - ((k - i) >> 1);
                rx = (i + k) >> 1;
                ry = j + ((k - i) >> 1);

                if(ly < 0 || ry >= n) {
                    break;
                }

                result.put((sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) + (sum1[rx + 1][ry + 1] - sum1[ux][uy]) + (sum1[dx + 1][dy + 1] - sum1[lx][ly]) + (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) - (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry]));
            }
        }
    }

    return result.get();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, vector<int> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result:   ";
    printArray(getBiggestThree(grid));

    cout << endl;
}

int main() {
    test({{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}}, {228, 216, 211});
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {20, 9, 8});
    test({{7, 7, 7}}, {7});
    test({{1}}, {1});
    test({{1, 2}, {3, 4}}, {4, 3, 2});

    return 0;
}
