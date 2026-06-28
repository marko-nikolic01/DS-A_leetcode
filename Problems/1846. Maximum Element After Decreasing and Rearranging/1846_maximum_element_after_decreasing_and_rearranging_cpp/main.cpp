#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    arr[0] = 1;

    int n = arr.size();
    for(int i = 1; i < n; ++i) {
        if(arr[i] > ++arr[i - 1]) {
            arr[i] = arr[i - 1];
        }
    }

    return arr[--n];
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

    cout << "Result: " << maximumElementAfterDecrementingAndRearranging(arr) << endl;

    cout << endl;
}

int main() {
    test({2, 2, 1, 2, 1}, 2);
    test({100, 1, 1000}, 3);
    test({1, 2, 3, 4, 5}, 5);
    test({1, 1, 1, 1}, 1);
    test({5}, 1);

    return 0;
}
