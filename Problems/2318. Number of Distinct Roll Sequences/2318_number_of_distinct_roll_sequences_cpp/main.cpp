#include <iostream>
#include <vector>

using namespace std;

int distinctSequences(int n) {
    if(--n < 1) {
        return 6;
    }

    vector<vector<bool>> allowedAdjacentRolls = {
        {false, true, true, true, true, true},
        {true, false, true, false, true, false},
        {true, true, false, true, true, false},
        {true, false, true, false, true, false},
        {true, true, true, true, false, true},
        {true, false, false, false, true, false}
    };
    vector<vector<int>> rolls1(6, vector<int>(6, 0));
    vector<vector<int>> rolls2(6, vector<int>(6));
    vector<vector<int>>& rolls = rolls1;
    vector<vector<int>>& newRolls = rolls2;
    vector<vector<int>>& temp = rolls1;
    int roll;

    short i;
    short j;
    short k;
    for(i = 0; i < 6; ++i) {
        for(j = 0; j < 6; ++j) {
            if(allowedAdjacentRolls[i][j]) {
                ++rolls[i][j];
            }
        }
    }

    for(i = 1; i < n; ++i) {
        for(j = 0; j < 6; ++j) {
            for(k = 0; k < 6; ++k) {
                newRolls[j][k] = 0;
            }
        }

        for(j = 0; j < 6; ++j) {
            for(k = 0; k < 6; ++k) {
                for(roll = 0; roll < 6; ++roll) {
                    if(allowedAdjacentRolls[roll][j] && roll != k) {
                        newRolls[roll][j] = (newRolls[roll][j] + rolls[j][k]) % 1000000007;
                    }
                }
            }
        }

        temp = newRolls;
        newRolls = rolls;
        rolls = temp;
    }

    roll = 0;

    for(i = 0; i < 6; ++i) {
        for(j = 0; j < 6; ++j) {
            roll = (roll + rolls[i][j]) % 1000000007;
        }
    }

    return roll;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << distinctSequences(n) << endl;

    cout << endl;
}

int main() {
    test(1, 6);
    test(2, 22);
    test(3, 66);
    test(4, 184);
    test(5, 516);

    return 0;
}
