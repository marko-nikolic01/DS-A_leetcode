#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k) {
    long totalHappiness = 0;

    sort(happiness.begin(), happiness.end(), greater<int>());

    for(int i = 0; i < k; ++i) {
        if(happiness[i] <= i) {
            break;
        }

        totalHappiness += happiness[i] - i;
    }

    return totalHappiness;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> happiness, int k, long long expected) {
    cout << "Happines: ";
    printArray(happiness);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumHappinessSum(happiness, k) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, 2, 4);
    test({1, 1, 1, 1}, 2, 1);
    test({2, 3, 4, 5}, 1, 5);
    test({5, 5, 5}, 3, 12);
    test({1, 1, 1}, 3, 1);
    test({100000000}, 1, 100000000);
    test({3, 3, 3, 3}, 4, 6);
    test({10, 9, 8, 7}, 2, 18);

    return 0;
}
