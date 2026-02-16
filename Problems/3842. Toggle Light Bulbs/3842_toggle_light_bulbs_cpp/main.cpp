#include <iostream>
#include <vector>

using namespace std;

vector<int> toggleLightBulbs(vector<int>& bulbs) {
    vector<bool> lightBulbs(101, false);

    short i = bulbs.size();
    while(--i > -1) {
        lightBulbs[bulbs[i]] = !lightBulbs[bulbs[i]];
    }

    bulbs.resize(0);

    for(i = 1; i < 101; ++i) {
        if(lightBulbs[i]) {
            bulbs.push_back(i);
        }
    }

    return bulbs;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> bulbs, vector<int> expected) {
    cout << "Light bulbs: ";
    printArray(bulbs);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(toggleLightBulbs(bulbs));

    cout << endl;
}

int main() {
    test({10, 30, 20, 10}, {20, 30});
    test({100, 100}, {});
    test({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    test({1, 1, 2, 2, 3, 3}, {});
    test({5, 7, 5, 7, 9}, {9});

    return 0;
}
