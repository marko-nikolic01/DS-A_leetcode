#include <iostream>
#include <vector>

using namespace std;

int dieSimulator(int n, vector<int>& rollMax) {
    vector<vector<int>> rolls1(6, vector<int>(15, 0));
    vector<vector<int>> rolls2(6, vector<int>(15));
    vector<vector<int>>& rolls = rolls1;
    vector<vector<int>>& newRolls = rolls2;
    vector<vector<int>>& temp = rolls1;
    int roll;

    short i;
    short j;
    for(i = 0; i < 6; ++i) {
        rolls[i].assign(rollMax[i], 0);
        newRolls[i].assign(rollMax[i], 0);
        ++rolls[i][0];
    }

    while(--n > 0) {
        for(i = 0; i < 6; ++i) {
            for(j = rollMax[i] - 1; j > -1; --j) {
                newRolls[i][j] = 0;
            }
        }

        for(i = 0; i < 6; ++i) {
            for(j = 0; j < 6; ++j) {
                if(i == j) {
                    for(roll = rollMax[j] - 1; roll > 0; --roll) {
                        newRolls[i][roll] = (newRolls[i][roll] + rolls[i][roll - 1]) % 1000000007;
                    }
                } else {
                    for(roll = rollMax[j] - 1; roll > -1; --roll) {
                        newRolls[i][0] = (newRolls[i][0] + rolls[j][roll]) % 1000000007;
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
        for(j = rollMax[i] - 1; j > -1; --j) {
            roll = (roll + rolls[i][j]) % 1000000007;
        }
    }

    return roll;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<int> rollMax, int expected) {
    cout << "n: " << n << endl;

    cout << "Maximum consecutive rolls: ";
    printArray(rollMax);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << dieSimulator(n, rollMax) << endl;

    cout << endl;
}

int main() {
    test(2, {1, 1, 2, 2, 2, 3}, 34);
    test(2, {1, 1, 1, 1, 1, 1}, 30);
    test(3, {1, 1, 1, 2, 2, 3}, 181);
    test(3, {15, 15, 15, 15, 15, 15}, 216);
    test(3, {1, 1, 1, 1, 1, 1}, 150);

    return 0;
}
