#include <iostream>
#include <vector>

using namespace std;

vector<int> sumZero(int n) {
    vector<int> zero;
    short number = 0;

    if((n & 1) > 0) {
        zero.push_back(0);
    }

    n >>= 1;

    while(--n > -1) {
        zero.push_back(++number);
        zero.push_back(-number);
    }

    return zero;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(sumZero(n));

    cout << endl;
}

int main() {
    test(1, {0});
    test(2, {1, -1});
    test(3, {0, 1, -1});
    test(4, {1, -1, 2, -2});
    test(5, {0, 1, -1, 2, -2});

    return 0;
}
