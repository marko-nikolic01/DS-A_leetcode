#include <iostream>
#include <vector>

using namespace std;

int shortestSequence(vector<int>& rolls, int k) {
    vector<int> sides(k, 0);
    int sidesLeft = k;
    int rollCount = 1;

    for(int i = rolls.size() - 1; i > -1; --i) {
        if(sides[--rolls[i]] < rollCount) {
            sides[rolls[i]] = rollCount;

            if(--sidesLeft < 1) {
                sidesLeft = k;
                ++rollCount;
            }
        }
    }

    return rollCount;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> rolls, int k, int expected) {
    cout << "Rolls: ";
    printArray(rolls);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << shortestSequence(rolls, k) << endl;

    cout << endl;
}

int main() {
    test({4, 2, 1, 2, 3, 3, 2, 4, 1}, 4, 3);
    test({1, 1, 2, 2}, 2, 2);
    test({1, 1, 3, 2, 2, 2, 3, 3}, 4, 1);
    test({1, 2, 3, 4, 5, 6}, 6, 2);
    test({2, 2, 2, 2}, 3, 1);

    return 0;
}
