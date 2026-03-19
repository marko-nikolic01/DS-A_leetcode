#include <iostream>
#include <vector>

using namespace std;

int numWays(vector<int>& ways, int& steps, int& n) {
    if(--steps < 0) {
        return ways[0];
    }

    int previous = 0;
    int temp;

    short i;
    for(i = n - 1; i > -1; --i) {
        temp = ways[i];
        ways[i] = (ways[i] + previous) % 1000000007;
        previous = temp;

        if(i > 0) {
            ways[i] = (ways[i] + ways[i - 1]) % 1000000007;
        }
    }

    return numWays(ways, steps, n);
}

int numWays(int steps, int arrLen) {
    if(steps < arrLen) {
        arrLen = steps + 1;
    }

    vector<int> ways(arrLen, 0);

    ++ways[0];

    return numWays(ways, steps, arrLen);
}

void test(int steps, int arrLen, int expected) {
    cout << "Steps: " << steps << endl;

    cout << "Array length: " << arrLen << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numWays(steps, arrLen) << endl;

    cout << endl;
}

int main() {
    test(3, 2, 4);
    test(2, 4, 2);
    test(4, 2, 8);
    test(1, 1, 1);
    test(500, 1000000, 374847123);

    return 0;
}
