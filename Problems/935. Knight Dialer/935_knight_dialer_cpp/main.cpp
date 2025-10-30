#include <iostream>
#include <vector>

using namespace std;

int knightDialer(vector<vector<short>>& previous, vector<int>& dials, vector<int>& nextDials, int& n) {
    if(--n < 1) {
        for(short i = 0; i < 10; ++i) {
            n = (n + dials[i]) % 1000000007;
        }

        return n;
    }

    short j;
    for(short i = 0; i < 10; ++i) {
        nextDials[i] = 0;

        for(j = previous[i].size() - 1; j > -1; --j) {
            nextDials[i] = (nextDials[i] + dials[previous[i][j]]) % 1000000007;
        }
    }

    return knightDialer(previous, nextDials, dials, n);
}

int knightDialer(int n) {
    vector<int> dials1(10, 1);
    vector<int> dials2(10);
    vector<vector<short>> previous = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    return knightDialer(previous, dials1, dials2, n);
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << knightDialer(n) << endl;

    cout << endl;
}

int main() {
    test(1, 10);
    test(2, 20);
    test(10, 14912);
    test(100, 540641702);
    test(1000, 88106097);
    test(3131, 136006598);
    test(5000, 406880451);

    return 0;
}
