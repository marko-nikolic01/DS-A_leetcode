#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long putMarbles(vector<int>& weights, int k) {
    int n = weights.size();
    vector<int> costs(--n);

    long i = 0;
    for(i; i < n; ++i) {
        costs[i] = weights[i] + weights[i + 1];
    }

    sort(costs.begin(), costs.end());
    i = 0;
    --k;

    while(k > 0) {
        i += costs[--n] - costs[--k];
    }

    return i;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> weights, int k, long long expected) {
    cout << "Marble weights: ";
    printArray(weights);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << putMarbles(weights, k) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 5, 1}, 2, 4);
    test({1, 3}, 2, 0);
    test({4, 2, 8, 6, 7}, 3, 11);
    test({10, 20, 30, 40, 50}, 4, 60);
    test({5, 1, 2, 6, 3}, 3, 8);
    test({1, 3, 5, 1}, 1, 0);

    return 0;
}
