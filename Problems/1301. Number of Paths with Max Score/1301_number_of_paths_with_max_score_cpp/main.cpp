#include <iostream>
#include <vector>

using namespace std;

vector<int> pathsWithMaxScore(vector<string>& board) {
    vector<vector<int>> dirs {{1, 0}, {0, 1}, {1, 1}};
    auto sz = board.size();
    vector<vector<int>> score(sz + 1, vector<int>(sz + 1)), paths(sz + 1, vector<int>(sz + 1));
    board[0][0] = board[sz - 1][sz - 1] = '0';
    paths[0][0] = 1;
    for (int i = 1; i <= sz; ++i) {
        for (int j = 1; j <= sz; ++j) {
            if (board[i - 1][j - 1] == 'X')
                continue;
            for (auto d : dirs) {
                auto i1 = i - d[0], j1 = j - d[1];
                auto val = score[i1][j1] + (board[i - 1][j - 1] - '0');
                if (score[i][j] <= val && paths[i1][j1] > 0) {
                    paths[i][j] = ((score[i][j] == val ? paths[i][j] : 0) + paths[i1][j1]) % 1000000007;
                    score[i][j] = val;
                }
            }
        }
    }
    return {paths[sz][sz] ? score[sz][sz] : 0, paths[sz][sz]};
}

void test(vector<string> board, vector<int> expected) {
    cout << "Board:" << endl;
    for (string row : board) {
        cout << row << endl;
    }

    cout << "Expected: " << "[" << expected[0] << "," << expected[1] << "]" << endl;

    vector<int> result = pathsWithMaxScore(board);
    cout << "Result: " << "[" << result[0] << "," << result[1] << "]" << endl;

    cout << endl;
}

int main() {
    test({"E23", "2X2", "12S"}, {7, 1});
    test({"E12", "1X1", "21S"}, {4, 2});
    test({"E11", "XXX", "11S"}, {0, 0});
    test({"E11", "2X1", "31S"}, {6, 1});
    test({"E11", "1X1", "11S"}, {3, 2});

    return 0;
}
