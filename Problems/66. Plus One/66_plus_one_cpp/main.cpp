#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    short i;
    for(i = digits.size() - 1; i > -1; --i) {
        if(digits[i] < 9) {
            bool carry;

            for(i = digits.size() - 1; true; --i) {
                carry = digits[i] > 8;

                if(carry) {
                    digits[i] = 0;
                } else {
                    ++digits[i];

                    return digits;
                }
            }
        }
    }

    i = digits.size();
    digits.resize(++i);
    digits[0] = 1;

    while(--i > 0) {
        digits[i] = 0;
    }

    return digits;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> digits, vector<int> expected) {
    cout << "Digits: ";
    printArray(digits);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(plusOne(digits));

    cout << endl;
}

int main() {
    test({1, 2, 3}, {1, 2, 4});
    test({4, 3, 2, 1}, {4, 3, 2, 2});
    test({9}, {1, 0});
    test({8, 9, 9, 9}, {9, 0, 0, 0});
    test({9, 9, 9}, {1, 0, 0, 0});
    test({1}, {2});

    return 0;
}
