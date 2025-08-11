#include <iostream>
#include <vector>

using namespace std;

long productQueries(long base, long exponent) {
    long result = 1;

    while(exponent > 0) {
        if(exponent & 1) {
            result = (result * base) % 1000000007;
        }

        base = (base * base) % 1000000007;
        exponent >>= 1;
    }

    return result;
}

long productQueries(long x) {
    return productQueries(x, 1000000005);
}

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;

    int i;
    for(int i = 1; n > 0; i <<= 1) {
        if(n & 1) {
            powers.push_back(i);
        }

        n >>= 1;
    }

    n = powers.size();
    vector<long> prefix(n);
    prefix[0] = powers[0] % 1000000007;

    for(i = 1; i < n; ++i) {
        prefix[i] = (prefix[i - 1] * powers[i]) % 1000000007;
    }

    vector<int> products(queries.size());
    long product;

    for(i = queries.size() - 1; i > -1; --i) {
        products[i] = queries[i][0] > 0 ? (prefix[queries[i][1]] * productQueries(prefix[queries[i][0] - 1])) % 1000000007 : prefix[queries[i][1]];
    }

    return products;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> queries, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(productQueries(n, queries));

    cout << endl;
}

int main() {
    test(15, {{0, 1}, {2, 2}, {0, 3}}, {2, 4, 64});
    test(2, {{0, 0}}, {2});
    test(7, {{0, 0}, {1, 2}, {0, 2}}, {1, 8, 8});
    test(1024, {{0, 0}}, {1024});
    test(19, {{0, 0}, {1, 1}, {0, 2}, {1, 2}}, {1, 2, 32, 32});

    return 0;
}
