#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> zigZagArrays(vector<vector<long>>& a, vector<vector<long>>& b) {
    int n = a.size();
    int m = b[0].size();
    vector<vector<long>> res(n, vector<long>(m, 0));

    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < a[0].size(); ++k) {
            long r = a[i][k];

            if(r != 0) {
                for(int j = 0; j < m; ++j) {
                    res[i][j] = (res[i][j] + r * b[k][j]) % 1000000007;
                }
            }
        }
    }

    return res;
}

vector<vector<long>> zigZagArrays(vector<vector<long>> base, long exp, vector<vector<long>> res) {
    while(exp > 0) {
        if(exp & 1) {
            res = zigZagArrays(res, base);
        }

        base = zigZagArrays(base, base);
        exp >>= 1;
    }

    return res;
}

int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;

    if(n == 1) {
        return m;
    }

    int size = m << 1;
    vector<vector<long>> u(size, vector<long>(size, 0));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < i; ++j) {
            u[i][j + m] = 1;
        }

        for(int j = i + 1; j < m; ++j) {
            u[i + m][j] = 1;
        }
    }

    vector<vector<long>> dp(1, vector<long>(size, 1));

    dp = zigZagArrays(move(u), --n, move(dp));

    long ans = 0;

    for(int i = 0; i < size; ++i) {
        ans = (ans + dp[0][i]) % 1000000007;
    }

    return ans;
}

void test(int n, int l, int r, int expected) {
    cout << "n: " << n << endl;

    cout << "l: " << l << endl;

    cout << "r: " << r << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result:   " << zigZagArrays(n, l, r) << endl;

    cout << endl;
}

int main() {
    test(3, 4, 5, 2);
    test(3, 1, 3, 10);
    test(4, 1, 2, 2);
    test(3, 1, 4, 28);
    test(5, 1, 3, 26);

    return 0;
}
