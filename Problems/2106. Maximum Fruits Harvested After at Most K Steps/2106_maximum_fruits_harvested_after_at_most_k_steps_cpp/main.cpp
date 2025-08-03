#include <iostream>
#include <vector>

using namespace std;

int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    int fruit = 0;
    int currentFruits;

    int i;
    int j;
    int n = fruits.size();
    for(i = 0; i < n && fruits[i][0] <= startPos; ++i) {
        if(startPos - fruits[i][0] <= k) {
            currentFruits = 0;

            j = i;
            while(j < n && fruits[j][0] <= startPos) {
                currentFruits += fruits[j++][1];
            }

            while(i < n && fruits[i][0] <= startPos) {
                while(j < n && startPos - (fruits[i][0] << 1) + fruits[j][0] <= k) {
                    currentFruits += fruits[j++][1];
                }

                if(currentFruits > fruit) {
                    fruit = currentFruits;
                }

                currentFruits -= fruits[i++][1];
            }

            break;
        }
    }

    for(i = --n; i > -1 && fruits[i][0] >= startPos; --i) {
        if(fruits[i][0] - startPos <= k) {
            currentFruits = 0;

            j = i;
            while(j > -1 && fruits[j][0] >= startPos) {
                currentFruits += fruits[j--][1];
            }

            while(i > -1 && fruits[i][0] >= startPos) {
                while(j > -1 && (fruits[i][0] << 1) - startPos - fruits[j][0] <= k) {
                    currentFruits += fruits[j--][1];
                }

                if(currentFruits > fruit) {
                    fruit = currentFruits;
                }

                currentFruits -= fruits[i--][1];
            }

            break;
        }
    }

    return fruit;
}

void test(vector<vector<int>> fruits, int startPos, int k, int expected) {
    cout << "Fruits: ";
    for(vector<int> fruit : fruits) {
        cout << "[" << fruit[0] << ", " << fruit[1] << "] ";
    }
    cout << endl;

    cout << "Starting position: " << startPos << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxTotalFruits(fruits, startPos, k) << endl;

    cout << endl;
}

int main() {
    test({{2,8}, {6,3}, {8,6}}, 5, 4, 9);
    test({{0,9}, {4,1}, {5,7}, {6,2}, {7,4}, {10,9}}, 5, 4, 14);
    test({{0,3}, {6,4}, {8,5}}, 3, 2, 0);
    test({{200000, 10000}}, 200000, 200000, 10000);
    test({{0, 5}, {10, 10}, {20, 20}, {30, 30}, {40, 40}}, 10, 10, 30);

    return 0;
}
