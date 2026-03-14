#include <iostream>
#include <vector>

using namespace std;

int minOperations(int n) {
    short operations = 0;
    vector<int> powers = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};
    short left;
    short right;
    short middle;

    while(n > 0) {
        ++operations;
        left = 0;
        right = 17;

        while(true) {
            middle = (left + right) >> 1;

            if(n < powers[middle]) {
                right = --middle;
            } else if(n == powers[middle]) {
                return operations;
            } else if(n < powers[middle + 1]) {
                n = min(abs(n - powers[middle]), abs(n - powers[middle + 1]));

                break;
            } else {
                left = ++middle;
            }
        }
    }

    return operations;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minOperations(n) << endl;

    cout << endl;
}

int main() {
    test(39, 3);
    test(54, 3);
    test(1, 1);
    test(3, 2);
    test(100000, 6);
    return 0;
}
