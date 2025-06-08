#include <iostream>
#include <vector>

using namespace std;

vector<int> lexicalOrder(int n) {
    vector<int> numbers;
    int number = 1;

    for(int i = 0; i < n; ++i) {
        numbers.push_back(number);

        if(10 * number <= n) {
            number *= 10;
        } else {
            while(number % 10 > 8 || number >= n) {
                number /= 10;
            }

            ++number;
        }
    }

    return numbers;
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
    printArray(lexicalOrder(n));

    cout << endl;
}

int main() {
    test(13, {1,10,11,12,13,2,3,4,5,6,7,8,9});
    test(2, {1,2});
    test(19, {1,10,11,12,13,14,15,16,17,18,19,2,3,4,5,6,7,8,9});
    test(1, {1});
    test(21, {1,10,11,12,13,14,15,16,17,18,19,2,20,21,3,4,5,6,7,8,9});

    return 0;
}
