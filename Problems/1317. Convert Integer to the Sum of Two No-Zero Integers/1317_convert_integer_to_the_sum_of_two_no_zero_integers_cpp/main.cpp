#include <iostream>
#include <vector>

using namespace std;

vector<int> getNoZeroIntegers(int n) {
    short b;
    short temp;
    bool isNonZeroInteger;

    for(short a = 1; a < n; ++a) {
        b = n - a;
        isNonZeroInteger = true;

        temp = a;

        while(temp > 0) {
            if(temp % 10 < 1) {
                isNonZeroInteger = false;
                break;
            }

            temp /= 10;
        }

        if(!isNonZeroInteger) {
            continue;
        }

        temp = b;

        while(temp > 0) {
            if(temp % 10 < 1) {
                isNonZeroInteger = false;
                break;
            }

            temp /= 10;
        }

        if(isNonZeroInteger) {
            return {a, b};
        }
    }

    return {};
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
    printArray(getNoZeroIntegers(n));

    cout << endl;
}

int main() {
    test(2, {1, 1});
    test(11, {2, 9});
    test(101, {2, 99});
    test(1000, {1, 999});
    test(109, {11, 98});

    return 0;
}
