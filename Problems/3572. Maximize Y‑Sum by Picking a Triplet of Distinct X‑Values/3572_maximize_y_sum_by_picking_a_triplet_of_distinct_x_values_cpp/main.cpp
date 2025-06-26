#include <iostream>
#include <vector>

using namespace std;

int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
    vector<int> groups = {0, 0, 0};
    vector<int> values = {0, 0, 0};
    short iMin;

    for(int i = x.size() - 1; i > -1; --i) {
        if(x[i] == groups[0]) {
            if(y[i] > values[0]) {
                values[0] = y[i];
            }
        } else if(x[i] == groups[1]) {
            if(y[i] > values[1]) {
                values[1] = y[i];
            }
        } else if(x[i] == groups[2]) {
            if(y[i] > values[2]) {
                values[2] = y[i];
            }
        } else {
            iMin = values[0] < values[1] ? (values[0] < values[2] ? 0 : 2) : (values[1] < values[2] ? 1 : 2);

            if(y[i] > values[iMin]) {
                groups[iMin] = x[i];
                values[iMin] = y[i];
            }
        }
    }

    return groups[0] < 1 || groups[1] < 1 || groups[2] < 1 ? -1 : values[0] + values[1] + values[2];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> x, vector<int> y, int expected) {
    cout << "x: ";
    printArray(x);

    cout << "y: ";
    printArray(y);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSumDistinctTriplet(x, y) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 1, 3, 2}, {5, 3, 4, 6, 2}, 14);
    test({1, 2, 1, 2}, {4, 5, 6, 7}, -1);
    test({5, 2, 15, 2, 15, 8}, {13, 5, 11, 15, 8, 8}, 39);
    test({14, 2, 19, 7}, {1, 11, 12, 5}, 28);
    test({1, 2, 3, 1, 2, 3}, {1, 2, 3, 100, 200, 300}, 600);

    return 0;
}
