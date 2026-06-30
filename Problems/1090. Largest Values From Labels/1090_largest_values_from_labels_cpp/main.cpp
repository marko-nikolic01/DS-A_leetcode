#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
    int value = 0;
    vector<pair<short, short>> items;
    unordered_map<short, short> used;

    short n = values.size();
    for(short i = n - 1; i > -1; --i) {
        items.push_back({values[i], labels[i]});
    }

    sort(items.begin(), items.end());

    while(--n > -1 && numWanted > 0) {
        if(++used[items[n].second] <= useLimit) {
            value += items[n].first;
            --numWanted;
        }
    }

    return value;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> values, vector<int> labels, int numWanted, int useLimit, int expected) {
    cout << "Values: ";
    printArray(values);

    cout << "Labels: ";
    printArray(labels);

    cout << "Wanted number: " << numWanted << endl;

    cout << "Use limit: " << useLimit << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestValsFromLabels(values, labels, numWanted, useLimit) << endl;

    cout << endl;
}

int main() {
    test({5, 4, 3, 2, 1}, {1, 1, 2, 2, 3}, 3, 1, 9);
    test({5, 4, 3, 2, 1}, {1, 3, 3, 3, 2}, 3, 2, 12);
    test({9, 8, 8, 7, 6}, {0, 0, 0, 1, 1}, 3, 1, 16);
    test({1, 1, 1, 1}, {1, 2, 3, 4}, 2, 1, 2);
    test({10, 20, 30}, {1, 1, 1}, 5, 3, 60);

    return 0;
}
