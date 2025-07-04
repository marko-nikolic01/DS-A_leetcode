#include <iostream>
#include <vector>

using namespace std;

char kthCharacter(long long k, vector<int>& operations) {
    short character = 0;
    short i = min(46, (short)operations.size() - 1);
    long powerOf2 = 1l << (i + 1);

    while(powerOf2 >> 1 > k) {
        powerOf2 >>= 1;
        --i;
    }

    while(k > 1) {
        powerOf2 >>= 1;

        if(powerOf2 < k) {
            if(operations[i] > 0) {
                ++character;
            }

            k -= powerOf2;
        }

        --i;
    }

    return 'a' + character % 26;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(long long k, vector<int> operations, char expected) {
    cout << "k: " << k << endl;

    cout << "Operations: ";
    printArray(operations);

    cout << "Expected: " << "'" << expected << "'" << endl;

    cout << "Result: " << "'" << kthCharacter(k, operations) << "'" << endl;

    cout << endl;
}

int main() {
    test(5, {0, 0, 0}, 'a');
    test(10, {0, 1, 0, 1}, 'b');
    test(12145134613, {0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1}, 'i');
    test(100000000000000, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 'e');
    test(15, {0, 1, 1, 0, 1}, 'c');

    return 0;
}
