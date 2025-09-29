#include <iostream>
#include <vector>

using namespace std;

int minScoreTriangulation(vector<int>& values) {
    short n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    short j;
    short k;
    short m;
    short l;
    for(short i = 2; i < n; ++i){
        m = n - i;
        for(j = 0; j < m; ++j){
            l = i + j;
            dp[j][l] = 2147483647;

            for(k = j + 1; k < l; ++k){
                dp[j][l] = min(dp[j][l], dp[j][k] + dp[k][l] + values[j] * values[k] * values[l]);
            }
        }
    }

    return dp[0][--n];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> values, int expected) {
    cout << "Values: ";
    printArray(values);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minScoreTriangulation(values) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, 6);
    test({3, 7, 4, 5}, 144);
    test({1, 3, 1, 4, 1, 5}, 13);
    test({2, 2, 2, 2}, 16);
    test({5, 6, 7, 8, 9}, 850);

    return 0;
}
