#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    short edges = 0;
    unordered_map<int, short> bricks;
    short brick;

    short j;
    short n = wall.size();
    for(short i = n - 1; i > -1; --i) {
        brick = 0;

        for(j = wall[i].size() - 1; j > 0; --j) {
            brick += wall[i][j];
            ++bricks[brick];
        }
    }


    for(unordered_map<int, short>::iterator it = bricks.begin(); it != bricks.end(); ++it) {
        if(it->second > edges) {
            edges = it->second;
        }
    }

    return n - edges;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> wall, int expected) {
    cout << "Wall:" << endl;
    printMatrix(wall);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << leastBricks(wall) << endl;

    cout << endl;
}

int main() {
    test({{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}}, 2);
    test({{1}, {1}, {1}}, 3);
    test({{5}}, 1);
    test({{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, 0);
    test({{1, 1}, {2}, {1, 1}, {1, 1}}, 1);

    return 0;
}
