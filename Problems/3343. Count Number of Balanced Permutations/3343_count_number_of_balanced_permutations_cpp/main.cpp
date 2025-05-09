#include <iostream>
#include <vector>

using namespace std;

int countBalancedPermutations(string num) {
    int tot = 0;
    int n = num.size();
    vector<int> cnt(10);

    for(char ch : num) {
        int d = ch - '0';
        cnt[d]++;
        tot += d;
    }

    if (tot % 2 != 0) {
        return 0;
    }

    int target = tot / 2;
    int maxOdd = (n + 1) / 2;
    vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1));
    vector<vector<long long>> f(target + 1, vector<long long>(maxOdd + 1));

    for(int i = 0; i <= maxOdd; i++) {
        comb[i][i] = comb[i][0] = 1;

        for(int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % 1000000007;
        }
    }

    f[0][0] = 1;
    int psum = 0;
    int totSum = 0;

    for(int i = 0; i <= 9; i++) {
        psum += cnt[i];
        totSum += i * cnt[i];

        for (int oddCnt = min(psum, maxOdd); oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--) {
            int evenCnt = psum - oddCnt;

            for(int curr = min(totSum, target); curr >= max(0, totSum - target); curr--) {
                long long res = 0;

                for(int j = max(0, cnt[i] - evenCnt); j <= min(cnt[i], oddCnt) && i * j <= curr; j++) {
                    long long ways = comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % 1000000007;
                    res = (res + ways * f[curr - i * j][oddCnt - j] % 1000000007) % 1000000007;
                }

                f[curr][oddCnt] = res % 1000000007;
            }
        }
    }

    return f[target][maxOdd];
}

void test(string digits, int expected) {
    cout << "Digits: " << digits << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countBalancedPermutations(digits) << endl;

    cout << endl;
}

int main() {
    test("123", 2);
    test("112", 1);
    test("12345", 0);
    test("11", 1);
    test("1212", 4);
    return 0;
}
