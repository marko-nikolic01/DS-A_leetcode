#include <iostream>
#include <vector>

using namespace std;

int minimumIndex(vector<int>& capacity, int itemSize) {
    short index = -1;

    for(short i = capacity.size() - 1; i > -1; --i) {
        if(capacity[i] >= itemSize && (index < 0 || capacity[i] <= capacity[index])) {
            index = i;
        }
    }

    return index;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> capacity, int itemSize, int expected) {
    cout << "Capacities: ";
    printArray(capacity);

    cout << "Item size: " << itemSize << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumIndex(capacity, itemSize) << endl;

    cout << endl;
}

int main() {
    test({1, 5, 3, 7}, 3, 2);
    test({3, 5, 4, 3}, 2, 0);
    test({4}, 5, -1);
    test({5, 5, 5, 5}, 5, 0);
    test({1, 2, 3, 10}, 9, 3);

    return 0;
}
