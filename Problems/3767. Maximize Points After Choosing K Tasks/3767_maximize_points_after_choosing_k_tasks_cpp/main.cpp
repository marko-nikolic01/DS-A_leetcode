#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
    long points = 0;
    int n = technique1.size();
    vector<pair<int, int>> tasks(n);

    int i;
    for(i = 0; i < n; ++i) {
        tasks[i] = {technique1[i] - technique2[i], i};
    }

    sort(tasks.begin(), tasks.end());

    i = --n - k;
    for(n; n > i || (n > -1 && tasks[n].first > 0); --n) {
        points += technique1[tasks[n].second];
    }

    for(n; n > -1; --n) {
        points += technique2[tasks[n].second];
    }

    return points;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> technique1, vector<int> technique2, int k, long long expected) {
    cout << "Technique 1: ";
    printArray(technique1);

    cout << "Technique 2: ";
    printArray(technique2);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxPoints(technique1, technique2, k) << endl;

    cout << endl;
}

int main() {
    test({5, 2, 10}, {10, 3, 8}, 2, 22);
    test({10, 20, 30}, {5, 15, 25}, 2, 60);
    test({1, 2, 3}, {4, 5, 6}, 0, 15);
    test({8, 1, 4, 9}, {3, 10, 2, 1}, 1, 31);
    test({7, 7, 7}, {7, 7, 7}, 2, 21);

    return 0;
}
