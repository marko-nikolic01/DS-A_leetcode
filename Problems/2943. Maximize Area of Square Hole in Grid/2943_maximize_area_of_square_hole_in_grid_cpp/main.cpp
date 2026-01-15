#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());

    int horizontalMaximum = 1;
    int verticalMaximum = 1;
    int horizontalCurrent = 1;
    int verticalCurrent = 1;

    n = hBars.size();
    for(m = 1; m < n; ++m) {
        if(hBars[m] != ++hBars[m - 1]) {
            horizontalCurrent = 1;
        } else if(++horizontalCurrent > horizontalMaximum) {
            horizontalMaximum = horizontalCurrent;
        }
    }

    n = vBars.size();
    for (m = 1; m < n; ++m) {
        if(vBars[m] != ++vBars[m - 1]) {
            verticalCurrent = 1;
        } else if(++verticalCurrent > verticalMaximum) {
            verticalMaximum = verticalCurrent;
        }
    }

    return horizontalMaximum < verticalMaximum ? ++horizontalMaximum * horizontalMaximum : ++verticalMaximum * verticalMaximum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, int m, vector<int> hBars, vector<int> vBars, int expected) {
    cout << "n: " << n << endl;

    cout << "m: " << m << endl;

    cout << "Horizontal bars: ";
    printArray(hBars);

    cout << "Vertical bars: ";
    printArray(vBars);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximizeSquareHoleArea(n, m, hBars, vBars) << endl;

    cout << endl;
}

int main() {
    test(2, 1, {2, 3}, {2}, 4);
    test(1, 1, {2}, {2}, 4);
    test(2, 3, {2, 3}, {2, 4}, 4);
    test(5, 5, {2, 3, 4}, {3, 4, 5}, 16);
    test(10, 8, {2, 4, 6}, {3, 4, 5, 6}, 4);

    return 0;
}
