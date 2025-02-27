#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    vector<vector<short>> sequenceLengths(n, vector<short>(n, 0));
    unordered_map<int, int> valueIndex;

    short longestFibonacciSequence = 2;

    int j;
    int k;
    for(int i = 0; i < n; ++i) {
        valueIndex[arr[i]] = i;

        for(j = 0; j < i; ++j) {
            if(valueIndex.find(arr[i] - arr[j]) == valueIndex.end() || arr[i] - arr[j] >= arr[j]) {
                sequenceLengths[i][j] = 2;
            } else {
                k = valueIndex[arr[i] - arr[j]];

                sequenceLengths[i][j] = ++sequenceLengths[j][k];

                if(sequenceLengths[i][j] > longestFibonacciSequence) {
                    longestFibonacciSequence = sequenceLengths[i][j];
                }
            }
        }
    }

    return longestFibonacciSequence > 2 ? longestFibonacciSequence : 0;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr, int expected) {
    cout << "Array: ";
    printArray(arr);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << lenLongestFibSubseq(arr) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 5, 6, 7, 8}, 5);
    test({1, 3, 7, 11, 12, 14, 18}, 3);
    test({1, 2, 3, 5, 8, 13, 21, 34}, 8);
    test({1, 4, 7, 10, 13, 16, 19}, 0);
    test({2, 4, 7, 11, 18, 29, 47}, 6);

    return 0;
}
