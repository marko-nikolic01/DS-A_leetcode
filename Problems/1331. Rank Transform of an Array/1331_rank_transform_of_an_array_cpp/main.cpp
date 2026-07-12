#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    unordered_map<int, int> ranks;
    vector<int> sortedArray;

    int i;
    int n = arr.size();
    for(i = --n; i > -1; --i) {
        if(ranks.find(arr[i]) == ranks.end()) {
            ranks[arr[i]] = 0;
            sortedArray.push_back(arr[i]);
        }
    }

    sort(sortedArray.begin(), sortedArray.end());

    for(i = sortedArray.size() - 1; i > -1; --i) {
        ranks[sortedArray[i]] = i + 1;
    }

    for(n; n > -1; --n) {
        arr[n] = ranks[arr[n]];
    }

    return arr;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr, vector<int> expected) {
    cout << "Array: ";
    printArray(arr);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(arrayRankTransform(arr));

    cout << endl;
}

int main() {
    test({40, 10, 20, 30}, {4, 1, 2, 3});
    test({100, 100, 100}, {1, 1, 1});
    test({37, 12, 28, 9, 100, 56, 80, 5, 12}, {5, 3, 4, 2, 8, 6, 7, 1, 3});
    test({}, {});
    test({-5, -10, 0, 5, -1000000000}, {3, 2, 4, 5, 1});

    return 0;
}
