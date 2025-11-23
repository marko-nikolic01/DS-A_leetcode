#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minSetSize(vector<int>& arr) {
    unordered_map<int, int> numbers;

    int i;
    int n = arr.size();
    for(i = n - 1; i > -1; --i) {
        ++numbers[arr[i]];
    }

    i = numbers.size();
    vector<int> occurences(i);

    for(unordered_map<int, int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        occurences[--i] = it->second;
    }

    sort(occurences.begin(), occurences.end(), greater<int>());

    for(n >>= 1; n > 0;) {
        n -= occurences[i++];
    }

    return i;
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

    cout << "Result: " << minSetSize(arr) << endl;

    cout << endl;
}

int main() {
    test({3, 3, 3, 3, 5, 5, 5, 2, 2, 7}, 2);
    test({7, 7, 7, 7, 7, 7}, 1);
    test({1, 2, 1, 2}, 1);
    test({1, 1, 1, 1, 2, 3, 4, 5}, 1);
    test({4, 4, 6, 6, 8, 8, 9, 9}, 2);

    return 0;
}
