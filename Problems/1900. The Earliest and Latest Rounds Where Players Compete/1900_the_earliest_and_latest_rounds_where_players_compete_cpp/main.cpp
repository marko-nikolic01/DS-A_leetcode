#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<int, int> earliestAndLatest(int n, int f, int s, vector<vector<vector<int>>>& F, vector<vector<vector<int>>>& G) {
    if(F[n][f][s] != 0) {
        return {F[n][f][s], G[n][f][s]};
    }

    if(f + s == n + 1) {
        return {1, 1};
    }

    if(f + s > n + 1) {
        tie(F[n][f][s], G[n][f][s]) = earliestAndLatest(n, n + 1 - s, n + 1 - f, F, G);

        return {F[n][f][s], G[n][f][s]};
    }

    int earliest = INT_MAX;
    int latest = INT_MIN;
    int n_half = (n + 1) / 2;
    int s_prime;
    int mid;

    int i;
    int j;
    if(s <= n_half) {
        for (i = 0; i < f; ++i) {
            for (j = 0; j < s - f; ++j) {
                auto [x, y] = earliestAndLatest(n_half, i + 1, i + j + 2, F, G);
                earliest = min(earliest, x);
                latest = max(latest, y);
            }
        }
    } else {
        s_prime = n + 1 - s;
        mid = (n - 2 * s_prime + 1) / 2;

        for(i = 0; i < f; ++i) {
            for(j = 0; j < s_prime - f; ++j) {
                auto [x, y] = earliestAndLatest(n_half, i + 1, i + j + mid + 2, F, G);
                earliest = min(earliest, x);
                latest = max(latest, y);
            }
        }
    }

    F[n][f][s] = earliest + 1;
    G[n][f][s] = latest + 1;

    return {F[n][f][s], G[n][f][s]};
}

vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    vector<vector<vector<int>>> F(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    vector<vector<vector<int>>> G(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

    if(firstPlayer > secondPlayer) {
        swap(firstPlayer, secondPlayer);
    }

    auto [earliest, latest] = earliestAndLatest(n, firstPlayer, secondPlayer, F, G);

    return {earliest, latest};
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, int firstPlayer, int secondPlayer, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "First player: " << firstPlayer << endl;

    cout << "Second player: " << secondPlayer << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(earliestAndLatest(n, firstPlayer, secondPlayer));

    cout << endl;
}

int main() {
    test(11, 2, 4, {3, 4});
    test(5, 1, 5, {1, 1});
    test(8, 1, 8, {1, 1});
    test(4, 2, 3, {1, 1});
    test(28, 13, 16, {1, 1});

    return 0;
}
