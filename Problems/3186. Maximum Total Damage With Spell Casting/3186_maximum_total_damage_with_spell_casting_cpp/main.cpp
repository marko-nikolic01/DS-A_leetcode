#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long maximumTotalDamage(vector<int>& power) {
    unordered_map<int, int> spells;
    vector<pair<int, int>> sortedSpells;

    int i;
    for (i = power.size() - 1; i > -1; --i) {
        ++spells[power[i]];
    }

    for(unordered_map<int, int>::iterator it = spells.begin(); it != spells.end(); ++it) {
        sortedSpells.push_back({it->first, it->second});
    }

    sort(sortedSpells.begin(), sortedSpells.end());

    int n = sortedSpells.size();
    vector<long> damages(n, 0);
    long damage = 0;
    long previousDamage = 0;

    int j = 0;
    int m;
    for(i = 0; i < n; ++i) {
        m = sortedSpells[i].first - 2;
        while(sortedSpells[j].first < m) {
            if(damages[j] > previousDamage) {
                previousDamage = damages[j];
            }

            ++j;
        }

        damages[i] = previousDamage + (long)sortedSpells[i].first * sortedSpells[i].second;

        if(damages[i] > damage) {
            damage = damages[i];
        }
    }

    return damage;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> power, long long expected) {
    cout << "Powers: ";
    printArray(power);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumTotalDamage(power) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 3, 4}, 6);
    test({7, 1, 6, 6}, 13);
    test({2, 2, 4, 6, 8}, 12);
    test({10, 10, 11, 12, 13, 15}, 35);
    test({1, 2, 3, 9, 10, 11, 20}, 34);

    return 0;
}
