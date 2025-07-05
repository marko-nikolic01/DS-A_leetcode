#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findLucky(vector<int>& arr) {
    unordered_map<short, short> occurences;

    short i;
    for(i = arr.size() - 1; i > -1; --i) {
        ++occurences[arr[i]] > arr[i];
    }

    i = -1;

    for(unordered_map<short, short>::iterator it = occurences.begin(); it != occurences.end(); ++it) {
        if(it->first == it->second && it->first > i) {
            i = it->first;
        }
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

    cout << "Result: " << findLucky(arr) << endl;

    cout << endl;
}

int main() {
    test({2, 2, 3, 4}, 2);
    test({1, 2, 2, 3, 3, 3}, 3);
    test({2, 2, 2, 3, 3}, -1);
    test({1}, 1);
    test({5, 5, 5, 5, 5}, 5);

    return 0;
}
