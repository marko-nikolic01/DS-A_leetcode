#include <iostream>
#include <vector>

using namespace std;

double champagneTower(vector<double>& overflow, vector<double>& nextOverflow, int& queryRow, int& queryGlass, short row) {
    double poured;

    nextOverflow.resize(1);
    nextOverflow[0] = 0;

    for(short i = 0; i <= row; ++i) {
        poured = overflow[i] + overflow[i + 1];

        if(row == queryRow && i == queryGlass) {
            return min(1., poured);
        }

        nextOverflow.push_back(max(0., --poured / 2));
    }

    nextOverflow.push_back(0);

    return champagneTower(nextOverflow, overflow, queryRow, queryGlass, ++row);
}

double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> overflow(2, 0);
    vector<double> nextOverflow;

    overflow[0] = poured;

    return champagneTower(overflow, nextOverflow, query_row, query_glass, 0);
}

void test(int poured, int query_row, int query_glass, double expected) {
    cout << "Poured: " << poured << endl;

    cout << "Query row: " << query_row << endl;

    cout << "Query glass: " << query_glass << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << champagneTower(poured, query_row, query_glass) << endl;

    cout << endl;
}

int main()
{
    test(1, 1, 1, 0);
    test(2, 1, 1, 0.5);
    test(100000009, 33, 17, 1);
    test(3, 1, 1, 1);
    test(4, 2, 1, 0.5);

    return 0;
}
