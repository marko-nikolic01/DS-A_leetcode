#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double new21Game(int n, int k, int maxPts) {
    vector<double> dp(n + 1);
    dp[0] = 1;
    double s = k > 0 ? 1 : 0;

    for(int i = 1; i <= n; ++i) {
        dp[i] = s / maxPts;

        if(i < k) {
            s += dp[i];
        }

        if(i - maxPts >= 0 && i - maxPts < k) {
            s -= dp[i - maxPts];
        }
    }

    return accumulate(dp.begin() + k, dp.end(), 0.0);
}

void test(int n, int k, int maxPts, double expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Maximum points: " << maxPts << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << new21Game(n, k, maxPts) << endl;

    cout << endl;
}


int main() {
    test(10, 1, 10, 1);
    test(6, 1, 10, 0.6);
    test(21, 17, 10, 0.732778);
    test(5, 0, 2, 1);
    test(20, 10, 10, 1);

    return 0;
}
