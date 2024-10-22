#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();

    vector<vector<char>> rotatedBox(n--, vector<char> (m--, '.'));

    for(int i = m; i > -1; --i) {
        int bottom = n;

        for(int j = n; j > -1; --j) {
            if(box[i][j] == '#') {
                rotatedBox[bottom--][m - i] = '#';
            } else if(box[i][j] == '*') {
                rotatedBox[j][m - i] = '*';
                bottom = j - 1;
            }
        }
    }

    return rotatedBox;
}

void printBox(const vector<vector<char>>& box) {
    for (const auto& row : box) {
        for (char c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }
}

void testCase(vector<vector<char>> box, vector<vector<char>> expected) {
    cout << "Box:" << endl;
    printBox(box);

    cout << "Expected:" << endl;
    printBox(expected);

    cout << "Result:" << endl;
    printBox(rotateTheBox(box));

    cout << endl;
}

int main() {
    vector<vector<char>> box1 = {{'#', '#', '*', '.', '.'},
                                 {'.', '#', '#', '*', '.'}};
    vector<vector<char>> expected1 = {{'.', '#'},
                                      {'#', '#'},
                                      {'#', '*'},
                                      {'*', '.'},
                                      {'.', '.'}};
    testCase(box1, expected1);

    vector<vector<char>> box2 = {{'#', '.', '*', '#', '#'},
                                 {'#', '#', '*', '.', '.'}};
    vector<vector<char>> expected2 = {{'#', '.'},
                                      {'#', '#'},
                                      {'*', '*'},
                                      {'.', '#'},
                                      {'.', '#'}};
    testCase(box2, expected2);

    vector<vector<char>> box3 = {{'#', '#', '#', '.'},
                                 {'.', '.', '#', '#'}};
    vector<vector<char>> expected3 = {{'.', '.'},
                                      {'.', '#'},
                                      {'#', '#'},
                                      {'#', '#'}};
    testCase(box3, expected3);

    vector<vector<char>> box4 = {{'.', '*', '.', '.'},
                                 {'.', '*', '.', '.'}};
    vector<vector<char>> expected4 = {{'.', '.'},
                                      {'*', '*'},
                                      {'.', '.'},
                                      {'.', '.'}};
    testCase(box4, expected4);

    vector<vector<char>> box5 = {{'*', '#', '.', '#', '*'}};
    vector<vector<char>> expected5 = {{'*'},
                                      {'.'},
                                      {'#'},
                                      {'#'},
                                      {'*'}};
    testCase(box5, expected5);

    vector<vector<char>> box6 = {{'.', '.', '.', '.'},
                                 {'.', '.', '.', '.'}};
    vector<vector<char>> expected6 = {{'.', '.'},
                                      {'.', '.'},
                                      {'.', '.'},
                                      {'.', '.'}};
    testCase(box6, expected6);

    return 0;
}
