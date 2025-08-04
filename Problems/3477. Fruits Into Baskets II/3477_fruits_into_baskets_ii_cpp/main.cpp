#include <iostream>
#include <vector>

using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    short n = fruits.size();
    short unplacedFruits = n;

    short iBaskets;
    for(short i = 0; i < n; ++i) {
        for(iBaskets = 0; iBaskets < n; ++iBaskets) {
            if(fruits[i] <= baskets[iBaskets]) {
                --unplacedFruits;
                baskets[iBaskets] = 0;
                break;
            }
        }
    }

    return unplacedFruits;
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
