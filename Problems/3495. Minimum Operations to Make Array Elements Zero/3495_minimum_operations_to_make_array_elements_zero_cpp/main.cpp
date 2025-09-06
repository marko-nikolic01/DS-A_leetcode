#include <iostream>
#include <vector>

using namespace std;

long long minOperations(vector<vector<int>>& queries) {
    long operations = 0;
    long currentOperations;
    vector<pair<int, int>> operationsPerPowerOf4 = {
        {3, 1},
        {15, 2},
        {63, 3},
        {255, 4},
        {1023, 5},
        {4095, 6},
        {16383, 7},
        {65535, 8},
        {262143, 9},
        {1048575, 10},
        {4194303, 11},
        {16777215, 12},
        {67108863, 13},
        {268435455, 14},
        {1073741823, 15}
    };

    short o;
    for(int i = queries.size() - 1; i > -1; --i) {
        currentOperations = 0;

        for(o = 0; o < 14; ++o) {
            if(queries[i][0] <= operationsPerPowerOf4[o].first) {
                break;
            }
        }

        do {
            currentOperations += (long)(min(queries[i][1], operationsPerPowerOf4[o].first) - queries[i][0] + 1) * operationsPerPowerOf4[o].second;
            queries[i][0] = operationsPerPowerOf4[o++].first + 1;
        } while(queries[i][0] <= queries[i][1]);

        operations += ++currentOperations >> 1;
    }

    return operations;
}

void test(vector<vector<int>> queries, long long expected) {
    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minOperations(queries) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {2, 4}}, 3);
    test({{2, 6}}, 4);
    test({{3, 7}, {3, 7}}, 10);
    test({{1, 1}}, 1);
    test({{5, 8}}, 4);

    return 0;
}
