#include <iostream>
#include <vector>

using namespace std;

long magicalSum(long x, long y) {
    long result = 1;
    long current = x % 1000000007;

    while(y) {
        if(y & 1) {
            result = result * current % 1000000007;
        }

        y >>= 1;
        current = current * current % 1000000007;
    }

    return result;
};

int magicalSum(int m, int k, vector<int>& nums) {
    short n = nums.size();
    vector<long> factorial(++m, 1);
    vector<long> iFactorial(m , 1);
    vector<vector<long>> numsPower(n, vector<long>(m, 1));

    short i;
    for(i = 1; i < m; ++i) {
        factorial[i] = factorial[i - 1] * i % 1000000007;
    }

    for(i = 2; i < m; ++i) {
        iFactorial[i] = magicalSum(i, 1000000005);
    }

    for(i = 2; i < m; ++i) {
        iFactorial[i] = iFactorial[i - 1] * iFactorial[i] % 1000000007;
    }

    short j;
    for(i = 0; i < n; ++i) {
        for(j = 1; j < m; ++j) {
            numsPower[i][j] = numsPower[i][j - 1] * nums[i] % 1000000007;
        }
    }

    vector<vector<vector<vector<long>>>> f(n, vector(--m + 1, vector((m << 1) + 1, vector<long>(k + 1, 0))));

    for(j = 0; j <= m; ++j) {
        f[0][j][j][0] = numsPower[0][j] * iFactorial[j] % 1000000007;
    }

    short p;
    short q;
    short q2;
    short r;
    for(i = 0; i + 1 < n; ++i) {
        for(j = 0; j <= m; ++j) {
            for(p = 0; p <= m * 2; ++p) {
                for(q = 0; q <= k; ++q) {
                    q2 = p % 2 + q;

                    if(q2 > k) {
                        break;
                    }

                    for(r = 0; r + j <= m; ++r) {
                        int p2 = p / 2 + r;
                        f[i + 1][j + r][p2][q2] += f[i][j][p][q] * numsPower[i + 1][r] % 1000000007 * iFactorial[r] % 1000000007;
                        f[i + 1][j + r][p2][q2] %= 1000000007;
                    }
                }
            }
        }
    }

    long result = 0;

    for(p = 0; p <= m << 1; ++p) {
        for(q = 0; q <= k; ++q) {
            if(__builtin_popcount(p) + q == k) {
                result = (result + f[n - 1][m][p][q] * factorial[m] % 1000000007) % 1000000007;
            }
        }
    }

    return result;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int m, int k, vector<int> nums, int expected) {
    cout << "m: " << m << endl;

    cout << "k: " << k << endl;

    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << magicalSum(m, k, nums) << endl;

    cout << endl;
}

int main() {
    test(5, 5, {1, 10, 100, 10000, 1000000}, 991600007);
    test(2, 2, {5, 4, 3, 2, 1}, 170);
    test(1, 1, {28}, 28);
    test(10, 4, {4, 38}, 476488942);
    test(7, 3, {14, 6}, 234733568);

    return 0;
}
