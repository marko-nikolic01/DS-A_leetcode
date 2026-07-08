#include <iostream>
#include <vector>

using namespace std;

vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<int> sum(++n, 0);
    vector<long> x(n, 0);
    vector<int> cnt(n--, 0);
    long pow10[100001];
    int d;
    int l;
    int r;
    int length;
    long val_x;
    long val_sum;

    pow10[0] = 1;

    int i;
    for(i = 1; i < 100001; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % 1000000007;
    }

    for(i = 0; i < n; ++i) {
        d = s[i] - '0';
        sum[i + 1] = sum[i] + d;
        x[i + 1] = (d > 0) ? (x[i] * 10 + d) % 1000000007 : x[i];
        cnt[i + 1] = cnt[i] + (d > 0);
    }

    n = queries.size();
    vector<int> res(n, 0);

    for(i = 0; i < n; ++i) {
        l = queries[i][0];
        r = queries[i][1] + 1;
        length = cnt[r] - cnt[l];
        val_x = (x[r] - x[l] * pow10[length] % 1000000007 + 1000000007) % 1000000007;
        val_sum = sum[r] - sum[l];
        res[i] = (val_x * val_sum) % 1000000007;
    }

    return res;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string s, vector<vector<int>> queries, vector<int> expected) {
    cout << "Digits: " << s << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(sumAndMultiply(s, queries));

    cout << endl;
}

int main() {
    test("10203004", {{0, 7}, {1, 3}, {4, 6}}, {12340, 4, 9});
    test("1000", {{0, 3}, {1, 1}}, {1, 0});
    test("9876543210", {{0, 9}}, {444444137});
    test("000", {{0, 2}}, {0});
    test("5", {{0, 0}}, {25});

    return 0;
}
