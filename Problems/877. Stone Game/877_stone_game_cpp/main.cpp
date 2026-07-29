#include <iostream>
#include <vector>

using namespace std;

bool stoneGame(vector<int>& piles) {
    return true;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> piles, bool expected) {
    cout << "Piles: ";
    printArray(piles);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (stoneGame(piles) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({5, 3, 4, 5}, true);
    test({3, 7, 2, 3}, true);
    test({1, 2}, true);
    test({8, 15, 3, 7}, true);
    test({20, 8, 15, 3, 7, 1, 500, 1}, true);

    return 0;
}
