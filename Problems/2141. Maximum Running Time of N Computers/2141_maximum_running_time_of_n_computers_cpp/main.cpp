#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxRunTime(int n, vector<int>& batteries) {
    long energy = 0;

    int nBatteries = batteries.size();
    for(int i = --nBatteries; i > -1; --i) {
        energy += batteries[i];
    }

    sort(batteries.begin(), batteries.end());

    for(nBatteries; nBatteries > -1; --nBatteries) {
        if(batteries[nBatteries] > energy / n) {
            energy -= batteries[nBatteries];
            --n;
        } else {
            break;
        }
    }

    return energy / n;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<int> batteries, long long expected) {
    cout << "n: " << n << endl;

    cout << "Batteries: ";
    printArray(batteries);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxRunTime(n, batteries) << endl;

    cout << endl;
}

int main() {
    test(2, {3, 3, 3}, 4);
    test(2, {1, 1, 1, 1}, 2);
    test(3, {10, 10, 3, 5}, 8);
    test(1, {100}, 100);
    test(3, {2, 2, 3, 3, 4}, 4);

    return 0;
}
