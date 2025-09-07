#include <iostream>
#include <vector>

using namespace std;

long long minOperations(vector<vector<int>>& queries) {
    long operations = 0;
    long currentOperations;
    vector<int> operationsPerPowerOf4 = {
        3,
        15,
        63,
        255,
        1023,
        4095,
        16383,
        65535,
        262143,
        1048575,
        4194303,
        16777215,
        67108863,
        268435455,
        1073741823
    };

    short o;
    for(int i = queries.size() - 1; i > -1; --i) {
        currentOperations = 0;

        for(o = 0; o < 14; ++o) {
            if(queries[i][0] <= operationsPerPowerOf4[o]) {
                break;
            }
        }

        do {
            currentOperations += (long)(min(queries[i][1], operationsPerPowerOf4[o]) - queries[i][0] + 1) * (o + 1);
            queries[i][0] = operationsPerPowerOf4[o++] + 1;
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
