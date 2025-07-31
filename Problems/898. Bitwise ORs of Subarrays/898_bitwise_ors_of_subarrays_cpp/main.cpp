#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> ors;
    unordered_set<int> ors1;
    unordered_set<int> ors2;
    unordered_set<int>* previousOrs = &ors1;
    unordered_set<int>* nextOrs = &ors2;
    unordered_set<int>* tempOrs;
    int orValue;

    unordered_set<int>::iterator it;
    for(int i = arr.size() - 1; i > -1; --i) {
        nextOrs->insert(arr[i]);
        ors.insert(arr[i]);

        for(it = previousOrs->begin(); it != previousOrs->end(); ++it) {
            orValue = *it | arr[i];
            nextOrs->insert(orValue);
            ors.insert(orValue);
        }

        previousOrs->clear();
        tempOrs = previousOrs;
        previousOrs = nextOrs;
        nextOrs = tempOrs;
    }

    return ors.size();
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

    cout << "Result: " << subarrayBitwiseORs(arr) << endl;

    cout << endl;
}

int main() {
    test({0}, 1);
    test({1, 1, 2}, 3);
    test({1, 2, 4}, 6);
    test({8, 1, 2}, 6);
    test({3, 3, 3}, 1);

    return 0;
}
