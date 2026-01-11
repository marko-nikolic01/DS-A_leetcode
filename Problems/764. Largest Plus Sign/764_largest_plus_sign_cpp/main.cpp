#include <iostream>
#include <vector>

using namespace std;

int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    short plusSign = 0;
    vector<vector<short>> plusSigns(n, vector<short>(n, 1));
    short streak;

    short i;
    for(i = mines.size() - 1; i > -1; --i) {
        --plusSigns[mines[i][0]][mines[i][1]];
    }

    short j;
    for(i = --n; i > -1; --i) {
        streak = 0;

        for(j = 0; j <= n; ++j) {
            if(plusSigns[i][j] < 1) {
                streak = 0;
            } else {
                plusSigns[i][j] = ++streak;
            }
        }
    }

    for(i = n; i > -1; --i) {
        streak = 0;

        for(j = n; j > -1; --j) {
            if(plusSigns[i][j] < 1) {
                streak = 0;
            } else {
                if(++streak < plusSigns[i][j]) {
                    plusSigns[i][j] = streak;
                }
            }
        }
    }

    for(j = n; j > -1; --j) {
        streak = 0;

        for(i = 0; i <= n; ++i) {
            if(plusSigns[i][j] < 1) {
                streak = 0;
            } else {
                if(++streak < plusSigns[i][j]) {
                    plusSigns[i][j] = streak;
                }
            }
        }
    }

    for(j = n; j > -1; --j) {
        streak = 0;

        for(i = n; i > -1; --i) {
            if(plusSigns[i][j] < 1) {
                streak = 0;
            } else {
                if(++streak < plusSigns[i][j]) {
                    plusSigns[i][j] = streak;
                }

                if(plusSigns[i][j] > plusSign) {
                    plusSign = plusSigns[i][j];
                }
            }
        }
    }

    return plusSign;
}

void test(int n, vector<vector<int>> mines, int expected) {
    cout << "n: " << n << endl;

    cout << "Mines: ";
    for(vector<int> mine : mines) {
        cout << "[" << mine[0] << ", " << mine[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << orderOfLargestPlusSign(n, mines) << endl;

    cout << endl;
}

int main() {
    test(5, {{4, 2}}, 2);
    test(1, {{0, 0}}, 0);
    test(2, {{0, 0}, {0, 1}, {1, 0}}, 1);
    test(3, {}, 2);
    test(5, {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}}, 1);

    return 0;
}
