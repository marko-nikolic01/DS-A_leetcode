#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = baskets.size();
    int m = sqrt(n);
    int section = (n + m - 1) / m;
    int count = 0;
    vector<int> maxV(section);

    int i;
    for(i = 0; i < n; i++) {
        maxV[i / m] = max(maxV[i / m], baskets[i]);
    }

    int sec;
    int unset;
    int choose;
    int pos;

    int j;
    int nFruits = fruits.size();
    for(i = 0; i < nFruits; ++i) {
        unset = 1;

        for(sec = 0; sec < section; ++sec) {
            if(maxV[sec] < fruits[i]) {
                continue;
            }

            choose = 0;
            maxV[sec] = 0;

            for(j = 0; j < m; j++) {
                pos = sec * m + j;

                if(pos < n && baskets[pos] >= fruits[i] && !choose) {
                    baskets[pos] = 0;
                    choose = 1;
                }

                if(pos < n) {
                    maxV[sec] = max(maxV[sec], baskets[pos]);
                }
            }

            unset = 0;

            break;
        }

        count += unset;
    }

    return count;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> fruits, vector<int> baskets, int expected) {
    cout << "Fruits: ";
    printArray(fruits);

    cout << "Baskets: ";
    printArray(baskets);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numOfUnplacedFruits(fruits, baskets) << endl;

    cout << endl;
}

int main() {
    test({4, 2, 5}, {3, 5, 4}, 1);
    test({3, 6, 1}, {6, 4, 7}, 0);
    test({10, 20, 30}, {1, 2, 3}, 3);
    test({5, 10, 15}, {5, 10, 15}, 0);
    test({2, 2, 2}, {1, 2, 1}, 2);

    return 0;
}
