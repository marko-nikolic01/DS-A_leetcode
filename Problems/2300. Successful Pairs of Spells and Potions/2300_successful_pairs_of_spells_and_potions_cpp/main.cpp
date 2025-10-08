#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());

    int n = spells.size();
    vector<int> sortedSpells(n);

    int i;
    for(i = --n; i > -1; --i) {
        sortedSpells[i] = i;
    }

    sort(sortedSpells.begin(), sortedSpells.end(), [&](int& a, int& b) {
        return spells[a] < spells[b];
    });

    int spell;
    int left = 0;
    int right;
    int middle;

    i = potions.size();
    for(n; n > -1; --n) {
        spell = (success + spells[sortedSpells[n]] - 1) / spells[sortedSpells[n]];

        if(potions[left] >= spell) {
            spells[sortedSpells[n]] = i - left;
        } else {
            ++left;
            right = i - 1;

            while(left <= right) {
                middle = (left + right) >> 1;

                if(potions[middle] < spell) {
                    left = ++middle;
                } else if(middle > 0 && potions[middle - 1] >= spell) {
                    right = --middle;
                } else {
                    left = middle;
                    break;
                }
            }

            if(left >= i) {
                break;
            }

            spells[sortedSpells[n]] = i - left;
        }
    }

    while(n > -1) {
        spells[sortedSpells[n--]] = 0;
    }

    return spells;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> spells, vector<int> potions, long long success, vector<int> expected) {
    cout << "Spells: ";
    printArray(spells);

    cout << "Potions: ";
    printArray(potions);

    cout << "Success: " << success << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(successfulPairs(spells, potions, success));

    cout << endl;
}


int main() {
    test({5, 1, 3}, {1, 2, 3, 4, 5}, 7, {4, 0, 3});
    test({3, 1, 2}, {8, 5, 8}, 16, {2, 0, 2});
    test({10, 20}, {5, 5, 5}, 30, {3, 3});
    test({1, 2, 3}, {1, 1, 1}, 10, {0, 0, 0});
    test({2, 5, 8, 1}, {3, 1, 4, 2}, 10, {0, 3, 3, 0});

    return 0;
}
