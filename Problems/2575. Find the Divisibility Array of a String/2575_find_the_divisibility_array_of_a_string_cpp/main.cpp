#include <iostream>
#include <vector>

using namespace std;

vector<int> divisibilityArray(string word, int m) {
    int n = word.length();
    vector<int> divisibility(n);
    long remainder = 0;

    for(int i = 0; i < n; ++i) {
        remainder = (10 * remainder + word[i] - '0') % m;
        divisibility[i] = remainder < 1 ? 1 : 0;
    }

    return divisibility;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string word, int m, vector<int> expected) {
    cout << "Number: " << word << endl;

    cout << "m: " << m << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(divisibilityArray(word, m));

    cout << endl;
}

int main() {
    test("998244353", 3, {1, 1, 0, 0, 0, 1, 1, 0, 0});
    test("1010", 10, {0, 1, 0, 1});
    test("123456", 7, {0, 0, 0, 0, 0, 0});
    test("50000", 5, {1, 1, 1, 1, 1});
    test("111111", 2, {0, 0, 0, 0, 0, 0});

    return 0;
}
