#include <iostream>
#include <vector>

using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int triplets = 0;

    short i;
    short j;
    for(short k = arr.size() - 1; k > 1; --k) {
        for(j = k - 1; j > 0; --j) {
            if(abs(arr[j] - arr[k]) <= b) {
                for(i = j - 1; i > -1; --i) {
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[i] - arr[k]) <= c) {
                        ++triplets;
                    }
                }
            }
        }
    }

    return triplets;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr, int a, int b, int c, int expected) {
    cout << "Array: ";
    printArray(arr);

    cout << "a: " << a << endl;

    cout << "b: " << b << endl;

    cout << "c: " << c << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countGoodTriplets(arr, a, b, c) << endl;

    cout << endl;
}

int main() {
    test({3, 0, 1, 1, 9, 7}, 7, 2, 3, 4);
    test({1, 1, 2, 2, 3}, 0, 0, 1, 0);
    test({1, 2, 3, 4, 5}, 1, 1, 1, 0);
    test({1, 2, 3, 1}, 3, 3, 3, 4);
    test({1, 5, 9, 1, 5, 9}, 4, 4, 4, 8);

    return 0;
}
