#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialDigits(vector<int>& numbers, int number, int& low, int& high) {
    if(number >= low) {
        if(number <= high) {
            numbers.push_back(number);
        } else {
            return;
        }
    }

    if(number % 10 < 9) {
        sequentialDigits(numbers, 10 * number + number % 10 + 1, low, high);
    }
}

vector<int> sequentialDigits(int low, int high) {
    vector<int> numbers;

    for(short i = 1; i < 9; ++i) {
        sequentialDigits(numbers, i, low, high);
    }

    sort(numbers.begin(), numbers.end());

    return numbers;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int low, int high, vector<int> expected) {
    cout << "Low: " << low << endl;

    cout << "High: " << high << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(sequentialDigits(low, high));

    cout << endl;
}

int main() {
    test(100, 300, {123, 234});
    test(1000, 13000, {1234, 2345, 3456, 4567, 5678, 6789, 12345});
    test(10, 99, {12, 23, 34, 45, 56, 67, 78, 89});
    test(1000000000, 1000000000, {});
    test(123, 123, {123});

    return 0;
}
