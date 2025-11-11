#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    auto& n0 = m;
    auto& n1 = n;
    array<array<int, 101>, 101> dp{};
    short c0;
    short c1;

    short i;
    short j;
    for(auto& str : strs) {
        c0 = ranges::count(str, '0');
        c1 = str.size() - c0;

        for(i = m; i >= c0; --i)
            for(j = n; j >= c1; --j) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
            }
    }

    return dp[m][n];
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> strs, int m, int n, int expected) {
    cout << "Strings: ";
    printArray(strs);

    cout << "m: " << m << endl;

    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findMaxForm(strs, m, n) << endl;

    cout << endl;
}

int main() {
    test({"10", "0001", "111001", "1", "0"}, 5, 3, 4);
    test({"10", "0", "1"}, 1, 1, 2);
    test({"10", "0001", "111001", "1", "0"}, 3, 4, 3);
    test({"10", "0001", "111001", "1", "0"}, 6, 6, 4);
    test({"1", "0", "0", "1", "1", "0"}, 2, 2, 4);

    return 0;
}
