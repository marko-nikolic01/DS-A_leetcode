#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n) {
    if(n < 1) {
        return {0};
    }

    vector<int> bitCounts(n-- + 1);
    bitCounts[0] = 0;

    int last = 1;
    int index = 1;

    while(n > -1) {
        for(int i = 0; i < last && n > -1; ++i, --n) {
            bitCounts[index++] = bitCounts[i] + 1;
        }

        last <<= 1;
    }

    return bitCounts;
}

void test(int n, const vector<int>& expected) {
    cout << "n: " << n << endl;

    cout << "Expected: ";
    for(int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result:   ";
    for(int result : countBits(n)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test(0, {0});
    test(1, {0, 1});
    test(2, {0, 1, 1});
    test(3, {0, 1, 1, 2});
    test(4, {0, 1, 1, 2, 1});
    test(5, {0, 1, 1, 2, 1, 2});
    test(6, {0, 1, 1, 2, 1, 2, 2});
    test(7, {0, 1, 1, 2, 1, 2, 2, 3});
    test(8, {0, 1, 1, 2, 1, 2, 2, 3, 1});
    test(9, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2});
    test(10, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2});

    return 0;
}
