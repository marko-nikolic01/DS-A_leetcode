#include <iostream>
#include <vector>

using namespace std;

int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long number = 0;
    long max = 0;
    long min = 0;

    int n = differences.size();
    for(int i = 0; i < n; ++i) {
        number += differences[i];

        if(number < min) {
            min = number;
        } else if(number > max) {
            max = number;
        }
    }

    min = -min + lower;
    max += min;

    return max > upper ? 0 : upper - max + 1;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> differences, int lower, int upper, int expected) {
    cout << "Differences: ";
    printArray(differences);

    cout << "Lower: " << lower << endl;

    cout << "Upper: " << upper << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfArrays(differences, lower, upper) << endl;

    cout << endl;
}

int main() {
    test({1, -3, 4}, 1, 6, 2);
    test({3, -4, 5, 1, -2}, -4, 5, 4);
    test({4, -7, 2}, 3, 6, 0);
    test({0, 0, 0}, 0, 0, 1);
    test({-2, -1, 2, 3}, 1, 10, 5);

    return 0;
}
