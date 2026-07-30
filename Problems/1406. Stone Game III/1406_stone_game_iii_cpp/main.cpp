#include <iostream>
#include <vector>

using namespace std;

string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    int dp[4] = {0, 0, 0, 0};
    string s[] = {"Bob", "Tie", "Alice"};

    for(int i = n - 1; i > -1; --i) {
        dp[i & 3] = stoneValue[i] - dp[(i + 1) & 3];

        if(i + 2 <= n) {
            dp[i & 3] = max(dp[i & 3], stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) & 3]);
        }

        if (i + 3 <= n) {
            dp[i & 3] = max(dp[i & 3], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) & 3]);
        }
    }

    return s[(dp[0] > 0) - (dp[0] < 0) + 1];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> stoneValue, string expected) {
    cout << "Stone values: ";
    printArray(stoneValue);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << stoneGameIII(stoneValue) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 7}, "Bob");
    test({1, 2, 3, -9}, "Alice");
    test({1, 2, 3, 6}, "Tie");
    test({-1, -2, -3}, "Tie");
    test({5}, "Alice");

    return 0;
}
